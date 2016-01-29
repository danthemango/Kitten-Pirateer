//Edited by: Keenan Longair.
//Last update: 8:00PM January 28, 2016.
//Purpose: Prototyping of the main "GameBoard" and its interface. This is implemented
//as a singleton and thus can only have one instance. Use the Game::getInstance() function
//to gain access to the instance.
//Version: 0.3

#ifndef GAME_H_
#define GAME_H_

#include <stdlib.h>
#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */

//class ImageLoader;
class Menu;//Gives access to the Menu.

#define MAX_OBJECTS 50

class Game {
// Required portions for making this a Singleton.
    public:
        //Insead of a constructor, use this static method to create an instance
        //(or used the already created instance) of Game
        static Game& getInstance()
        {
            static Game instance;//Guaranteed to be destroyed.
            //Instantiated on first use.
            return instance;
        };
		
    private:
        // Make all the constructors private. If you want an instance, use the 
        // getInstance() method above
        Game() {
           m_margine = 4;
           m_width = 507*2;
           m_height = 432*2;
        }; // Default Constructor (the {} brackets) are needed here, even if it is empty.
        Game(Game const&);           // Don't Implement
        void operator=(Game const&); // Don't implement

	//Now that we are  a Singleton, define the rest of the class as usual.
	private:
      const static int c_interval = 1000 / 60;//60 frames per second

		//Window size 
		int m_width;
		int m_height;
		int m_margine;

		GLuint m_backgroundTexture;


	public:
		//Functions for GL. Key handles keyboard input. Run is the computing loop
		//and calls update
		static bool c_running;//Variable to tell update if the game is to be paused or not.
		static void key(unsigned char key, int x, int y);
		static void run();
		static void idle();
		static void timer(int id);
		void update();
		//void splashScreen();//Implemented as its own object.
		void reshape(GLsizei newwidth, GLsizei newheight);
		int LoadImage(char *filename);

		void init();

		GLfloat frand();
};


#endif /* GAME_H_ */
