//Edited by: Keenan Longair.
//Last UpdatE: 7:00PM January 28, 2016.
//Purpose: To implement the prototyped functions found in the Menu.h file
//which will provide the menus of the game.
//Version: 0.1

//Libraries included until all dependancies are worked out.
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <GL/freeglut.h>
#include <cstdio>
#include "ImageLoader.h"

void Menu::init()
{

}

void Menu::update()
{

}

void Menu::splashScreen()
{
	
	//Other parts of the program have been doing speical things with
	//lights and textures. We want a flat rectangle so turn them all off.
	glDisable(GL_TEXTURE_2D);//Disable any textures. We want color!
	glDisable (GL_LIGHTING);//Also turn off any lights
	glLoadIdentity();//load identity matrix

	glEnable(GL_COLOR_MATERIAL);//Needed so glColor3f controls the color
	glColor3f(0.5f,0.7f,1.0f);//Sky blue backcground for now, will be changed.
	//ImageLoader::rectangle(20, 20, m_width-40, m_height-40);

	char string[1200];
	sprintf(string, "Game Paused. Press space to continue.\n");
	sprintf(string, "%s\nControls:", string);
	glColor3f(0.0, 0.0, 0.0);//Black Text
	//ImageLoader::RenderString(30, m_height-60, GLUT_BITMAP_TIMES_ROMAN_24, string);
	glDisable(GL_COLOR_MATERIAL);
	
}

void Menu::mainMenu()
{
	
	//Other parts of the program have been doing speical things with
	//lights and textures. We want a flat rectangle so turn them all off.
	glDisable(GL_TEXTURE_2D);//Disable any textures. We want color!
	glDisable (GL_LIGHTING);//Also turn off any lights
	glLoadIdentity();//load identity matrix

	glEnable(GL_COLOR_MATERIAL);//Needed so glColor3f controls the color
	glColor3f(0.5f,0.7f,1.0f);//Sky blue backcground for now, will be changed.
	//ImageLoader::rectangle(20, 20, m_width-40, m_height-40);

	char string[1200];
	sprintf(string, "Welcome to Kitty Piratier: Zombie Island!\n");
	sprintf(string, "%s\nControls:", string);
	//Reserved space for game control list.
	
	
	sprintf(string, "Press _ to start the game.\n");
	glColor3f(0.0, 0.0, 0.0);//Black Text
	//ImageLoader::RenderString(30, m_height-60, GLUT_BITMAP_TIMES_ROMAN_24, string);
	glDisable(GL_COLOR_MATERIAL);
	
}

