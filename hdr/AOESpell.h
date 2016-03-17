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
#include "ImageLoader.h"


// DrJ Constructor
/*
 * i used Weapons constructor for AOESpell, and changed the 
 * m_itemTexture for it.
 * 
 * 
 */


class AOESpell: public Spell{
	public:
		void use();
		
		AOESpell(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d)
		: Weapon(id, x, y, name, display, r, tile, type, d){
			
			m_itemTexture = ImageLoader::LoadTexture("./imgs/AOEScroll.png");
		};
		~AOESpell(){};
	
	
	
};




#endif
