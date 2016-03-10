//******************************************//
//********** Title: Boomerang.h   **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//**********   Handles how wepaon **********//
//**********   boomerang is used. **********//
//**********   Picks up Items     **********//
//******************************************//

#ifndef BOOMERANG_H_
#define BOOMERANG_H_

#include "Projectile.h"

class Boomerang: public Projectile {
	private:
		bool m_atRange;
	
	public:
		void displayProjectileMove();
		void use();
		
		Boomerang(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d);
		Boomerang(){};
		~Boomerang(){};
};



#endif
