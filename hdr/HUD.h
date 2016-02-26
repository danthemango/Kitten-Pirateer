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

#include "../hdr/Game.h"
#include "../hdr/pc.h"
#include <GL/glut.h>

class HUD {

	protected:
		
	private:
		GLfloat m_width, m_length;

	public:
		HUD(); // Default constructor. 
			   // ~HUD(); // Don't implement: using singleton.
		
};

#endif // !HUD_H
