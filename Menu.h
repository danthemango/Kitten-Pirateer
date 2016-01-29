//Edited by: Keenan Longair.
//Last Update: 8:00PM January 28, 2016.
//Purpose: To prototype the interface needed to create a spash screen
//and main menu.
//Version: 0.1

#ifndef MENU_H_
#define MENU_H_

//Libraries included until all dependancies are worked out.
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <GL/freeglut.h>
#include <cstdio>
#include "ImageLoader.h"

//class imageLoader;

class Menu {
	
	private:

		//Contructor
		Menu() {
			
			m_width = 500;//Need a set width.			
			m_height = 500;//Need a set height.
			
		};
		
		//Menu and splashScreen height and width variables.
		int m_width;
		int m_height;

	public:
	
		//Still working on making this a proper singleton.
		static Menu& getMenu()
		{
			
			static Menu instance;
			return instance;
			
		};
		
		void init();//Prepares the various files.
		void update();//Handles updateing any menu information.
		void splashScreen();//Provides the spashscreen for pausing the
		//game.
		void mainMenu();//Provides the main menu presented at the start
		//of the game.
		//void inventorymenu();//Provides an inventory menu. Not implemented
		//but will be an extra goal.
		
};

#endif /* MENU_H_ */