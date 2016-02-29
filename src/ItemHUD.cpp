/*
File: ItemHUD.cpp
Author: Benjamin Smith
Purpose:
	Handles the updating of items displayed in the HUD. This includes
	the current weapon and the inventory items the player currently has. 
*/

#include "../hdr/ItemHUD.h"

// Display the weapon and inventory contents
/*
To be completed for final: display all items and sprites of items within the inventory
*/
void ItemHUD::displayHUD() {
	// Display the equipped weapon name to the HUD
	HUD::RenderString(m_width - 150, m_height - 225, GLUT_BITMAP_TIMES_ROMAN_24, ItemHUD::weaponName);
	// Display the current item in inventory to the HUD
	HUD::RenderString(m_width - 150, m_height - 275, GLUT_BITMAP_TIMES_ROMAN_24, ItemHUD::itemName);
	// Display the current item amount to the HUD
	HUD::RenderString(m_width - 100, m_height - 275, GLUT_BITMAP_TIMES_ROMAN_24, "X"+ItemHUD::itemAmount);
}
