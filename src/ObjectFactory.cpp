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





#include "../hdr/Obstacle.h"
#include "../hdr/ObstacleDmg.h"
#include "../hdr/ObstacleSlow.h"
#include "../hdr/ObjectFactory.h"
#include <iostream>



	
Obstacle ObjectFactory::createObstacle(int x, int y, int w, int h, int obsType) {
		switch (obsType) {
		case 0: return Obstacle(x,y,w,h);
		case 1: return ObstacleDmg(x,y,w,h,1);
		case 2: return ObstacleSlow(x,y,w,h,1);
		};
	}




