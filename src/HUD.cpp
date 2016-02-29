/*

File: src/HUD.cpp
Author: Benjamin Smith
Purpose: 
	This superclass for the HUD function allows for the implementation of an overlain
	view window to the main window that encompasses the characters current health
	and weapon information. 

*/

#include "../hdr/HUD.h"

	// Prints a text string to the screen. 
	void HUD::RenderString(float x, float y, void *font, const char* string)
	{  
	  char *c;

	  const unsigned char* string2 = (const unsigned char*)string;

	  glColor3f(0.0, 0.0, 0.0); // black
	  glRasterPos2f(x, y);
	  glutBitmapString(font, string2);
	} 

	// Display the main sections for the HUD
	void HUD::displayHUD() {
		// The health of the player will be available to the controller.
		RenderString(m_width - 150, m_height - 50, GLUT_BITMAP_TIMES_ROMAN_24, "Health");
		// The current Weapon equipped by the player.
		RenderString(m_width - 150, m_height - 200, GLUT_BITMAP_TIMES_ROMAN_24, "Weapon");
		// The current item equipped by the player
		RenderString(m_width - 150, m_height - 250, GLUT_BITMAP_TIMES_ROMAN_24, "Inventory");
		
	}


