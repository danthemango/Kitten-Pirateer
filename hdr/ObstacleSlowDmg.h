// **********************************************
// Filename: ObstacleSlowDmg.h
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: A type of obstacel that will slow your movement and damage you
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

public:
	
	ObstacleSlowDmg(int x, int y, int w, int h, int slow, int dmg);
	~ObstacleSlowDmg(){};

};

#endif 
