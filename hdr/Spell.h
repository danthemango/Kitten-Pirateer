#ifndef SPELL_H_
#define SPELL_H_

#include "Weapon.h"

class Spell: public Weapon {
	public:
		virtual void use()=0;
		
		Spell(){};
		~Spell(){};
};
#endif
