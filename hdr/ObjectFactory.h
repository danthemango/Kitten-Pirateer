// **********************************************
// Filename: ObjectFactory.h
// Author: Nathan Hogman
// Date: 2016-02-22
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//	Used to create the various types of obstacles needed in the game
// 
//    
// ************************************************



#ifndef OBJECTFACTORY_H_
#define OBJECTFACTORY_H_

#include "Obstacle.h"
#include "ObstacleSlow.h"
#include "ObstacleDmg.h"
#include "ObstacleSlowDmg.h"

class ObjectFactory 
{
private:
	
	
    
public:
	
	// ObsType that is passed into the Factory is associated as this:
	// 	0: 	Obstacle
	//	1:	Slowing Obstacle
	// 	2:	Damaging Obstacle
	//	3:	Slow and Damaging Obstacle
	
	static Obstacle createObstacle(int x, int y, int w, int h, int obsType);

	ObjectFactory(){};
	~ObjectFactory(){};
	
};

#endif 
