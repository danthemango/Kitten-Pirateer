/*
File: ItemHUD.cpp
Author: Benjamin Smith
Purpose:
	Handles the updating of items displayed in the HUD. This includes
	the current weapon and the inventory items the player currently has. 
*/

#include "../hdr/HUD.h"
#include "../hdr/ItemHandler.h"

class ItemHUD : HUD {

	// iterator used to count through an array containing all the items in the 
	// inventory of the player to be printed to the screen
	static count;
	
	// Current weapon the player is using/has equipped.
	Item currWeapon = ItemHandler::getInstance().getWeapon();
	// Get the weapon name to be printed to the HUD.
	string weaponName = currWeapon.getName();

	// Current item being equipped to the player
	Item curItem = ItemHandler::getInstance().getItem();
	// Current item name
	string itemName = currItem.getName();
	// The amount of the item currently equipped.
	int itemAmount = currItem.getAmount();		
}

	// Display the weapon and inventory contents
	void displayHUD() {
		// Display the equipped weapon name to the HUD
		RenderString(m_width - 150, m_height - 225, GLUT_BITMAP_TIMES_ROMAN_24, weaponName);
		// Display the current item in inventory to the HUD
		RenderString(m_width - 150, m_height - 275, GLUT_BITMAP_TIMES_ROMAN_24, itemName);
		// Display the current item amount to the HUD
		RenderString(m_width - 100, m_height - 275, GLUT_BITMAP_TIMES_ROMAN_24, "X"+itemAmount);
	}
