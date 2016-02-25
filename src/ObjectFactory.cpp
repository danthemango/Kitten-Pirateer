// **********************************************
// Filename: ObstacleFactory.cpp
// Author: Nathan Hogman
// Date: 2016-02-22
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//    
// ************************************************





#include "Obstacle.h"
#include "ObstacleDmg.h"
#include "ObstacleSlow.h"

class ObstacleFactory: public GameObject {

public:
	
static unique_ptr<Obstacle> createObstacle(int x, int y, int w, int h, int obsType) {
		switch (obsType) {
		case 0: return make_unique<Obstacle>(x,y,w,h);
		case 1: return make_unique<ObstacleDmg>(x,y,w,h,1);
		case 2: return make_unique<ObstacleSlow>(x,y,w,h,1);
		};
	}
};



