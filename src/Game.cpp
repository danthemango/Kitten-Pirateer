//Edited by: Keenan Longair.
//Last update: 5:30PM March 23rd, 2016.
//Purpose: Contains the body of the game file prototyped in the Game.h file.
//Version: 1.7
//**************************************************************************************
//TODO: Enable a restart ability. 

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

//DrJ Class/object
//Below are the instance variables all using the m_ naming convention. I believe that
//there should be only one instance variable per instance. However class variables are
//singular to the class. Thus the class only has one instance of a class variable over
//all of the instances, while instance variables are one PER instance. So if we have
//three instances of Game, there will be three instances of each member variable.
//Class methods are messages to the class as a whole, while the instance methods are
//messages to objects.

//DrJ Abstraction
//Game creates the ability for the rest of the classes to have abstraction by defining
//the top level update and display methods. 
//Definition: Refers to the process of exposing only the relevant and essential data 
//to the users without showing unnecessary information. We model real world objects by 
//abstracting selected properties and actions of these objects, ignoring details.


//DrJ Polymorphism
//See the MiniGame class which contains not only inheritance and multi inheritance, but 
//it also contains the polymorphed version of the display and update methods.
//Note: These methods are not implemented within MiniGame but would be if the class was
//fully implemented.
//Definition: Allows you to use an entity in multiple forms.

//Main Variables:
bool Game::c_run = false;//Set the game to display the main menu. Once changed this
//moves the game along. This will also be used for the restart if possible.
bool Game::c_running = false;//Set the running state to false to start the game
//with the splashscreen displayed.
bool Game::c_gameOver = false;//Variable to tell if the game is over.
bool Game::c_winCondition = false;//Variable to tell if the game's win condition was true.
//The c_winCondition will be checked if the c_gameOver variable is set to true so that 
//the proper win/lose screen is displayed. 
bool* Game::c_keystates = new bool[256];
int Game::c_lastSong = 6000000;
bool Game::c_quit = false;//This variable will tell us if we need to bring up the quit confirmation
//window. If the variable is set to true, then the quit confirmation should be displayed. 
//If it is false, then we do not display the quit confirmation. Thus if it is true, then
//while paused the player may hit the enter key to quit, but if it is false enter will
//do nothing. Pressing escape again should swap the c_quit from true to false turning off
//the confirmation window.
int Game::c_windowID;//Define the window ID variable.


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
    Game::c_windowID = glutCreateWindow("Kitten Pirateer - Adventure of Zombie Island");

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
	miliseconds =  now - c_lastSong;
	
	if (miliseconds > 32600) {
		
		Jukebox::PlayBackground();
		c_lastSong = glutGet(GLUT_ELAPSED_TIME);
		
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

	if(!Game::c_running) {
		
	   	if(!Game::c_run) {

			//This will only call the main menu if the game has yet to be started.
			if (c_quit) {
				
				//If the user hits the escape key on the main menu, allow the quit
				//confirmation screen to be displayed instead of the main menu.
				return m_menu.quitConf();
				
			} else {
				
				//If the user has not pushed the escape key, simply display the 
				//main menu screen for the user.
				return m_menu.mainMenu();

			}
			
		} else if (Game::c_quit) { 
		
			//This should display the quitScreen when ever the c_quit variable is 
			//set to true. TODO TEST THIS CODE.
			return m_menu.quitConf();
		
		} else {
			
			//This will call the splash screen when ever the user pauses the game
			//using the space bar.
			return m_menu.pauseScreen();

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
//TODO finalize and debug this method.
{

	if (DEBUG) { 
		
		cout << "Debug-Game.cpp: The game is attempting to restart.\n";
		
	}
	
	//First reset all the variables.
	Game::c_running = false;
	Game::c_run = false;
	Game::c_quit = false;
	
	//Next destroy the window.
	glutDestroyWindow(Game::c_windowID);
	
	//Now delete all of the variables created in the init.
	
	//Finally call init
	Game::getInstance().init();

}
/****End of Main Work Functions*********************************************************/

/****Key Functions**********************************************************************/
void Game::key(unsigned char key, int x, int y)
//This function handles key input from the user for non-movement controls.
//TODO Determine if the x and y variables are needed for keyinput or not.
{
	
	c_keystates[key] = true;
	
    switch (key){
		
        case ' ' :
		
			//If the space bar is hit, the game first checks to see if the c_run
			//has changed from false yet. 
			if (Game::c_run == false) {
				
				//If c_run is still false, then we would start the game and set c_run
				//and c_running to true and allow the game to run.
				Game::c_run = !Game::c_run;
				Game::c_running = !Game::c_running;
				if (Game::c_quit) Game::c_quit = false;//If we had set the c_quit value to true, but then
				//started the game again, we make sure to reset c_quit to false so that it 
				//will not allow the user to hit space followed by enter to quit by mistake. 
				Jukebox::PlayBackground();//This should play the background song.
                Game::c_lastSong = glutGet(GLUT_ELAPSED_TIME);//This logs when the sound was started.
				
            } else {
				
				//If c_run has changed to true, then the game has been started and 
				//we simply deal with the c_running variable to decide upon displaying
				//the pause screen or allowing game play.
				Game::c_running = !Game::c_running;
				if (Game::c_quit) Game::c_quit = false;//If we had set the c_quit value to true, but then
				//started the game again, we make sure to reset c_quit to false so that it
				//will not allow the user to hit space followed by enter to quit by mistake.
				
            }
			
			break;
			
        case 'k':
			
			//If k is hit, check the status of the game and either allow an item use or do not allow item
			//use within the game. 
			if (Game::c_running) {
				
				//If the game is running, allow item use.
				ItemHandler::getInstance().iUse();
				//k will handle item use.
			
			}
				
			//Otherwise do nothing.
			break;
				
		case 'i':
			
			//If i is hit, check the status of the game and either allow an item swap or do not allow item
			//swap within the game. 
			if (Game::c_running) {
				
				//If the game is running, allow item swapping.
				//i will handle item swap.
				ItemHandler::getInstance().iSwitch();
			
			}

			//Otherwise do nothing.
			break;
				
		case 'j':
		
			//If j is hit, check the status of the game and either allow an attack or do not allow an
			//attack within the game. 
			if (Game::c_running) {	

				//If the game is running allow attacks.
				//j uses the currently equipted weapon to attack or do something else.
				Player::getInstance().attack();
			
			}
			
			//Otherwise do nothing.
			break;
		
		case 'u':
		
			//If u is hit, check the status of the game and either allow an weapon swap or do not allow
			//weapon swapping within the game.
			if (Game::c_running) {	

				//If the game is running allow weapon swapping.
				//u handles weapon swap.
				ItemHandler::getInstance().wSwitch();
			
			}

			//Otherwise do nothing.
			break;
		
		case 27:
		
		//27 refers to the escape key Ascii code. When the escape key is hit the game 
		//will check the c_quit variables state. If that state is false switch it to 
		//true, it if is true, switch it to false. The reason the code uses slightly
		//different style compared to other areas is due to the fact that for some 
		//reason the code using a normal expression of c_quit = !c_quit; seemed to
		//cause no change at all. 
		
			if (c_quit == false) {
				
				c_quit = true;
				
				if (DEBUG) {
					
					cout << "Debug-Game.cpp: c_quit set to true\n";
					
				}
				
			} else if (c_quit == true) {
				
				c_quit = false;
				
				if (DEBUG) {
					
					cout << "Debug-Game.cpp: c_quit set to false\n";
					
				}
			
			}
			
			break;

		case 13://13 is the enter key. This states that if the enter key is
		//pressed while the game is paused do the following.
			 
			if ((!Game::c_running) && (Game::c_quit)) {
				
				//If the game is paused allow the user to hit escape followed by enter
				//to quit the game.
				glutDestroyWindow(Game::c_windowID);//c_windowID should contain the windows
				//ID number so that we can destroy it.
				exit(0);//Exits the program.
			
			}
				
			//Otherwise do nothing.
			break;
		
		/*
		//TODO define the restart key and work out how to re-initialize all of the classes.
		case 'b'://b is only a temporary key to be used. When this key is pressed while the
		//game is paused and the quit confirmation screen is being displayed, allow call the
		//restart function.

			if ((!Game::c_running) && (c_quit)) {
				
				Game::getInstance().restartGame();
			
			}
			break;
		*/
	
    }

    //glutPostRedisplay();
	
}

void Game::keyOperations()
//keyOpertations handles smooth movement from the control input.
{
	
	if (Game::c_running) {
		
		//If the game is running, allow movement keys to be used.
		if (c_keystates['a']) {
	   
			Player::getInstance().left();
			Player::getInstance().update();
	  
		}
   
		if (c_keystates['w']) {
	   
			Player::getInstance().up();
			Player::getInstance().update();
	  
		}
   
		if (c_keystates['d']) {
	   
			Player::getInstance().right();
			Player::getInstance().update();
	  
		}
   
		if (c_keystates['s']) {
	   
			Player::getInstance().down();
			Player::getInstance().update();
	  
		}
		
	} 
	
	//Otherwise do nothing.
		
}

void Game::keyUp(unsigned char key, int x, int y)
//Sets the proper key state to be false.
{
	
   c_keystates[key] = false;

}
/****End of Key Functions**************************************************************/



/****Main Function*********************************************************************/
int main(int argc, char **argv)
//TODO check to see if we need int argc and char **argv since the game does not need any
//extra parameter input on start up.
{
	
	//Start by trying to initialize Jukebox and then init glut and getInstance to that
	//the game will start (within getInstance).
    if(!Jukebox::init()) {
		
		exit;
	
	}
	
	glutInit(&argc, argv);//TODO determine if this line can be removed or if it is needed
	//for the glut library initialization.
    Game::getInstance().init();//Starts up the game.
    SDL_CloseAudio();//Once the game is ended, close the audio.
	
	if(DEBUG) {
		
		cout << "Debug-Game.cpp-523: Shutting Down...\n";
	
	}
	
	return 0;//Ensure the program exits.
	
}
/****End Main Function*****************************************************************/
