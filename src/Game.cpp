//Edited by: Keenan Longair.
//Last update: 12:30PM March 17th, 2016.
//Purpose: Contains the body of the game file prototyped in the Game.h file.
//Version: 1.6
//**************************************************************************************
//TODO: Add a restart function ability to the code so we can restart the game from within.
//Not sure how to add this ability yet but I believe it would have to be part of the 
//win/lose code. So far only a win/lose screen from menu has been coded. 

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
#include "../hdr/ItemHandler.h"//Dependancy for the item handler.
#include "../hdr/HUDHandler.h" //HUD Dependency.
#include "../hdr/ZombieHandler.h"//Zombie Handler dependancy.

//Main Variables: TODO Try to move these into the init or the constructor instead of 
//defining them here. 
bool Game::m_run = false;//Set the game to display the main menu. Once changed this
//moves the game along. This will also be used for the restart if possible.
bool Game::m_running = false;//Set the running state to false to start the game
//with the splashscreen displayed.
bool Game::m_gameOver = false;//Variable to tell if the game is over.
bool Game::m_winCondition = false;//Variable to tell if the game's win condition was true.
//The m_winCondition will be checked if the m_gameOver variable is set to true so that 
//the proper win/lose screen is displayed. 
bool* Game::keystates = new bool[256];
int Game::m_lastSong = 6000000;
bool Game::m_quit = false;//This variable will tell us if we need to bring up the quit confirmation
//window. If the variable is set to true, then the quit confirmation should be displayed. 
//If it is false, then we do not display the quit confirmation. Thus if it is true, then
//while paused the player may hit the enter key to quit, but if it is false enter will
//do nothing. Pressing escape again should swap the m_quit from true to false turning off
//the confirmation window.
int Game::m_windowID;//Define the window ID variable.

//ORALEXAM Lines: Creator justification line 56. Info on line 60.

/****Main Work Functions***************************************************************/
void Game::init()
//Initialization function.
{
	
	//ORALEXAM/Creator: The creator pattern is in use because in Game's init It must
	//create the other classes within the game. Either indirectly or directly the other
	//classes are created. 
	
	//Creator information:
	//Problem: Who should be responsible for creating a new instance of some class?
	//Solution: Assign class B the responcibility to create an instance of class A if one 
	//of these is true (& the more the better)... B "Contains" or compositely aggregates A.
	//B records A. B closely uses A. Or B has initializing data for A.
	//Game closely uses the Menu class and is an expert on creating the other classes. 
	//The "Creator" principle is meant to help us achieve low coupling, increased clarity, 
	//increased encapsulation, and inscreased reusability. 
	//Discussion: Intent is to support low coupling, initializing data is sometimes as
	//of a good Creator. Some object cosntructors have complex signatures, which objects 
	//have the information needed to supply parameter values for such constructors?
	//Contraindications: Creation can be complex, may wish to use Factory Method or Abstract
	//Factory instead in these cases.
	//Benefits: Low coupling has already been mentioned, why is this good?
		
	//TODO remove the next 2 lines if the random number function is not needed.
    //Set the seed for the random variable generator just in case we need it.
    //srandom(time(NULL));

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);//Use double buffering for smoother images
    glutInitWindowSize(m_width+HUD_WIDTH, m_height);
    glutInitWindowPosition(0, 0);
    Game::m_windowID = glutCreateWindow("Kitten Pirateer - Adventure of Zombie Island");

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
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
    //gluOrtho2D(0, m_width+m_margine, 0, m_height+m_margine);
	
    glOrtho(0, m_width+HUD_WIDTH, 0, m_height, 0, 1000);

	//Set up the callbacks that will be taken care of in step 1:
    glutKeyboardFunc(Game::key);//Keyboard input
    glutDisplayFunc(Game::run);//Display frames
	glutKeyboardUpFunc(Game::keyUp);//Keyboard Movement input.
    //glutIdleFunc(Game::run);//Wait time between frames.
	
	//Load the default texture into the member variable:
	Game::m_backgroundTexture = MapHandler::getInstance().getTile(START_TILE);
	
	//Place init here for the main GameObject (probably the PC character).
	Player::getInstance().init();
	ZombieHandler::getInstance();
	m_menu.init();
	
	//Run the main glut loop for processing the game. 
    glutMainLoop(); //glutMainLoop enters the GLUT event processing loop. 
                    //This routine should be called at most once in a GLUT program. 
                    //Once called, this routine will never return. 
                    //It will call as necessary any callbacks that have been registered.

	return;//Exit the init once the glutMainLoop() is exited.
	
}

void Game::update()
//Function handling the update of the game.
{
	
	int now;
	int miliseconds;
	now = glutGet(GLUT_ELAPSED_TIME);
	miliseconds =  now - m_lastSong;
	
	if (miliseconds > 32600) {
		
		Jukebox::PlayBackground();
		m_lastSong = glutGet(GLUT_ELAPSED_TIME);
		
	}
	
	Game::getInstance().keyOperations();
	
	//Clear color and depth buffers:
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

	//Clear the screen:
	glClearColor(1.0, 1.0, 1.0, 1.0); // Set the clear color to white
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Draw the background:
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_backgroundTexture);
	ImageLoader::rectangle(0,0, m_width, m_height);
	glDisable(GL_TEXTURE_2D);
	glFlush();
   
	//Update the HUD:
	HUDHandler::getInstance().displayHUD(); 

	if(!Game::m_running) {
		
	   	if(!Game::m_run) {

			//This should only call the mainMenu once at the start of the game.
			return m_menu.mainMenu();

			
		} else if (Game::m_quit) { 
		
			//This should display the quitScreen when ever the m_quit variable is 
			//set to true. TODO TEST THIS CODE.
			return m_menu.quitScreen();
		
		} else {
			
			//This will call the splash screen when ever the user pauses the game
			//using the space bar.
			return m_menu.splashScreen();

		}
	 
	}

	//Display and update the zombies:
	ZombieHandler::getInstance().display();
	ZombieHandler::getInstance().update();
	//Update the items:
	ItemHandler::getInstance().update();
	//Player display should be one of the very last, if not last.
	Player::getInstance().display();
	
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

//Called by Game::idle this function sends a signal to update the screen
void Game::timer(int id)
{
	
	if(id == 513) {
		
		//Redisplay frame
		glutPostRedisplay();
		
	}
   
}

//This function handles the delay between the update signals for the screen.
void Game::idle() 
{
	
	glutTimerFunc(Game::m_interval, // in this many miliseconds
		Game::timer,      // call the funtion timer
		513               // with this parameter
	);
   
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void Game::reshape(GLsizei newwidth, GLsizei newheight) 
{  

	//Set the viewport to cover the new window
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
	
	Game::m_backgroundTexture = x;
	ZombieHandler::getInstance().updateTile(x);
	
}

void Game::restartGame()
//This function handles restarting the game when needed.
//TODO figure out how to enable the restart of the game. This may require the
//deconstructor to be called and then the constructor to restart but that does
//not appear to be appropriate. From the research I have done, it appears that each
//class needs to have a reset ability to be called to reset all of the positions
//and variables they use to their initial state.
{

}
/****End of Main Work Functions*********************************************************/

/****Key Functions**********************************************************************/
void Game::key(unsigned char key, int x, int y)
//This function handles key input from the user for non-movement controls.

//TODO Determine if the x and y variables are needed for keyinput or not.
{
	
	keystates[key] = true;
	
    switch (key){
		
        case ' ' :
		
			//If the space bar is hit, the game first checks to see if the m_run
			//has changed from false yet. 
			if (Game::m_run == false) {
				
				//If m_run is still false, then we would start the game and set m_run
				//and m_running to true and allow the game to run.
				Game::m_run = !Game::m_run;
				Game::m_running = !Game::m_running;
				if (Game::m_quit) Game::m_quit = false;//If we had set the m_quit value to true, but then
				//started the game again, we make sure to reset m_quit to false so that it 
				//will not allow the user to hit space followed by enter to quit by mistake. 
				Jukebox::PlayBackground();//This should play the background song.
                Game::m_lastSong = glutGet(GLUT_ELAPSED_TIME);//This logs when the sound was started.
				
            } else {
				
				//If m_run has changed to true, then the game has been started and 
				//we simply deal with the m_running variable to decide upon displaying
				//the pause screen or allowing game play.
				Game::m_running = !Game::m_running;
				if (Game::m_quit) Game::m_quit = false;//If we had set the m_quit value to true, but then
				//started the game again, we make sure to reset m_quit to false so that it
				//will not allow the user to hit space followed by enter to quit by mistake.
				
            }
			
			break;
			
		//The following controls are not finite. They may be changed later on however 
		//this will allow us to test them ass we need them.
        case 'k':
			
			if (Game::m_running) {
				
				//If the game is running, allow item use.
				ItemHandler::getInstance().iUse();
				//k will handle item use.
				break;
			
			} else {
				
				//Otherwise do nothing.
				break;
				
			}
			
		case 'i':
		
			if (Game::m_running) {
				
				//If the game is running, allow item swapping.
				//i will handle item swap.
				ItemHandler::getInstance().iSwitch();
				break;
			
			} else {

				//Otherwise do nothing.
				break;
				
			}
				
		case 'j':
		
			if (Game::m_running) {	

				//If the game is running allow attacks.
				//j uses the currently equipted weapon to attack or do something else.
				Player::getInstance().attack();
				break;
			
			} else {

				//Otherwise do nothing.
				break;
				
			}
			
		case 'u':
		
			if (Game::m_running) {	

				//If the game is running allow weapon swapping.
				//u handles weapon swap.
				ItemHandler::getInstance().wSwitch();
				break;
			
			} else {

				//Otherwise do nothing.
				break;
				
			}
		
		//TODO Add a confirmation for quitting the game. That way it is not possible
		//to quit by mistake.
/*		
		case 27:
		
		//27 refers to the escape key Ascii code. When the escape key is hit the game 
		//will check the m_quit variables state. If that state is false switch it to 
		//true, it if is true, switch it to false. The reason the code uses slightly
		//different style compared to other areas is due to the fact that for some 
		//reason the code using a normal expression of m_quit = !m_quit; seemed to
		//cause no change at all. 
		
			if (m_quit == false) {
				
				m_quit = true;
				if (DEBUG)) {
					
					cout << "Debug-Game.cpp: m_quit set to true\n";
					
				}
				
			} else if (m_quit == true) {
				
				m_quit = false;
				if (DEBUG) {
					
					cout << "Debug-Game.cpp: m_quit set to false\n";
					
				}
				
			}

		case 13://13 is the enter key. This states that if the enter key is
		//pressed while the game is paused do the following.
			 
			if ((!Game::m_running) && (Game::m_quit)) {
				
				//If the game is paused allow the user to hit escape followed by enter
				//to quit the game.
				glutDestroyWindow(Game::m_windowID);//m_windowID should contain the windows
				//ID number so that we can destroy it.
				exit(0);//Exits the program.
				break;
			
			} else {
				
				//Otherwise do nothing.
				break;
			
			}
*/		
    }
	
    //glutPostRedisplay();
	
}

void Game::keyOperations()
//keyOpertations handles smooth movement from the control input.
{
	
	if (Game::m_running) {
		
		//If the game is running, allow movement keys to be used. '
		if (keystates['a']) {
	   
			Player::getInstance().left();
			Player::getInstance().update();
			//Player::getInstance().m_left = true;
	  
		} else {
	   
			//Player::getInstance().m_left = false;
	
		}
   
		if (keystates['w']) {
	   
			Player::getInstance().up();
			Player::getInstance().update();
			//Player::getInstance().m_up = true;
	  
		} else {
	   
			//Player::getInstance().m_up = false;
	
		}
   
		if (keystates['d']) {
	   
			Player::getInstance().right();
			Player::getInstance().update();
			//Player::getInstance().m_right = true;
	  
		} else {
	   
			//Player::getInstance().m_right = false;
	
		}
   
		if (keystates['s']) {
	   
			Player::getInstance().down();
			Player::getInstance().update();
			//Player::getInstance().m_down = true;
	  
		} else {
	   
			//Player::getInstance().m_down = false;
	
		}

	} else if (!Game::m_running) {
		
	//27 refers to the escape key Ascii code. When the escape key is hit the game 
	//will check the m_quit variables state. If that state is false switch it to 
	//true, it if is true, switch it to false. The reason the code uses slightly
	//different style compared to other areas is due to the fact that for some 
	//reason the code using a normal expression of m_quit = !m_quit; seemed to
	//cause no change at all. 
		
		if(keystates[27]) {
			
			if (Game::m_quit == false) {
				
				Game::m_quit = true;
				if (DEBUG) {
					
					cout << "Debug-Game.cpp: m_quit set to true\n";
					
				}
			
			} else if (Game::m_quit == true) {
				
				Game::m_quit = false;
				if (DEBUG) {
					
					cout << "Debug-Game.cpp: m_quit set to false\n";
					
				}
				
			}
			
		}
		
		if(keystates[13]) {//13 is the enter key. This states that if the enter key is
		//pressed while the game is paused do the following.
			
			if (Game::m_quit == true) {
				
				//If the game is paused, and the m_quit is set to true, allow enter
				//to exit the game. 
				glutDestroyWindow(Game::m_windowID);
				//glutLeaveMainLoop();//This needs to be tested to see if the glutMainLoop()
				//will exit allowing the Game.cpp main funciton to return and close the audio.
				exit(0);
				
			}
			
		}
	}
	//Otherwise do nothing.
		
}

void Game::keyUp(unsigned char key, int x, int y)
//Sets the proper key state to be false.
{
	
   keystates[key] = false;

}
/****End of Key Functions**************************************************************/


/****Other Functions*******************************************************************/
//Possibly helpful functions.
//These functions are here to provide their possible use for the project.
//Anything not used by the end will be removed.
//TODO remove any functions in this location that are not used.

/*
//Function to return a random number if needed. May be removed if 
//not used before final presentation.
GLfloat Game::frand()
//Random number generating function.
{
	
    return random()/(GLfloat)RAND_MAX;

}
*/
/****End of Other Functions************************************************************/


/****Main Function*********************************************************************/
int main(int argc, char **argv) 
{
	
	//Start by trying to initialize Jukebox and then init glut and getInstance to that
	//the game will start (within getInstance).
    if(!Jukebox::init())
		exit;
    glutInit(&argc, argv);
    Game::getInstance().init();
	//Once the game is ended, close the audio.
    SDL_CloseAudio();
	if(DEBUG) {
		cout << "Debug-Game.cpp-523: Shutting Down...\n";
	}
	return 0;//Ensure the program exits.
	
}
/****End Main Function*****************************************************************/
