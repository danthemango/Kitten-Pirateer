#ifndef SPELL_H_
#define SPELL_H_

#include "Weapon.h"

class Spell: virtual public Weapon {
	protected:
		int m_element; //0=fire,1=water
	
	public:
		virtual void use()=0;
		int getElement(){return m_element;}
		
		Spell(){};
		~Spell(){};
};
#endif
