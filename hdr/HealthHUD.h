/*
File: HealthHUD.h
Author: Benjamin Smith
Purpose:
	Display the health levels of the PC and decrease/increase 
	accordingly.
*/
#pragma once
#ifndef HEALTHHUD_H
#define HEALTHHUD_H

#include "../hdr/HUD.h"
#include "../hdr/Player.h"
#include "../hdr/ImageLoader.h"
#include <cstring>

/*
DrJ -- (Data) Encapsulation:

A header file in itself is a representation of data encapsulation. The variables and 
functions are instantiated but not defined, that is left up to the corresponding
cpp file to do. 
Others can use the public methods, but have no knowledge on how these functions are 
implemented and the only information that suggests the purpose of these functions
are the function names and the proper documentation paired along with the definition. 
*/
/*
DrJ -- Inheritance:

HealthHUD is derived from the HUD class to polymorhpically implement the abstract displayHUD
function. 
A subclass can access all the non-private and protected members of its superclass (base class).
HealthHUD does not modify HUD by extends the use of the function named above to be 
associated with the HealthHUD class. HealthHUD is-a HUD object.

The method within this class is bound to this class by the use of the  class operator "::". 
*/

class HealthHUD : public HUD { 
	
	private:

      // DrJ - Instance Variables "_m"
      // Here instance variables to the object of HealthHUD are created for the class.
      // They will be implemeneted only within the HealthHUD object.

		int m_health; // health amount of the player
		std::string m_healthString; // String to convert player health to be printed to HUD
		const char * m_printHealth;
		int m_posX, m_posY; // Position of the character
      GLuint m_healthLabel = ImageLoader::LoadTexture("./imgs/HUD/1.png");
		
	public:

      // DrJ -- Constructor
      // Default constructor for the HealthHUD class
      // Definition: Default constructors are a constructor that can be called without
      // any arguements.
      HealthHUD();
		HealthHUD(int m_width, int m_height) {}; // Constructor
		~HealthHUD();

      // DrJ -- Instance Method
      // This method is implemented by HealthHUD and pertains to the specific behavior
      // of the HealthHUD class.
		void displayHUD(); // Display health of the player
};

#endif // !HEALTHHUD_H
