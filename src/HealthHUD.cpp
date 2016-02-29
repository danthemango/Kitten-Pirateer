/*
File: HealthHUD.cpp
Author: Benjamin Smith
Purpose:
	Display the health stats of the players health to the HUD
*/

#include "../hdr/HealthHUD.h"

// Display the health of the player to the screen. 	
void HealthHUD::displayHUD() {
    
    m_health = Game::getInstance().m_myPlayer.getHealth();
	m_healthString = std::to_string(m_health);
    m_printHealth = m_healthString.c_str();

    // The health of the player will be available to the controller.

	RenderString(m_width - 150, m_height - 50, GLUT_BITMAP_TIMES_ROMAN_24, "Health");
	RenderString(m_width - 150, m_height - 75, GLUT_BITMAP_TIMES_ROMAN_24 , m_printHealth);

	/*
	Future implentations:
		display affliction sprite for the infected player
	*/
}

