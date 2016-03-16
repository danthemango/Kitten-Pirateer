//Edited by: Keenan Longair.
//Last update: 12:00PM March 12th, 2016.
//Purpose: To implement the prototyped functions found in the Menu.h file
//which will provide the menus of the game.
//Version: 0.8
//TODO create the win/lose screens aswell as a finalized menu and pause menu.
//TODO work out the x/y coordinates for the win/lose menu. 

//Libraries required:
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <GL/freeglut.h>
#include <cstdio>

//Required files:
#include "../hdr/ImageLoader.h"//Dependancy for images.
#include "../hdr/Menu.h"//Prototype source code.

void Menu::init()
//Prepare any Menu variables here.
{

}

void Menu::update()
//Update the menu's display here.
{

}

void Menu::splashScreen()
//Display the splash screen used as a pause pause screen.
{
	
	//Call the menu image we need to display when pausing the game.
	//The loading of this texture occurs in the Menu.h constructor.
	//m_splashTexture= ImageLoader::LoadTexture( "./imgs/menus/pausemenu.bmp" );
 
	glEnable(GL_TEXTURE_2D);
	ImageLoader::rectangle(420, 127, 600, 215);//x, y, width, height.
   
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_splashTexture);
   
	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}

void Menu::mainMenu()
//Main Menu, used at the very start of the game.
//May only be used once for now, however if we enable a restart feature
//this may be called more frequently.
{
	
	//Call the main menu image we need to display at the start of the game.
	//The loading of this texture occurs in the Menu.h constructor.
	//m_menuTexture = ImageLoader::LoadTexture( "./imgs/menus/mainmenu.png" );

	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_menuTexture);
   	ImageLoader::rectangle(227, 27, 800, 600);//x, y, width, height.

	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}

/*
//TODO create the winScreen and loseScreens along side the revised menu and pause screens.
//TODO set the size of the windows and their orientation to be centered. 
void Menu::winScreen()
//winScreen simply displays the end game victory screen.
{
	
	//Call the main menu image we need to display at the start of the game.
	//The loading of this texture occurs in the Menu.h constructor.
	//m_winTexture = ImageLoader::LoadTexture( "./imgs/menus/winscreen.png" );

	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_menuTexture);
   	ImageLoader::rectangle(200, 250, 800, 600);//x, y, width, height.

	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}

void Menu::loseScreen()
//loseScreen simply displays the end game lose screen.
{
	
	//Call the main menu image we need to display at the start of the game.
	//The loading of this texture occurs in the Menu.h constructor.
	//m_loseTexture = ImageLoader::LoadTexture( "./imgs/menus/losescreen.png" );

	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_menuTexture);
   	ImageLoader::rectangle(200, 250, 800, 600);//x, y, width, height.

	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}
*/