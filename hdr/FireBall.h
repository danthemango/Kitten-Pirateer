#ifndef FIRE_BALL_H_
#define FIRE_BALL_H_

#include "Spell.h"

class FireBall: public Spell {
	public:
		void use();
		
		FireBall(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d);
		~FireBall(){};
		
};

#endif
