//******************************************//
//********** Title: ItemsFactory.h**********//
//********** Author: Robert Dunn  **********//
//******************************************//

#include "../hdr/ItemsFactory.h"
#include "../hdr/Items.h"
#include "../hdr/Weapon.h"
#include "../hdr/ItemObject.h"
#include "../hdr/AOESpell.h"
#include "../hdr/FireBall.h"
#include "../hdr/Boomerang.h"
#include "../hdr/Bomb.h"
#include <string>
#include <iostream>


ItemObject *ItemsFactory::createItem(int id, int x, int y, std::string name, int r, int tilepos, int type, int d)
{
	if(id >= 0 && id <10){
		switch (id){
			case 0:
				return new Weapon(id, x, y, name, true, r, tilepos, type, d);
				break;
			case 1:
				return new AOESpell(id, x, y, name, true, r, tilepos, type, d);
				break;
			case 2:
				return new FireBall(id, x, y, name, true, r, tilepos, type, d);
				break;
			case 3:
				return new Boomerang(id, x, y, name, true, r, tilepos, type, d);
				break;
		}
		
	}else if(id >=10 && id <=19){
		if(id == 13){
		return new Bomb(id, x, y, name, false, r, tilepos);
	}else{
		return new Items(id, x, y, name, true, r, tilepos);
	}
	}
	
	
}
