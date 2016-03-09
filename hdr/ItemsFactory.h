#ifndef ITEMS_FACTORY_H_
#define ITEMS_FACTORY_H_

#include "../hdr/Items.h"
#include "../hdr/Weapon.h"

class ItemsFactory {
	
	public:
		static Items *createItem(int id, int x, int y, std::string name, int r, int tilepos, int type, int d);
};



#endif
