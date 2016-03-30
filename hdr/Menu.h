//Edited by: Keenan Longair.
//Last update: 5:45PM March 25th, 2016.
//Purpose: To prototype the interface needed to create a spash screen
//and main menu.
//Version: 1.0
//**************************************************************************************

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

//Class description below:
class Menu {
	
	private:

		//Menu and splashScreen height and width variables.
		//int m_width;//Variables storing the width of the max menu size.
		//int m_height;//Variable storing the height of the max menu size.
		GLuint m_pauseTexture;//Variable storing the pause texture.
		GLuint m_menuTexture;//Variable storing the menu texture.
		GLuint m_winTexture;//Variable storing the win texture.
		GLuint m_loseTexture;//Variable storing the lose texture.
		GLuint m_quitTexture;//Variable storing the quit confirmation texture.
		GLuint m_restartTexture;//Variable storing the restart confirmation texture.
		GLuint m_escapeTexture;//Variable storing the escape menu.

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
		void pauseScreen();//Provides the spashscreen for pausing the
		//game.
		void mainMenu();//Provides the main menu presented at the start
		//of the game.
		void quitConf();//Provides the quit confirmation screen.
		void restartConf();//Provides the screen presenting the restart confirmation
		//message.
		void escapeScreen();//Provides the quit/restart option screen.	
		
		//TODO create the win/lose textures and win/lose screen's need to give the 
		//option to quit.
		void winScreen();//Provides the screen presenting the win message.
		void loseScreen();//Provides the screen presenting the lose message.
		
};

#endif /* MENU_H_ */