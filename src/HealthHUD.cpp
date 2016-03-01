/*
File: HealthHUD.cpp
Author: Benjamin Smith
Purpose:
	Display the health stats of the players health to the HUD
*/

#include "../hdr/HealthHUD.h"
#include "../hdr/Player.h"

// Display the health of the player to the screen. 	
void HealthHUD::displayHUD() {
    
    m_health = Player::getInstance().getHealth();
	m_healthString = std::to_string(m_health);
    m_printHealth = m_healthString.c_str();

    // The health of the player will be available to the controller.

	RenderString(m_width + 70, m_height - 144, GLUT_BITMAP_TIMES_ROMAN_24, "Health");
	RenderString(m_width + 90, m_height - 175, GLUT_BITMAP_TIMES_ROMAN_24 , m_printHealth);

	/*
	Future implentations:
		display affliction sprite for the infected player
	*/
}

