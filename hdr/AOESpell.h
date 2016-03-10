//******************************************//
//********** Title: AOESpell.h    **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//**********   AOE spell class    **********//
//**********   use is defined for **********//
//**********   all AOE spells     **********//
//******************************************//

#ifndef AOE_SPELL_H_
#define AOE_SPELL_H_

#include "Spell.h"

class AOESpell: public Spell{
	public:
		void use();
		
		AOESpell(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d);
		~AOESpell(){};
	
	
	
};




#endif
