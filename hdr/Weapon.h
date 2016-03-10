//******************************************//
//********** Title: Weapon.h      **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//******************************************//


#ifndef WEAPON_H_
#define WEAPON_H_

#include "ItemObject.h"
#include <string>

class Weapon: public ItemObject{
	public:	
		virtual void use();
		
		void pickUp();
		
		Weapon(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d);
		Weapon(){};
		~Weapon(){};
};

#endif
