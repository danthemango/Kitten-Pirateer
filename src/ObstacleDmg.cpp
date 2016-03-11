// **********************************************
// Filename: ObstacleDmg.cpp
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
//    
// ************************************************

#include "../hdr/ObstacleDmg.h"

ObstacleDmg::ObstacleDmg(int x, int y, int w, int h, int dmg)
	: Obstacle(x,y,w,h,DMGCONDITION) , m_dmg(dmg) {}
