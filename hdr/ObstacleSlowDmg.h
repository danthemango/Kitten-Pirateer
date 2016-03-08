// **********************************************
// Filename: ObstacleSlowDmg.h
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: child class of obstacle that will also cause the Character that is in 
// contact with it to be slowed when moving through it. So this obstacle will not 
// stop a character from passing through, but will hinder its movement
//    
// ************************************************



#ifndef OBSTACLESLOWDMG_H_
#define OBSTACLESLOWDMG_H_
#define SLOWDMGCOND 3

#include "ObstacleSlow.h"
#include "ObstacleDmg.h"

class ObstacleSlowDmg: public ObstacleSlow , public ObstacleDmg 
{

private:
	int m_x, m_y, m_width, m_height;
	int m_slow, m_dmg;
	int m_cond;

public:
	void update (){};
	void display (){};
	bool collide (Player *C){};
	ObstacleSlowDmg(int x, int y, int w, int h, int slow, int dmg);
	~ObstacleSlowDmg(){};

};

#endif 
