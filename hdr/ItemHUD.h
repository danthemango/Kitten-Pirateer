/*
File: ItemHUD.h
Author: Benjamin Smith
Purpose:
	Handles the updating of items displayed in the HUD. This includes
	the current weapon and the inventory items the player currently has.
	
*/
#pragma once
#ifndef ITEMHUD_H
#define ITEMHUD_H

#include <cstring>

#include "../hdr/HUD.h"
#include "../hdr/Items.h"

class ItemHUD : public HUD {
	
	private:
		// iterator used to count through an array containing all the items in the 
		// inventory of the player to be printed to the screen
		static int count;
		const char * weaponName;
		const char * itemName;
		int itemAmount;

	protected:
	
	public:
		ItemHUD() : HUD(m_width, m_height)  {
			// Current weapon the player is using/has equipped.
			Items currWeapon;
			// Get the weapon name to be printed to the HUD.
			weaponName = currWeapon.getName().c_str();

			// Current item being equipped to the player
			Items currItem;
			// Current item name
			itemName = currItem.getName().c_str();
			// The amount of the item currently equipped.
			itemAmount = currItem.getAmount();	
		}; // Default Constructor - singleton

		void displayHUD(); // Display all the weapon and items associated with the player
};

#endif
