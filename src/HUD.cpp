/*

File: src/HUD.cpp
Author: Benjamin Smith
Purpose: 
	This superclass for the HUD function allows for the implementation of an overlain
	view window to the main window that encompasses the characters current health
	and weapon information. 

*/

#include "../hdr/HUD.h"


	void HUD::RenderString(float x, float y, void *font, const char* string)
	{  
	  char *c;

	  const unsigned char* string2 = (const unsigned char*)string;

	  glColor3f(0.0, 0.0, 0.0); // black
	  glRasterPos2f(x, y);

	  glutBitmapString(font, string2);
	} 

	void HUD::displayHUD() {
		RenderString(m_width - 150, m_height - 50, GLUT_BITMAP_TIMES_ROMAN_24, "Health");
		RenderString(m_width - 150, m_height - 200, GLUT_BITMAP_TIMES_ROMAN_24, "Weapon");
		RenderString(m_width - 150, m_height - 250, GLUT_BITMAP_TIMES_ROMAN_24, "Inventory");
		
	}


