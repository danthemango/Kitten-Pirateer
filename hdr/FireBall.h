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
