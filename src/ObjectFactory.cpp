// **********************************************
// Filename: ObjectFactory.cpp
// Author: Nathan Hogman
// Date: 2016-02-22
// Class: CSCI 331
// Project: Kitty Pirateer
//    
// ************************************************

#include "../hdr/ObjectFactory.h"

Obstacle ObjectFactory::createObstacle(int x, int y, int w, int h, int obsType) 
{
		switch (obsType) {
		case 0: return Obstacle(x,y,w,h,0);
		case 1: return ObstacleDmg(x,y,w,h,1);
		case 2: return ObstacleSlow(x,y,w,h,1);
		case 3: return ObstacleSlowDmg(x,y,w,h,1,1);
		};
}




