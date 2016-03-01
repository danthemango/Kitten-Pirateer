//Edited by: Keenan Longair.
//Last update: 3:30PM February 26th, 2016.
//Purpose: To implement the prototyped functions found in the Menu.h file
//which will provide the menus of the game.
//Version: 0.6

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
	//m_splashTexture= ImageLoader::LoadTexture( "./imgs/menus/pausemenu.bmp" );
 
	glEnable(GL_TEXTURE_2D);
	ImageLoader::rectangle(200, 250, 600, 215);
   
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
	
	//Call the main menu image wwe need to display at the start of the game.
	//m_splashTexture = ImageLoader::LoadTexture( "./imgs/menus/mainmenu.bmp" );

	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_splashTexture);
   	ImageLoader::rectangle(200, 250, 800, 600);

	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}

