/*

*/

#include "../hdr/HUD.h"
#include "../hdr/PC.h"

class HealthHUD : HUD {

	int health = PC::getInstance().getHealth();
	void displayHUD() {
		HUD::RenderString(m_width - 150, m_height - 75, GLUT_BITMAP_TIMES_ROMAN_24 , health.c_str())
	}

};
