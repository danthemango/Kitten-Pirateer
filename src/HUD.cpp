/*

File: src/HUD.cpp
Author: Benjamin Smith
Purpose: 
	This superclass for the HUD function allows for the implementation of an overlain
	view window to the main window that encompasses the characters current health
	and weapon information. 

*/

#include "../hdr/HUD.h"

HUD::HUD() {
	// get the game width
	Game::getWidth() = m_width;
	// get the game height
	Game::getHeight() = m_height;
	// implement an overlay for the HUD so it doesnt affect the undlerlying game
	if (glutLayerGet(GLUT_OVERLAY_POSSIBLE)) {
		void glutEstablishOverlay();
	}
}

// Prints strings onto the screen
void Game::RenderString(float x, float y, void *font, const char* string)
{  
  char *c;

  const unsigned char* string2 = (const unsigned char*)string;

  glColor3f(0.0, 0.0, 0.0); // black
  glRasterPos2f(x, y);
  glutBitmapString(font, string2);
} 

// Function to be overwritten by subclasses. 
void displayHUD() {

}
