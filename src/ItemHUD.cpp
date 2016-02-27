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

	static count;
	

	Item currWeapon = ItemHandler::getInstance().getWeapon();
	string weaponName = currWeapon.getName();

	Item curItem = ItemHandler::getInstance().getItem();
	string itemName = currItem.getName();
	int itemAmount = currItem.getAmount();

	void displayHUD() {
		RenderString(m_width - 150, m_height - 225, GLUT_BITMAP_TIMES_ROMAN_24, weaponName);
		RenderString(m_width - 150, m_height - 275, GLUT_BITMAP_TIMES_ROMAN_24, itemName);
		RenderString(m_width - 100, m_height - 275, GLUT_BITMAP_TIMES_ROMAN_24, itemAmount);

		
}



