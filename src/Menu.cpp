//Edited by: Keenan Longair.
//Last update:  5:30PM March 23rd, 2016.
//Purpose: To implement the prototyped functions found in the Menu.h file
//which will provide the menus of the game.
//Version: 1.0
//TODO create the win/lose screens aswell as the finalize menu, quit confirmation 
//screen and pause screen.

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

	m_menuTexture = ImageLoader::LoadTexture(MAIN_MENU);
	m_splashTexture = ImageLoader::LoadTexture(PAUSE_MENU);	
	//m_winTexture = ImageLoader::LoadTexture(WIN_SCREEN);
	//m_loseTexture = ImageLoader::LoadTexture(LOSE_SCREEN);
	m_quitTexture = ImageLoader::LoadTexture(QUIT_SCREEN);

}

void Menu::update()
//Update the menu's display here.
{

}

void Menu::splashScreen()
//Display the splash screen used as a pause pause screen.
{
	
	//Call the menu image we need to display when pausing the game.
	//The loading of this texture occurs in Menu::init().
	//m_splashTexture= ImageLoader::LoadTexture( "./imgs/menus/pausemenu.bmp" );
 
	glEnable(GL_TEXTURE_2D);
	ImageLoader::rectangle(227, 420, 600, 215);//x, y, width, height.

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
	//The loading of this texture occurs in Menu::init().
	//m_menuTexture = ImageLoader::LoadTexture( "./imgs/menus/mainmenu.png" );

	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_menuTexture);
   	ImageLoader::rectangle(127, 227, 800, 600);//x, y, width, height.

	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}

/*
//TODO create the quitScreen, winScreen and loseScreens along side the revised menu and pause screens.
//TODO set the size of the windows and their orientation to be centered. 
void Menu::winScreen()
//winScreen simply displays the end game victory screen.
{
	
	//Call the main menu image we need to display at the start of the game.
	//The loading of this texture occurs in the Menu.h constructor.
	//m_winTexture = ImageLoader::LoadTexture( "./imgs/menus/winscreen.png" );

	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_winTexture);
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
	glBindTexture (GL_TEXTURE_2D, m_loseTexture);
   	ImageLoader::rectangle(200, 250, 800, 600);//x, y, width, height.

	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}
*/

void Menu::quitScreen()
//loseScreen simply displays the end game lose screen.
{
	
	//Call the main menu image we need to display at the start of the game.
	//The loading of this texture occurs in the Menu.h constructor.
	//m_quitTexture = ImageLoader::LoadTexture( "./imgs/menus/quitscreen.png" );

	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_quitTexture);
   	ImageLoader::rectangle(327, 427, 400, 200);//x, y, width, height.

	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}
