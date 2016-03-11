#ifndef BOMB_H_
#define BOMB_H_

#include "Items.h"

class Bomb: public Items{
	public:
		void use();
	
	
		Bomb(int id, int x, int y, std::string name, bool display, int r, int tile);
		Bomb(){};
};

#endif
