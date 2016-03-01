//Edited by: Keenan Longair.
//Last update: 3:30PM February 26th, 2016.
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

	public:
		//Contructor
		Menu() {
			
			//These size variables may not be needed since
			//all menu does is loads and displays a bmp.
			m_width = SCREEN_SIZE_X - 100;//Need a set width.			
			m_height = SCREEN_SIZE_Y - 100;//Need a set height.
			m_splashTexture = ImageLoader::LoadTexture( "./imgs/menus/pausemenu.bmp" );
			m_menuTexture = ImageLoader::LoadTexture( "./imgs/menus/mainmenu.png" );
			
		};
		
		
		//Required Functions:
		void init();//Prepares the various files.
		void update();//Handles updateing any menu information if needed.
		void splashScreen();//Provides the spashscreen for pausing the
		//game.
		void mainMenu();//Provides the main menu presented at the start
		//of the game.

		//Extra goals, functions for the future:
		//void inventorymenu();//Provides an inventory menu.
		//void winScreen();//Provides the screen presenting the win message.
		//void loseScreen();//Provides the screen presenting the lose message.
		
};

#endif /* MENU_H_ */
