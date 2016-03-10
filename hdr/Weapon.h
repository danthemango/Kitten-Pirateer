//******************************************//
//********** Title: Weapon.h      **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//**********   Creates basic      **********//
//**********   weapon, like sword **********//
//******************************************//


#ifndef WEAPON_H_
#define WEAPON_H_

#include "ItemObject.h"
#include <string>

class Weapon: public ItemObject{
	public:	
		virtual void use();
		
		void pickUp(int x, int y);
		
		Weapon(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d);
		Weapon(){};
		~Weapon(){};
};

#endif
