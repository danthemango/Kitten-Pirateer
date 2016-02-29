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
        // values used to store the game width and height.
		int m_width, m_height;
       		
	private:
// Default constructor for HUD
		
	public:
         HUD();
				
		// ~HUD(); // Don't implement: using singleton.
		// Create string to be printed to the overlay
		void RenderString(float x, float y, void *font, const char* string);
		// Display the primary labels for the HUD - subclasses will override.
		virtual void displayHUD() = 0;	
		// Display minimap for the player
		void minimap(); // not yet implemented.	
};

#endif // !HUD_H

