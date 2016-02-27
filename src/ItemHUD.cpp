/*
File: ItemHUD.cpp
Author: Benjamin Smith
Purpose:
	Handles the updating of items displayed in the HUD. This includes
	the current weapon and the inventory items the player currently has. 
*/
#include "../hdr/HUD.h"

class ItemHUD : HUD {

	Item currWeapon = ItemHandler::getInstance().getWeapon();
	string weaponName = currWeapon.getName();

	Item curItem = ItemHandler::getInstance().getItem();
	string itemName = currItem.getName();
	int itemAmount = currItem.getAmount();
}



