//Edited by: Keenan Longair.
//Last Update: 8:30PM February 8th, 2016.
//Purpose: To implement the prototyped functions found in the Menu.h file
//which will provide the menus of the game.
//Version: 0.4

//Libraries included until all dependancies are worked out.
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <GL/freeglut.h>
#include <cstdio>
#include "../hdr/ImageLoader.h"//Dependancy for images.

void Menu::init()
{

}

void Menu::update()
{

}

void Menu::splashScreen()
{

	m_splashTexture= ImageLoader::LoadTexture( "./imgs/pausemenu.bmp" );
 
	glEnable(GL_TEXTURE_2D);
	ImageLoader::rectangle(200, 250, 600, 215);
   
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_splashTexture);
   
	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}

void Menu::mainMenu()
//Main Menu, used at the very start of the game.
{
	
  m_splashTexture= ImageLoader::LoadTexture( "./imgs/mainmenu.bmp" );
   
   glEnable(GL_TEXTURE_2D);
   ImageLoader::rectangle(200, 250, 600, 215);
   
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
   glBindTexture (GL_TEXTURE_2D, m_splashTexture);
   
   glDisable(GL_TEXTURE_2D);
   glFlush();
	
}

