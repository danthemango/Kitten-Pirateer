/*
File: HealthHUD.h
Author: Benjamin Smith
Purpose:
	Display the health levels of the PC and decrease/increase 
	accordingly.
*/
#pragma once
#ifndef HEALTHHUD_H
#define HEALTHHUD_H

#include "../hdr/HUD.h"
#include "../hdr/Player.h"

class HealthHUD : public HUD { 
	
	private:
		int m_health; // health amount of the player
		std::string healthString; // String to convert player health to be printed to HUD

	public:
		HealthHUD(); // Constructor - singleton
		// ~HealthHUD(); // Destructor not required: singleton
		void displayHUD(); // Display health of the player
};

#endif // !HEALTHHUD_H
