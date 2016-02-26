/*
File: HUD.h
Author: Benjamin Smith
Purpose: 
	HUD implements a overlay view over the main game screen that 
	displays information about the player's health, weapon equipped,
	ammunition, and minimap. As the player moves, gets hit, and uses ammunition,
	the values shall be adjusted accordingly giving the controller feedback
	on their character. 
*/

#pragma once
#ifndef HUD_H
#define HUD_H

#include <cstring>

#include "../hdr/Game.h"
//#include "../hdr/PC.h"
#include <GL/glut.h>

class HUD {

	protected:
		
	private:
		float m_width, m_height;

	public:
		HUD(int width, int height) {
			m_width = width;
			m_height = height;
			if (glutLayerGet(GLUT_OVERLAY_POSSIBLE)) {
				void glutEstablishOverlay();
			}

		} // Default constructor. 

		// ~HUD(); // Don't implement: using singleton.
		void RenderString(float x, float y, void *font, const char* string);
		void displayHUD();
		
};

#endif // !HUD_H

