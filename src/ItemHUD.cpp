/*
File: ItemHUD.cpp
Author: Benjamin Smith
Purpose:
	Handles the updating of items displayed in the HUD. This includes
	the current weapon and the inventory items the player currently has. 
*/

#include "../hdr/ItemHUD.h"

ItemHUD::ItemHUD()  {
			// Current weapon the player is using/has equipped.
			Item currWeapon = ItemHandler::getInstance().getWeapon();
			// Get the weapon name to be printed to the HUD.
			string weaponName = currWeapon.getName();

			// Current item being equipped to the player
			Item currItem = ItemHandler::getInstance().getItem();
			// Current item name
			string itemName = currItem.getName();
			// The amount of the item currently equipped.
			int itemAmount = currItem.getAmount();	
		}; 
// Display the weapon and inventory contents
/*
To be completed for final: display all items and sprites of items within the inventory
*/
void ItemHUD::displayHUD() {
	// Display the equipped weapon name to the HUD
	HUD::RenderString(m_width - 150, m_height - 225, GLUT_BITMAP_TIMES_ROMAN_24, weaponName);
	// Display the current item in inventory to the HUD
	HUD::RenderString(m_width - 150, m_height - 275, GLUT_BITMAP_TIMES_ROMAN_24, itemName);
	// Display the current item amount to the HUD
	HUD::RenderString(m_width - 100, m_height - 275, GLUT_BITMAP_TIMES_ROMAN_24, "X"+itemAmount);
}
