//Edited by: Keenan Longair.
//Last update: 8:30PM February 8th, 2016.
//Purpose: Prototyping of the main "GameBoard" and its interface. This is implemented
//as a singleton and thus can only have one instance. Use the Game::getInstance() function
//to gain access to the instance.
//Version: 0.6

#ifndef GAME_H_
#define GAME_H_

#include <stdlib.h>
#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */

class ImageLoader;//Gives access to the ImageLoader.
class Menu;//Gives access to the Menu.

#define MAX_OBJECTS 50//50 is Default for now, may be increased once # of objects has been
//determined.

class Game {
	
    private:
        //Contructor is private, if you want to get the instance use the public getInstance
		//function by calling Game::getInstance().
        Game() {
           m_margine = 4;
           m_width = 507*2;
           m_height = 432*2;
        };//Default Constructor.
        
		Game(Game const&);           //Don't Implement
        void operator=(Game const&); //Don't implement
		
		const static int c_interval = 1000 / 60;//60 frames per second, c_interval sets up
		//the screens refresh rate and fps I believe.

		//Window size:
		int m_width;
		int m_height;
		int m_margine;
		//Background texture:
		GLuint m_backgroundTexture;
		
	public:
	    //Insead of a constructor, use this static method to create an instance
        //(or use the already created instance) of Game making this a singleton.
        static Game& getInstance()
        {
            static Game instance;//Guaranteed to be destroyed.
            //Instantiated on first use.
            return instance;
        };
		
		static bool c_running;//Variable to tell update if the game is to be paused or not.
		//The c_running variable is public, to allow other objects to alter this, in essence
		//allowing events to pause the game if necessary.
		
		//Functions for GL.
		static void key(unsigned char key, int x, int y);//Key takes in the key commands 
		//used to call the control functions of the controllable character.
		static void run();//Run is the computing loop which calls update.
		static void idle();//Handles the delay between screen updates. 
		static void timer(int id);//Times and calls the update on the screen.
		void update();//Update handles updating the display screen and calling update on each object.
		void reshape(GLsizei newwidth, GLsizei newheight);//Reshapes the window as needed.

		int LoadImage(char *filename);//Not sure what this does yet due to missing implementation.
		//This function is currently left here in order to have it incase it is needed, but may be
		//removed once its use is understood.
		
		void init();//Set to be public incase any objects inheriting from this needs their init
		//to be public aswell.

		GLfloat frand();//Random number function. Here incase we need it.
		
};


#endif /* GAME_H_ */
