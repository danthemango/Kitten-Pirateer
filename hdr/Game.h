//Edited by: Keenan Longair.
//Last update: 2:00PM February 28th, 2016.
//Purpose: Prototyping of the main "GameBoard" and its interface. This is implemented
//as a singleton and thus can only have one instance. Use the Game::getInstance() 
//function to gain access to the instance.
//Version: 1.3
//**************************************************************************************

#ifndef GAME_H_
#define GAME_H_

//Required Libraries:
#include <stdlib.h>
#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */

//Required .h files:
#include "../hdr/config.h"//Include the configuration settings.
#include "../hdr/Player.h"//Include the Player class.
#include "../hdr/Obstacle.h"//Include the Obstacle class.
#include "../hdr/MapHandler.h"//Include the MapHandler class.
#include "../hdr/ZombieHandler.h"

//Various required classes:
class Player;//Gives access to the Player.
class Obstacle;//Gives access to the Obstacle.
class ImageLoader;//Gives access to the ImageLoader.
class Menu;//Gives access to the Menu.

//Class definition of Game below:
class Game {
	
    private:
	
        //If you want to get the instance use Game::getInstance() function provided in 
		//the public section.
        Game() 
		{
			
           m_margine = MARGINE;
           m_width = SCREEN_SIZE_X;
           m_height = SCREEN_SIZE_Y;
		   
        };//Default Constructor.
        
		Game(Game const&);           //Don't Implement
        void operator=(Game const&); //Don't implement
		
		const static int c_interval = 1000 / 60;//60 frames per second, c_interval sets 
		//up the screens refresh rate and fps.

		//Game Variables:
		int m_width;
		int m_height;
		int m_margine;
		//int m_arraypos;
		//int m_gameObjects;
		
		//Background texture:
		GLuint m_backgroundTexture;

		//Obstacle objects:
		Obstacle *m_myGameObjects3[10];
		Obstacle *m_myGameObjects4[10];

		//Player objects:
		Player m_myPlayer;
		
		//MapHandler object:
		//Place holder to help remind me to add the creation of the MapHandler.
		//Most likly this will be done with new inside of the Game.cpp init itself 
		//instead of being done here.
		MapHandler m_MapHandler;
		
	public:
	
	    //Insead of a constructor, use this static method to create an instance
        //(or use the already created instance) of Game making this a singleton.
        static Game& getInstance()
        {
            static Game instance;//Guaranteed to be destroyed.
            //Instantiated on first use.
            return instance;
        };
		
		//Public Variables:
		static bool c_run;//Variable to handle the start up of the game. When this is set
		//to false, the game waits on the main menu. Once this is changed to true, the game
		//runs until the c_running variable is changed. This variable allows us to possibly
		//implement a system of restarting the game through a wide scope control variable.
		static bool c_running;//Variable to tell update if the game is to be paused or not.
		//The c_running variable is public, to allow other objects to alter this, in essence
		//allowing events to pause the game if necessary.
		
		//Control Input Functions:
		static bool* keystates;
		static void keyUp(unsigned char key, int x, int y);
		static void key(unsigned char key, int x, int y);
		void keyOperations();
		
		//Possible functions: These are pulled from the collision lab 
		//to be prepared incase anything is transfered over. 
		//Anything unused will be removed before the final due date.
		//void changeScreen(int dir);
		//int getArrayPos();
		//void setArrayPos(int pos);
		int getWidth();
		int getHeight();
		
		//Required functions:
		static void key(unsigned char key, int x, int y);//Key takes in the key commands 
		//used to call the switch control functions.
		static void run();//Run is the computing loop which calls update.
		static void idle();//Handles the delay between screen updates. 
		static void timer(int id);//Times and calls the update on the screen.
		void update();//Update handles updating the display screen and calling update on each object.
		void reshape(GLsizei newwidth, GLsizei newheight);//Reshapes the window as needed.
		int LoadImage(char *filename);//Required for loading an image.
		void init();//Set to be public incase any objects inheriting from this needs their init
		//to be public aswell.
		void updateTile(GLuint X);//Call this function with the next tile texture as input
		//to change the background tile variable.
		
		GLfloat frand();//Random number function. Here incase we need it.
		//These last two functions may not be needed since Width and Height are stored within the
		//config.h file.

};

#endif /* GAME_H_ */
