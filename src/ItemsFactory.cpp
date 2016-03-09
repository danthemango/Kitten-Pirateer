#include "../hdr/ItemsFactory.h"
#include "../hdr/Items.h"
#include "../hdr/Weapon.h"
#include <string>
#include <iostream>


Items *ItemsFactory::createItem(int id, int x, int y, std::string name, int r, int tilepos, int type, int d)
{
	if(id >= 0 && id <10){
		return new Weapon(id, x, y, name, true, r, tilepos, type, d);
	}else if(id >=10 && id <=19){
		return new Items(id, x, y, name, true, r, tilepos);
	}
	
	
}
