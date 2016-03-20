//Edited by: Keenan Longair.
//Last update: 12:30PM March 17th, 2016.
//Purpose: To prototype the interface needed to create a spash screen
//and main menu.
//Version: 0.9

#ifndef MENU_H_
#define MENU_H_

//Libraries required:
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <GL/freeglut.h>
#include <cstdio>

//Required files:
#include "../hdr/ImageLoader.h"
#include "../hdr/config.h"

//Classes required:
class imageLoader;

//Class description below:
class Menu {
	
	private:

		//Menu and splashScreen height and width variables.
		//int m_width;//Variables storing the width of the max menu size.
		//int m_height;//Variable storing the height of the max menu size.
		GLuint m_splashTexture;//Variable storing the pause texture.
		GLuint m_menuTexture;//Variable storing the menu texture.
		GLuint m_winTexture;//Variable storing the win texture.
		GLuint m_loseTexture;//Variable storing the lose texture.
		GLuint m_quitTexture;//Variable storing the quit texture.

	public:
	
		//Contructor
		Menu() {

			//Varify the if these are really needed. So far it appears that menu
			//does not need to know this.
			//m_width = SCREEN_SIZE_X - 100;//Need a set width.			
			//m_height = SCREEN_SIZE_Y - 100;//Need a set height.

		};
		
		
		//Required Functions:
		void init();//Prepares the various files.
		void update();//Handles updateing any menu information if needed.
		void splashScreen();//Provides the spashscreen for pausing the
		//game.
		void mainMenu();//Provides the main menu presented at the start
		//of the game.
		//Win/lose screen's need to give the option of quitting or restarting.
		//So far there is the ability to quit through a key (currently = '-')
		//but a restart ability eludes me.
		//void winScreen();//Provides the screen presenting the win message.
		//void loseScreen();//Provides the screen presenting the lose message.
		//void quitScreen();//Provides the quit confirmation screen.

};

#endif /* MENU_H_ */
