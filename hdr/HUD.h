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
#include <GL/glut.h>

class HUD {

	protected:
		friend class HealthHUD;
		friend class ItemHUD;
	private:
		
	public:
		// values used to store the game width and height.
		static int m_width, m_height;
		// Default constructor for HUD
		HUD(int width, int height) {
			m_width = width;
			m_height = height;
			// Create an overlay view over the main game as not to disrupt the primary functions of the game
			// Can be later implepented to be turned off through settings
			if (glutLayerGet(GLUT_OVERLAY_POSSIBLE)) {
				void glutEstablishOverlay();
			}
		}  
		// ~HUD(); // Don't implement: using singleton.
		// Create string to be printed to the overlay
		void RenderString(float x, float y, void *font, const char* string);
		// Display the primary labels for the HUD - subclasses will override.
		void displayHUD();	
		// Display minimap for the player
		void minimap(); // not yet implemented.	
		
};

#endif // !HUD_H

