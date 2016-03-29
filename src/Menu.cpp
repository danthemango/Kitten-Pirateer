//Edited by: Keenan Longair.
//Last update: 5:45PM March 25th, 2016.
//Purpose: To implement the prototyped functions found in the Menu.h file
//which will provide the menus of the game.
//Version: 1.2
//**************************************************************************************
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
	m_pauseTexture = ImageLoader::LoadTexture(PAUSE_MENU);	
	m_quitTexture = ImageLoader::LoadTexture(QUIT_SCREEN);
	m_restartTexture = ImageLoader::LoadTexture(RESTART_SCREEN);
	m_escapeTexture = ImageLoader::LoadTexture(ESCAPE_SCREEN);
	//m_winTexture = ImageLoader::LoadTexture(WIN_SCREEN);
	//m_loseTexture = ImageLoader::LoadTexture(LOSE_SCREEN);

}

void Menu::update()
//Update the menu's display here.
{

}

void Menu::pauseScreen()
//Display the splash screen used as a pause pause screen.
{

	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_pauseTexture);
  	ImageLoader::rectangle(227, 377, 600, 300);//x, y, width, height. 
	
	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}

void Menu::mainMenu()
//Main Menu, used at the very start of the game.
//May only be used once for now, however if we enable a restart feature
//this may be called more frequently.
{
	
	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_menuTexture);
   	ImageLoader::rectangle(127, 227, 800, 600);//x, y, width, height.

	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}

void Menu::quitConf()
//loseScreen simply displays the end game lose screen.
{

	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_quitTexture);
   	ImageLoader::rectangle(327, 427, 400, 200);//x, y, width, height.

	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}

void Menu::restartConf()
//loseScreen simply displays the end game lose screen.
{
	
	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_restartTexture);
   	ImageLoader::rectangle(327, 427, 400, 200);//x, y, width, height.

	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}

void Menu::escapeScreen()
//loseScreen simply displays the end game lose screen.
{

	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_escapeTexture);
   	ImageLoader::rectangle(327, 427, 400, 200);//x, y, width, height.

	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}


//TODO create the winScreen and loseScreens.
//TODO set the size of the windows and their orientation to be centered. 
void Menu::winScreen()
//winScreen simply displays the end game victory screen.
{

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

	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture (GL_TEXTURE_2D, m_loseTexture);
   	ImageLoader::rectangle(200, 250, 800, 600);//x, y, width, height.

	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}
