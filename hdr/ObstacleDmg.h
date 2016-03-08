// **********************************************
// Filename: ObstacleDmg.h
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: child class of obstacle that will also cause the Character that collides 
// with it to take a set amount of damage based on the obstacle type set on construction
// ************************************************

#ifndef OBSTACLEDMG_H_
#define OBSTACLEDMG_H_
#define DMGCONDITION 2

#include "Obstacle.h"

class ObstacleDmg: public Obstacle {

private:
	int m_x, m_y, m_width, m_height;
	int m_dmg;
	int m_cond;

public:
	void update (){};
	void display (){};
	bool collide (Player *C){};
	ObstacleDmg(int x, int y, int w, int h, int dmg);
	ObstacleDmg(){};
	~ObstacleDmg(){};

};

#endif 
