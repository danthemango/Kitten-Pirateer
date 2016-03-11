// **********************************************
// Filename: ObstacleDmg.h
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: A type of obstacle that does damage when hit by a player
// ************************************************

#ifndef OBSTACLEDMG_H_
#define OBSTACLEDMG_H_
#define DMGCONDITION 2

#include "Obstacle.h"

class ObstacleDmg: virtual public Obstacle {

private:
	// the amount of damage done by the obstacle
	int m_dmg;
public:
	//returns the amount of damage done by the obstacle
	int getDMG() {return m_dmg;};
	
	ObstacleDmg(int x, int y, int w, int h, int dmg);
	ObstacleDmg(){};
	~ObstacleDmg(){};
};

#endif 
