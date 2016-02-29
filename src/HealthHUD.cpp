/*
File: HealthHUD.cpp
Author: Benjamin Smith
Purpose:
	Display the health stats of the players health to the HUD
*/

#include "../hdr/HealthHUD.h"

// Display the health of the player to the screen. 	
void HealthHUD::displayHUD() {
	HUD::RenderString(HUD::m_width - 150, HUD::m_height - 75, GLUT_BITMAP_TIMES_ROMAN_24 , HealthHUD::m_printHealth);

	/*
	Future implentations:
		display affliction sprite for the infected player
	*/
}

