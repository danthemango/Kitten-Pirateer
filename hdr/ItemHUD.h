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

#include <string>

#include "../hdr/HUD.h"
#include "../hdr/Items.h"
#include "../hdr/ItemHandler.h"

class ItemHUD : public HUD {
	
	private:
		// iterator used to count through an array containing all the items in the 
		// inventory of the player to be printed to the screen
		static int count;
		// Name of the current weapon equipped.
		const char * weaponName;
		// Name of the current item equipped
		const char * itemName;
		// Amount of the current item equipped
		int itemAmount;
        const char * amount;

	protected:
	
	public:
		ItemHUD(int m_width, int m_height) {}; // Default Constructor

		void displayHUD(); // Display all the weapon and items associated with the player
};

#endif
