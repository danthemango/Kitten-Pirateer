#ifndef FIRE_BALL_H_
#define FIRE_BALL_H_

#include "Spell.h"
#include "Projectile.h"

class FireBall: public Spell, public Projectile {
	protected:
		FireBall *ball;
		//using Spell::m_range;//range of item 0 if N/A
		//using Spell::m_name;
		//using Spell::m_amount;
		//using Spell::m_invslot; //which inventory slot
                     //item is currently in
		//using Spell::m_itemID;  //item id states which
                     //type of item it is    
		//using Spell::m_displayed; //bool to see if item has been picked up
		//using Spell::m_tilePos; //which tile item is in
		//using Spell::m_x;//Xposition of item, -1 if N/A
		//using Spell::m_y;//YPosition of item, -1 if N/A
		//using Spell::m_itemWidth;
		//using Spell::m_damage;  //weapon damage
		//using Spell::m_type; //weapon type
                  //0:melee
                  //1:gun
                  //2:spell
      
		//using Spell::m_itemTexture;
	
	public:
		void use();
		//using Spell::pickUp;
		//using Spell::getItemID;
		//using Spell::getAmount;

		//using Spell::decreaseAmount;

		//using Spell::getRange;

		//using Spell::getName;

		//using Spell::setAmount;

		//using Spell::getDamage;

		using  Projectile::display;

		//using Spell::setDamage;

		//using Spell::getType;
      
		//using Spell::update;

		FireBall(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d);
		~FireBall(){};
		
};

#endif
