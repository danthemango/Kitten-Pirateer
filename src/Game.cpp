//Edited by: Keenan Longair.
//Original author: Julie Beeston.
//Last update: 3:15PM March 29th, 2016.
//Purpose: Contains the implememtation of the Game class prototyped in the Game.h file.
//Version: 2.1
//**************************************************************************************
//TODO: Test the new flow of the game including the reorganized dialog screen calls
//and the new screens themselves.

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

//Main Variables:
bool Game::c_run = false;//Set the game to display the main menu. Once changed this
//moves the game along. This will also be used for the restart if possible.
bool Game::c_running = false;//Set the running state to false to start the game
//with the splashscreen displayed.
bool Game::c_gameOver = false;//Variable to tell if the player has lost.
bool Game::c_winCondition = false;//Variable to tell if the player has won.
bool* Game::c_keystates = new bool[256];//Array Storage for keystates.
int Game::c_lastSong = 6000000;//Set the counter variable to default.
bool Game::c_escape = false;//Disable the escape dialog by default.
bool Game::c_restart = false;//Disable the restart dialog by default.
bool Game::c_quit = false;//Disable the quit dialog by default.
int Game::c_windowID;//Set up the variable.

/****Main Work Functions***************************************************************/
void Game::init()
//Initialization function.
{
	
	if (DEBUG) {
		
		cout << "Debug-Game.cpp: Initializing Game instance...\n";
		cout << "Debug-Game.cpp: Please wait...\n";
		
	}

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);//Use double buffering for smoother images
    glutInitWindowSize(m_width+HUD_WIDTH, m_height);
    glutInitWindowPosition(0, 0);
    Game::c_windowID = glutCreateWindow("Kitten Piratier - Adventure of Zombie Island");
    
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
	
	//Enable the glutLeaveMain() function to return to the calling function when it
	//causes the exit of the glutMainLoop() called next.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	
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
	
	//First check the elapsed time to see if we need to restart the background
	//theme song.
	int now;
	int miliseconds;
	now = glutGet(GLUT_ELAPSED_TIME);
	miliseconds =  now - c_lastSong;
	
	if (miliseconds > 32600) {
		
		Jukebox::PlayBackground();
		c_lastSong = glutGet(GLUT_ELAPSED_TIME);
		
	}
	
	//Now check the key input.
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
	//We update the hud first because we require it to remain as up to date as
	//possible even if a menu is displayed.

	//Check the game status and respond appropriatly.
	//If the players health reaches 0:
	if(Player::getInstance().getHealth() <= 0) {
		
		Game::getInstance().setLose();
	}
	
	//If the game is paused:
	if((!Game::c_running) && (!Game::c_gameOver) && (!Game::c_winCondition)) {
		//If the game is paused and c_running is false, the we check to see what
		//stat the game was left in.
		
	   	if(!Game::c_run) {
			//If the c_run variable is false, then the game has not started yet.
			//Thus we need to check to see if the escape menu has been called.
		
			if (Game::c_escape) {
				//If the escape menu has been called, we check to see if the user
				//has entered the command to quit.
				
				if (Game::c_quit) {
					//If the quit command was entered we displayed the 
					//confirmation screen.
					
					return m_menu.quitConf();
			
				} else {
					//Otherwise the user has simply hit the escape key to bring
					//up the quit option screen while the game has not 
					//started yet.
					
					return m_menu.escapeScreen();
				
				}

			} else {
				
				//Otherwise the user has not started the game and not chosen to
				//bring up the quit/restart screen.
				return m_menu.mainMenu();

			}
			
		} else {
			//Otherwise the game is paused so we need to check the state of the
			//game.
			
			if (Game::c_escape) {
				//If the escape menu has been called, we check to see if the user
				//has entered the command to quit or restart.
				
				if (Game:: c_restart) {
					//If the restart command was entered we display the 
					//confirmation screen.
					
					return m_menu.restartConf();
		
				} else if (Game::c_quit) { 
					//If the quit command was entered we displayed the 
					//confirmation screen.
					
					return m_menu.quitConf();
		
				} else {
					//Otherwise the game is simply paused and the escape key was
					//entered. Thus we display the escape menu.
					
					return m_menu.escapeScreen();
		
				}
			
			} else {
				//Otherwise the game was simply paused and the escape key has 
				//not been pressed yet.
			
				return m_menu.pauseScreen();

			}
				
		}
	 
	}
		
	if ((!Game::c_gameOver) && (!Game::c_winCondition)) {
		
		//Display and update the zombies:
		ZombieHandler::getInstance().display();
		ZombieHandler::getInstance().update();
		//Update the items:
		ItemHandler::getInstance().update();
		//Player display should be one of the very last, if not last.
		Player::getInstance().display();
		
	}
	
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

//Use of this method indicates that the win condition has been achived by the player.
void Game::setWin()
//Simple function to end the game on a win.
{
	
	Game::c_winCondition = true;//Game is now over, set to true.
	Game::c_quit = true;//Quit will occur soon, set to true.
	Game::c_escape = true;//Escape needs to be set to true.
	Game::c_running = false;//Game is no longer running, set to false.
	return m_menu.winScreen();//Bring up the win screen.
	//Once the win screen is displayed, only enter is allowed to function which allows
	//the plahyer to quit the game. In the future if possible the restart function 
	//will be allowed in this screen aswell.
	
	
}

//Use of this method indicates that the player has lost the game.
void Game::setLose()
//Simple function to end the game on a loss.
{
	
	Game::c_gameOver = true;//Game is now over, set to true.
	Game::c_quit = true;//Quit will occur soon, set to true.
	Game::c_escape = true;//Escape needs to be set to true.
	Game::c_running = false;//Game is no longer running, set to false.
	return m_menu.loseScreen();//Bring up the lose screen.
	//Once the lose screen is displayed, only enter is allowed to function which
	//allows the player to quit the game. In the future if possible the restart function
	//will be allowed in this screen aswell.
	
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
			if ((!Game::c_run) && (!c_escape)) {
				
				//If c_run is still false, then we would start the game and set c_run
				//and c_running to true and allow the game to run.
				Game::c_run = !Game::c_run;
				Game::c_running = !Game::c_running;
				
				//The next two if statements are now handled by the respective keys for quitting
				//or restarting (if enabled).
				//if (Game::c_quit) Game::c_quit = false;//Reset c_quit to prevent accidental
				//exiting of the game.
				//if (Game::c_restart) Game::c_restart = false;//Reset the c_restart to prevent
				//accidental restarting of the game.
				
				Jukebox::PlayBackground();//This should play the background song.
                Game::c_lastSong = glutGet(GLUT_ELAPSED_TIME);//This logs when the sound was started.
				
            } else if (!c_escape) {
				
				//If c_run has changed to true, then the game has been started and 
				//we simply deal with the c_running variable to decide upon displaying
				//the pause screen or allowing game play.
				Game::c_running = !Game::c_running;
				
				//The next two if statements are now handled by the respective keys for quitting
				//or restarting (if enabled).
				//if (Game::c_quit) Game::c_quit = false;//Reset c_quit to prevent accidental
				//exiting of the game.
				//if (Game::c_restart) Game::c_restart = false;//Reset the c_restart to prevent
				//accidental restarting of the game.
				
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
		
		case 27://27 refers to the escape key Ascii code. 
		
		//When the escape key is hit the game will check the c_quit variables state. 
		//If that state is false switch it to true, it if is true, switch it to false.
		
			if ((!Game::c_running) && (!Game::c_gameOver) && (!Game::c_winCondition)) {
				
				Game::c_escape = !Game::c_escape;
				if (Game::c_quit) Game::c_quit = false;//Reset c_quit to prevent accidental
				//exiting of the game.
				if (Game::c_restart) Game::c_restart = false;//Reset the c_restart to prevent
				//accidental restarting of the game.
				
			} 			
			break;

		case 13://13 is the enter key. This states that if the enter key is
		//pressed while the game is paused do the following:
			 
			if ((!Game::c_running) && (Game::c_escape) && 
				((Game::c_restart) || (Game::c_quit))) {
				//If the game is paused, the escape options called, and either the
				//restart or quit variables set to true;
			
				glutLeaveMainLoop();//This function will force the glutmainloop to exit
				//allowing us to return to the init function and then quit properly.
			
			}
				
			//Otherwise do nothing.
			break;
		
		//Future Content: Restart ability. Due to the complexity, restart was canceled as 
		//a feature of the final demo. However in the future this feature would be implemented.
		//case 'r':
		
		//When this key is pressed, the game varifies that the quit confirmation screen was
		//set to true, along with the game being paused. In this condition the game will
		//reset the c_quit variable to false and then leave the glut main loop. This allows
		//the game to destroy the instance and then restart. This should only be called 
		//if the game has been started. Otherwise there is no need to restart.

			//if ((!Game::c_running) && (Game::c_escape) && (Game::c_run)) {
				//Aslong as the game has started, the escape screen was called, and the game 
				//is paused, allow the game to be set to restart.			
				
				//c_quit = false;//Ensure the c_quit variable is set to false before leaving
				//the loop.
				//c_restart = true;
			
			//}
			//break;
	
		//TODO Test this method of quitting the game.
		case 'q':
		
			if ((!Game::c_running) && (Game::c_escape)) {
				
				c_restart = false;//Remove this line if restart is abandoned.
				c_quit = true;
				
			}
			break;
	
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
	
	if (DEBUG) {
		
		cout << "Debug-Game.cpp: Starting up the game...\n";
		cout << "Debug-Game.cpp: Please wait...\n";
		
	}
	
	//Start by trying to initialize Jukebox and then init glut and getInstance to that
	//the game will start (within getInstance).
	if(!Jukebox::init()) {
		
		exit;
	
	}
		
	if (DEBUG) {
		
		cout << "Debug-Game.cpp: Jukebox and glut libraries initialized.\n";
		cout << "Debug-Game.cpp: Creating singleton... please wait...\n";
		
	}
	
	//while (!Game::c_quit) {//While loop may be used for the ability to restart
	//however currently this is not expected to be enabled.
		
		glutInit(&argc, argv);//Initialization of the glut libraries.
		Game::getInstance().init();//Starts up the game.
	
	//}
	
	SDL_CloseAudio();//Once the game is ended, close the audio.	
		
	if(DEBUG) {
		
		cout << "Debug-Game.cpp: Shutting Down...\n";
	
	}
	
	return 0;//Ensure the program exits.
	
}
/****End Main Function*****************************************************************/

/**************************************************************************************/
/***Notes for the CSCI331 Oral Exam:***************************************************/
/**************************************************************************************/
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

//Creator: The creator pattern is in use because in Game's init It must
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
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/