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
	Game::getWidth() = m_width;
	Game::getHeight() = m_height;
//	pc::check_pc_ammo(
	if (glutLayerGet(GLUT_OVERLAY_POSSIBLE)) {
		void glutEstablishOverlay();
	}
}

void Game::RenderString(float x, float y, void *font, const char* string)
{  
  char *c;

  const unsigned char* string2 = (const unsigned char*)string;

  glColor3f(1.0, 0.0, 0.0); 
  glRasterPos2f(x, y);

  glutBitmapString(font, string2);
} 

void displayHUD() {

}
