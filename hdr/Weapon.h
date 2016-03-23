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

// DrJ Inheritance
/*
 * inheritance is when an object or class is based on another object 
 * (prototypal inheritance) or class (class-based inheritance), using 
 * the same implementation (inheriting from an object or class) 
 * specifying implementation to maintain the same behavior (realizing 
 * an interface; inheriting behavior).
 * 
 *  It is a mechanism for code reuse and to allow independent 
 * extensions of the original software via public classes and 
 * interfaces.
 * 
 * I use inheritance in pretty much all my classes. Here I inherit from
 * ItemObject, which is a template method class.
 * 
 * A method is bound during runtime.
 * 
 */


class Weapon: public ItemObject{
	public:	
		virtual void use();
		
		void pickUp(int x, int y);
		
		Weapon(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d);
		Weapon(){};
		~Weapon(){};
};

#endif
