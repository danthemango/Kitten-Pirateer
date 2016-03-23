//Edited by: Keenan Longair.
//Last update: 12:30PM March 20th, 2016.
//Purpose: Prototyping of the main "GameBoard" and its interface. This is implemented
//as a singleton and thus can only have one instance. Use the Game::getInstance() 
//function to gain access to the instance.
//Version: 1.5
//**************************************************************************************

#ifndef GAME_H_
#define GAME_H_

//Required Libraries:
#include <stdlib.h>
#include <GL/glut.h>/*glut.h includes gl.h and glu.h*/

//Required .h files:
#include "../hdr/config.h"//Include the configuration settings.
#include "../hdr/Player.h"//Include the Player class.
#include "../hdr/Obstacle.h"//Include the Obstacle class.
#include "../hdr/MapHandler.h"//Include the MapHandler class.
#include "../hdr/ZombieHandler.h"//Include the ZombieHandler.h
#include "../hdr/Menu.h"//Include the menu class.

//Various required classes:
class Player;//Gives access to the Player.
class Obstacle;//Gives access to the Obstacle.
class ImageLoader;//Gives access to the ImageLoader.
class Menu;//Gives access to the Menu.

//ORALEXAM: Singleton justification located on line 83. Info on line 88.

//Class definition of Game below:
class Game {
	
    private:
	
        //If you want to get the instance use Game::getInstance() function provided in 
		//the public section.
        Game()
		{
			
			m_margine = HUD_WIDTH;
			m_width = SCREEN_SIZE_X;
			m_height = SCREEN_SIZE_Y;
			//m_menu = new Menu();
		   
        };//Default Constructor.
        
		Game(Game const&);           //Don't Implement
        void operator=(Game const&); //Don't implement
		
		//Do not implement
		//Deconstructor:
		//~Game() {
			
			//TODO Try to set up the deconstructor to be used in order to call the proper delete
			//methods of the classes. Ask Dr. J to help direct me on how to properly have this 
			//called.
			
		//};
		
		const static int m_interval = 1000 / 60;//60 frames per second, c_interval sets 
		//up the screens refresh rate and fps.

		//Game Variables:
		int m_width;
		int m_height;
		int m_margine;
		
		Menu m_menu;
		
		//Background texture:
		GLuint m_backgroundTexture;	
		
	public:
	
		//DrJ Pattern Singleton
		
	    //Insead of a constructor, use this static method to create an instance
        //(or use the already created instance) of Game making this a singleton.
        static Game& getInstance()
        {
            static Game instance;//Guaranteed to be destroyed.
            //Instantiated on first use.
            return instance;
        };
		
		//JUSTIFICATION:
		//A singleton is used not only due to the requirements but due to the fact that a 
		//singleton is perfect for a game which only requires one instance.
		//With the game being a single player non networked game, a singleton allows us to have
		//only one instance of the Game and allows us to call its methods and functions. This 
		//also allows us to cut down on resources being used by only manageing one instance of
		//the game at a time.
		
		//Singleton information: 
		//INTENT: Ensure a class only ever has one instance, and provide a global point of 
		//access to it.
		//APPLICABILITY: When there must be exactly one instance of a class, and it must be 
		//accessible from a well-known access point. When the sole instance should be 
		//extensible by subclassing, and clients should be able to use an extended instance 
		//without modifying their code. 
		//CONSEQUENCES: Reduces namespace pollution, makes it easy to change your mind and 
		//allow more than one instance, allows extension by subclassing, same drawbacks of a
		//global if	misused, implementation may be less efficient than a global, and Concurrency
		//pitfalls. Also controlled access to sole instance, permits refinement of operations and
		//representations, permits a variable number of instances and is more flexible than class
		//operations.
		//NOTE: The singletons do add coupling, and when implementing a class as a singleton 
		//every application must use this class exactly the same way, every application only 
		//ever needs one instance of the class, and clients of the class are unaware of which 
		//application they belong to.
		//IMPLEMENTATION: Static instance operation and registering of the singleton instance.
		//KNOWN USES: Smalltalk-80 ChangeSet, the set of change to code, InterViews Session object,
		//and Unidraw's Unidraw object.
		
		//Public Variables:
		static int m_lastSong;//Stores the last song time stamp.
		static bool m_run;//Variable to handle the start up of the game. When this is set
		//to false, the game waits on the main menu. Once this is changed to true, the game
		//runs until the c_running variable is changed. This variable allows us to possibly
		//implement a system of restarting the game through a wide scope control variable.
		static bool m_running;//Variable to tell update if the game is to be paused or not.
		//The c_running variable is public, to allow other objects to alter this, in essence
		//allowing events to pause the game if necessary.
		static bool m_gameOver;//This variable will tell us if the game is over.
		static bool m_winCondition;//This variable will tell us if the game's win condition
		//was met or not. If this is true, the player won, if false, the player lost.
		static int m_windowID;//This variable stores the window id when the game is created.
		static bool m_quit;//This variable enables or disables the ability to hit enter and
		//quit during a time where the game is currently considered paused.
		
		//Required functions:
		static bool* keystates;
		static void keyUp(unsigned char key, int x, int y);
		void keyOperations();
		static void key(unsigned char key, int x, int y);//Key takes in the key commands 
		//used to call the switch control functions.
		static void run();//Run is the computing loop which calls update.
		static void idle();//Handles the delay between screen updates. 
		static void timer(int id);//Times and calls the update on the screen.
		void update();//Update handles updating the display screen and calling update on each object.
		void reshape(GLsizei newwidth, GLsizei newheight);//Reshapes the window as needed.
		void init();//Set to be public incase any objects inheriting from this needs their init
		//to be public aswell.
		void updateTile(GLuint x);//Call this function with the next tile texture as input
		//to change the background tile variable.
		void restartGame();//Function to restart the game when called. TODO Ask Dr. J to help direct
		//me on this section.
		
		//TODO Verify the need for this method. Does not appear in the original .cpp
		int LoadImage(char *filename);//Required for loading an image.		
		
		//Possible functions: These are pulled from the collision lab 
		//to be prepared incase anything is transfered over. 
		//Anything unused will be removed before the final due date.
		//GLfloat frand();//Random number function. Here incase we need it.

};

#endif /* GAME_H_ */

//DrJ Team Contribution

//What functionality did I provide?
//I provide the main game loop through creation and management of a single Game instance.
//This allows our game to loop using the GLutMainLoop function which provides the ability to 
//repeatedly call update and display on the games objects. This allows us to present the 
//objects without trying ot manage various instances. I also provide the menu's to be displayed
//and the control input methods. This means that I created a Menu class which handles displaying
//the desired menu along with the controls to handle the users input at the menus and during
//gameplay. Jukebox is also my responcibility and as such I try to maintain and make sure the 
//interface is simple and understood. To me Game's continued management has been the biggest 
//contribution due to the fact that the Game class really puts all the pieces together in order
//to allow us to have a running program. Game initializes everything and creates any instances
//that are required before locking into its main loop to allow the game to play out. I feel that
//my code could be much neater and cleaner however I am struggling to understand the full reaches 
//of the glut libraries.

//How did I make it easy for them to user/interface with?
//I kept the interfaces simple, clear and well documented. By keeping everything simple and clear,
//my fellow team mates have an easy time reading what a method should do or what a variable is for.
//Keeping the interface clear allows to only further improved my team mates chances of understanding
//the interface when used with the simplistic design. To further improve this I have tried to make
//sure all my interface code is well documented and up to date. Combining all of these creates a
//good base for my team mates to understand my interfaces but also allows me to quickly review 
//my interface and answer any questions or fix any bugs that may arise. I have kept my interface as
//similar to previous labs to allow us all to have a decent starting point, from which to work on.
