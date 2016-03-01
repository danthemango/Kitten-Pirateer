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
    // Get the weapon name to be printed to the HUD.
	weaponName = ItemHandler::getInstance().getWeapon()->getName().c_str();
    
    // Current item being equipped to the player
    //Items currItem;
	// Current item name
	itemName = ItemHandler::getInstance().getItem()->getName().c_str();
	// The amount of the item currently equipped.
    itemAmount = ItemHandler::getInstance().getItem()->getAmount();
    std::string stringAmount = std::to_string(itemAmount);
    amount = stringAmount.c_str();
   // amount = std::to_string(itemAmount).c_str();
	// The current Weapon equipped by the player.
	HUD::RenderString(m_width+60, m_height-660, GLUT_BITMAP_TIMES_ROMAN_24, "Weapon");
	// Display the equipped weapon name to the HUD
	HUD::RenderString(m_width +65, m_height - 690, GLUT_BITMAP_TIMES_ROMAN_24, weaponName);
	// The current item equipped by the player
	RenderString(m_width +60, m_height - 816, GLUT_BITMAP_TIMES_ROMAN_24, "Inventory");
	// Display the current item in inventory to the HUD
	HUD::RenderString(m_width +65, m_height - 846, GLUT_BITMAP_TIMES_ROMAN_24, itemName);
	// Display the current item amount to the HUD
	HUD::RenderString(m_width + 95, m_height - 871, GLUT_BITMAP_TIMES_ROMAN_24, amount);
	
	
	
}
