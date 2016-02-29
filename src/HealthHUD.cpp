/*
File: HealthHUD.cpp
Author: Benjamin Smith
Purpose:
	Display the health stats of the players health to the HUD
*/

#include "../hdr/HealthUD.h"

HealthHUD::HealthHUD() {

	// The value which the health of the player wil be contained in.
	m_health = PC::getInstance().getHealth();
	healthString = std::to+string(health);

}

// Display the health of the player to the screen. 	
void displayHUD() {
	HUD::RenderString(m_width - 150, m_height - 75, GLUT_BITMAP_TIMES_ROMAN_24 , healthString)

	/*
	Future implentations:
		display affliction sprite for the infected player
	*/
}

