//******************************************//
//********** Title: FireBall.h    **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//**********   Handles Fireball   **********//
//**********   spell, inherits    **********//
//**********   from Spell.h and   **********//
//**********   Projectile.h       **********//
//******************************************//

#ifndef FIRE_BALL_H_
#define FIRE_BALL_H_

#include "Spell.h"
#include "Projectile.h"

// DrJ Multiple Inheritance
/*
 * Multiple inheritance is a feature of some object-oriented computer 
 * programming languages in which an object or class can inherit 
 * characteristics and features from more than one parent object or 
 * parent class. It is distinct from single inheritance, where an 
 * object or class may only inherit from one particular object or 
 * class.
 * 
 * It is different from single inheritance since it takes properties
 * and functions from each of the parents.
 * 
 * Not all OO programming languages support both: java does not.
 * 
 * If a method was called on object that it did not understand, in 
 * which order would the classes be checked for that method?
 * I'm pretty sure it would look at Spell in my case first. Which ever
 * is defined in the inheritance first.
 * 
 * The "diamond problem" (sometimes referred to as the "deadly diamond 
 * of death") is an ambiguity that arises when two classes B and C
 * inherit from A, and class D inherits from both B and C. If there is
 * a method in A that B and C have overridden, and D does not override 
 * it, then which version of the method does D inherit: that of B, or 
 * that of C?
 * 
 * in C++ I provided projectile to virtual inherit from Weapon, same 
 * with spell, this way I got around the diamond problem.
 * (it only creates one instance to use instead of two instances of the
 * same thing.
 * 
 */



class FireBall: public Spell, public Projectile {
	protected:
		FireBall *ball;
	
	public:
		void use();
		
		using  Projectile::display;

		FireBall(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d);
		~FireBall(){};
		
};

#endif
