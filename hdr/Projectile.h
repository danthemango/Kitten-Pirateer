#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "Weapon.h"

class Projectile: virtual public Weapon {
	protected:
		Projectile* m_fireBallList[3];
		bool m_used;
		int m_lastProjectileTime;
		int m_direction;
		int m_startX;
		int m_startY;
		int m_startTile;
	
	public:
		void display();
		virtual void displayProjectileMove();
		void attack();
		
		Projectile(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d);
		Projectile(){};
		~Projectile(){};
};
#endif
