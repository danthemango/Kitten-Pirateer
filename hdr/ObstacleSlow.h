// **********************************************
// Filename: ObstacleSlow.h
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//	A type of obstacle that hinders the players movement
// ************************************************



#ifndef OBSTACLESLOW_H_
#define OBSTACLESLOW_H_
#define SLOWCONDITION 1

#include "Obstacle.h"

class ObstacleSlow: virtual public Obstacle {

private:
	int m_slow;
public:
	//returns the amount of slow caused by the obstacle
	int getSLOW() {return m_slow;};
	
	ObstacleSlow(int x, int y, int w, int h, int slow);
	ObstacleSlow(){};
	~ObstacleSlow(){};

};

#endif 
