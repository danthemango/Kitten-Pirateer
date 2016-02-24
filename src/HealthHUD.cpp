/*

*/

#include "../hdr/HUD.h"

class HealthHUD : HUD {

	void displayHUD() {
		RenderString(m_width-50, m_height-50, GLUT_BITMAP_TIME_ROMAN_24, "Health");
	}

};
