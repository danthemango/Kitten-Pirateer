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
#include <cstring>


class HealthHUD : public HUD { 
	
	private:
		int m_health; // health amount of the player
		std::string m_healthString; // String to convert player health to be printed to HUD
		const char * m_printHealth;

	public:
		HealthHUD(int m_width, int m_height) {}; // Constructor

		void displayHUD(); // Display health of the player
};

#endif // !HEALTHHUD_H
