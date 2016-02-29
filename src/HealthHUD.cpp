/*

*/

#include "../hdr/HUD.h"
#include "../hdr/Player.h"

class HealthHUD : HUD {

	// The value which the health of the player wil be contained in.
	int health = PC::getInstance().getHealth();
	std::string healthString = std::to+string(health);

};

	// Display the health of the player to the screen. 	
	void displayHUD() {
		HUD::RenderString(m_width - 150, m_height - 75, GLUT_BITMAP_TIMES_ROMAN_24 , healthString)
	}
