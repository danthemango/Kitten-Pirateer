//Edited by: Keenan Longair.
//Last update: 12:00PM March 12th, 2016.
//Purpose: To prototype the interface needed to create a spash screen
//and main menu.
//Version: 0.7

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
		int m_width;
		int m_height;
		GLuint m_splashTexture;
		GLuint m_menuTexture;
		GLuint m_winTexture;
		GLuint m_loseTexture;

	public:
	
		//Contructor
		Menu() {
			try {
			//These size variables may not be needed since
			//all menu does is loads and displays a bmp.
			m_width = SCREEN_SIZE_X - 100;//Need a set width.			
			m_height = SCREEN_SIZE_Y - 100;//Need a set height.
			//Preload the textures for menus. This prevents constant reloading of them
			//while the game is waiting on a menu.
			m_splashTexture = ImageLoader::LoadTexture(PAUSE_MENU);
			m_menuTexture = ImageLoader::LoadTexture(MAIN_MENU);
			//m_winTexture = ImageLoader::LoadTexture(WIN_SCREEN);
			//m_loseTexture = ImageLoader::LoadTexture(LOSE_SCREEN);
			} catch (exception &e) {
				cout << e.what() << endl;
			}
		};
		
		
		//Required Functions:
		void init();//Prepares the various files.
		void update();//Handles updateing any menu information if needed.
		void splashScreen();//Provides the spashscreen for pausing the
		//game.
		void mainMenu();//Provides the main menu presented at the start
		//of the game.
		void winScreen();//Provides the screen presenting the win message.
		void loseScreen();//Provides the screen presenting the lose message.

};

#endif /* MENU_H_ */
