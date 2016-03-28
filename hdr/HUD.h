/*
File: HUD.h
Author: Benjamin Smith
Purpose: 
	HUD implements a overlay view over the main game screen that 
	displays information about the player's health, weapon equipped,
	ammunition, and minimap. As the player moves, gets hit, and uses ammunition,
	the values shall be adjusted accordingly giving the controller feedback
	on their character. 
*/

/*
DrJ -- Header File

What functionality is provided:

The HUD object provides information to the actor that relays current status
about the character. The actor is informed of the health level of the character
as it is decreased when being attacked by zombies. It also displays any health
increases when the player recieved a heart item or uses a potion. Which brings us to
the item section of the HUD: the curent weapon is displayed and the maximum damage
capability of the weapon is listed underneath. This allows the actor to assess the 
amount of damage daelt to the zombies in return for hurting the character. Underneath
that are usable items and the quanitity listed. These items (and can be rotated, as like
the weapon) can be selected and used to benefit the player.

How did I make it easy for others to interface/use objects:

I made all the HUD objects easy to use by creating a HUDHandler object that is
a singleton to implements all the subclassed HUD classes displayHUD() function automatically.
*/

/*
DrJ -- Template Pattern
Defines a skeleton of an algorithm in an operation, deferring some steps to subclasses

HUD is a template for the HealthHUD and ItemHUD subclasses as it provides the abstract
function displayHUD() function available to be overridden and also the RednderString function
for the subclasses to implement. The subclasses define their variant parts based off of 
the HUD design and encourages code re-use. 
*/

#pragma once
#ifndef HUD_H
#define HUD_H

#include <cstring>

#include "../hdr/Game.h"
#include <GL/glut.h>

class HUD {

	protected:
        // values used to store the game width and height.
		int m_width, m_height;
       		
	private:
		
	public:

         /* DrJ - Deafault Constructor
            This is the default constructor for the HUD class
            Definition: A default constructor is a constructor that doesnt have any
            arguements.
            The default constructor is the constructor that is called when no other
            form of the class (arguments passed) is specified. It will always exists
            when an instance of this class is implemented. 
            To call a specific constructor in the superclass, you must append the superclass 
            constructor onto the end with the ':' operator of the subclass constructor. 
         */
         HUD(); // Default constructor for HUD class
				
		//~HUD(); // Don't implement: using singleton.
		// Create string to be printed to the overlay
		void RenderString(float x, float y, void *font, const char* string);

		// DrJ -- Abstraction
		// Display the primary labels for the HUD - subclasses will override.
      // Because this class contains one pure virtual function, it is considered an
      // abstract class (according to Microsoft Documentation on C++).
		virtual void displayHUD() = 0;	
		// Display minimap for the player
	//	void minimap(); // not yet implemented.	
};

#endif // !HUD_H

