// **********************************************
// Filename: ObstacleSlow.h
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



#ifndef OBSTACLESLOW_H_
#define OBSTACLESLOW_H_
#define SLOWCONDITION 1

#include "Obstacle.h"

class ObstacleSlow: public Obstacle {

private:
	int m_x, m_y, m_width, m_height;
	int m_slow;

public:
	void update (){};
	void display (){};
	bool collide (Player *C){};
	ObstacleSlow(int x, int y, int w, int h, int slow);
	~ObstacleSlow(){};

};

#endif 
