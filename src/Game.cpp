//Edited by: Keenan Longair.
//Last update: 3:00PM February 26th, 2016.
//Purpose: Contains the body of the game file prototyped in the Game.h file.
//Version: 1.1

//Required Libraries:
#include <cstdio>
#include <stdlib.h>
#include <GL/glut.h>/*glut.h includes gl.h and glu.h*/
#include <math.h>
#include <time.h>
#include <GL/freeglut.h>

//Required Files:
#include "../hdr/Game.h"//Prototype of this file.
#include "../hdr/Jukebox.h"//Dependancy for Sound.
#include "../hdr/Obstacle.h"//Dependancy for Obstacles.
#include "../hdr/ImageLoader.h"//Dependancy for Images.
#include "../hdr/MapHandler.h"//Dependancy for the Map.
#include "../hdr/Player.h"//Dependancy for the Player.
#include "../hdr/ItemHandler.h"//


//Main Variables:
bool Game::c_run = false;//Set the game to display the main menu. Once changed this
//moves the game along.
bool Game::c_running = false;//Set the running state to false to start the game
//with the splashscreen displayed.

/****Main Work Functions***************************************************************/
void Game::init()
//Initialization function.
{
	
    //Set the seed for the random variable generator just in case we need it.
    //srandom(time(NULL));

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);//Use double buffering for smoother images
    glutInitWindowSize(m_width, m_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Kitty Piratier - Adventure of Zombie Island");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	//Alpha layer code:
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUC_SRC_ALPHA);
	
    //gluOrtho2D(0, m_width+m_margine, 0, m_height+m_margine);
	
    glOrtho(0, m_width+m_margine, 0, m_height+m_margine, 0, 1000);

	//In event-driven programming, like you have in interactive OpenGL 
	//applications, the main application loop generally does three things:
	//  1. check the current event queues, and process any events (e.g., 
	//     mouse movement, key presses, etc.) that have occurred since the last check
	//  2. update the application state - things like player and object positions, 
	//     game physics, etc. - in preparation of the next rendering frame
	//  3. render the current frame.
	// GLUT does these steps implicitly in its glutMainLoop()

	//Set up the callbacks that will be taken care of in step 1:
    glutKeyboardFunc(Game::key);//Keyboard input
    glutDisplayFunc(Game::run);//Display frames
	glutKeyboardUpFunc(Game::keyUp);//Keyboard Movement input.
    //glutIdleFunc(Game::run);    // Wait time between frames.
	
	//Create the MapHandler so we can call the map.
	m_MapHandler = new MapHandler;//Creates the MapHandler using the new function.
	
	//Load the default texture into the ImageLoader. 
	//m_backgroundTexture = ImageLoader::LoadTexture( "./imgs/south.bmp" );
	m_backgroundTexture = m_MapHandler.getTile();
	
	//Place init here for the main GameObject (probably the PC character).
	m_myPlayer.init();


    glutMainLoop(); // glutMainLoop enters the GLUT event processing loop. 
                    //This routine should be called at most once in a GLUT program. 
                    //Once called, this routine will never return. 
                    //It will call as necessary any callbacks that have been registered.

}

void Game::update()
//Function handling the update of the game.
{
	
	Game::getInstance().keyOperations();
	
	//Clear color and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

	//Clear the screen
	glClearColor(1.0, 1.0, 1.0, 0.0); // Set the clear color to white
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Draw the background
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_backgroundTexture);
	ImageLoader::rectangle(0,0, m_width, m_height);
	glDisable(GL_TEXTURE_2D);
	glFlush();

	if(!Game::c_running) {
		
	   	if(!Game::c_run) {
	
			//This should only call the mainMenu once at the start of the game.
			return Menu::mainMenu();
		
		} else {
			
			//This will call the splash screen when ever the user pauses the game
			//using the space bar.
			return Menu::splashScreen();
			
		}
	 
	}

	//OBJECT UPDATE CALLS HERE:
	//MapHandler::
	//Item update must happen before the player display.
	//ItemHandler::getInstance().update();
	//Player display should be one of the very last, if not last.
	m_myPlayer.display();
	
}

void Game::run() 
{

    Game::getInstance().update();   
    //Flush the graphics pipele and display the objects we have specified
    //Since we are using double buffering this means we swap the buffer be just drew
    //on to the screen.
    glutSwapBuffers();
    Game::idle();
	
}

// Called by Game::idle this function sends a signal to update the screen
void Game::timer(int id)
{
	
   if(id == 513) {
      // Redisplay frame
      glutPostRedisplay();
   }
   
}

//This function handles the delay between the update signals for the screen.
void Game::idle() 
{
	
   glutTimerFunc(Game::c_interval, // in this many miliseconds
     Game::timer,      // call the funtion timer
     513               // with this parameter
   );
   
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void Game::reshape(GLsizei newwidth, GLsizei newheight) 
{  
	// Set the viewport to cover the new window
    glViewport(0, 0, m_width=newwidth, m_height=newheight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, m_width, m_height, 0.0, 0.0, 100.0);
    glMatrixMode(GL_MODELVIEW); 
    glutPostRedisplay();
}

void Game::updateTile(GLuint x)
//Function which allows the background texture variable to be altered when required.
{
	
	m_backgroundTexture = x;
	
}
/****End of Main Work Functions*********************************************************/


/****Key Functions**********************************************************************/
void Game::key(unsigned char key, int x, int y)
//This function handles key input from the user for non-movement controls.
{
	
    switch (key){
		
        case ' ' :
		
			//If the space bar is hit, the game first checks to see if the c_run
			//has changed from false yet. 
			if (Game::c_run == false) {
				
				//If c_run is still false, then we would start the game and set c_run
				//and c_running to true and allow the game to run.
				Game::c_run = !Game::c_run;
				Game::c_running = !Game::c_running;
				
            } else {
				//If c_run has changed to true, then the game has been started and 
				//we simply deal with the c_running variable to decide upon displaying
				//the pause screen or allowing game play.
				Game::c_running = !Game::c_running;
				
            }
			break;
			
        case 'e':
			//e could handle the interactions.
			break;
			
		case 'q':
			//q could handle the item use.
			break;
			
		case 'h':
			//h could handle the attack command.
			break;
			
    }
    //glutPostRedisplay();
	
}

void Game::keyOperations()
//keyOpertations handles smooth movement from the control input.
{
	
   if(keystates['a']){
	   
      Game::getInstance().m_myPlayer.left();
      Game::getInstance().m_myPlayer.c_left = true;
	  
   } else {
	   
   	Game::getInstance().m_myPlayer.c_left = false;
	
   }
   
   if (keystates['w']) {
	   
      Game::getInstance().m_myPlayer.up();
      Game::getInstance().m_myPlayer.c_up = true;
	  
   } else {
	   
   	Game::getInstance().m_myPlayer.c_up = false;
	
   }
   
   if (keystates['d']) {
	   
      Game::getInstance().m_myPlayer.right();
      Game::getInstance().m_myPlayer.c_right = true;
	  
   } else {
	   
   	Game::getInstance().m_myPlayer.c_right = false;
	
   }
   
   if (keystates['s']) {
	   
      Game::getInstance().m_myPlayer.down();
      Game::getInstance().m_myPlayer.c_down = true;
	  
   } else {
	   
   	Game::getInstance().m_myPlayer.c_down = false;
	
   }

}

void Game::keyUp(unsigned char key, int x, int y)
//Sets the proper key to be false.
{
	
   keystates[key] = false;

}
/****End of Key Functions**************************************************************/


/****Other Functions*******************************************************************/
//Possibly helpful functions.
//These functions are here to provide their possible use for the project.
//Anything not used by the end will be removed.
//int Game::getArrayPos()
//{
  //return m_arraypos;
//}

//void Game::setArrayPos(int pos)
//{
   //m_arraypos = pos;
//}

//void Game::changeScreen(int dir)
//{

	//const char* tiles[5] =  {"","./imgs/north.bmp","./imgs/east.bmp","./imgs/south.bmp","./imgs/west.bmp"};
	//m_backgroundTexture= ImageLoader::LoadTexture(tiles[dir]);
	
//}

/*Get Width and Get Height are not required now that the size of the screen will be
located within the config.h*/
int Game::getWidth() 
{
	
	return m_width;
	
}

int Game::getHeight() 
{
	
	return m_height;
	
}

//Function to return a random number if needed. May be removed if 
//not used before final presentation.
//GLfloat Game::frand()
//Random number generating function.
//{
	
    //return random()/(GLfloat)RAND_MAX;

//}
/****End of Other Functions************************************************************/


/****Main Function*********************************************************************/
int main(int argc, char **argv) 
{
	
    if(!Jukebox::init())
       exit;
    glutInit(&argc, argv);
    Game::getInstance().init();
    SDL_CloseAudio();
	
}
/****End Main Function*****************************************************************/