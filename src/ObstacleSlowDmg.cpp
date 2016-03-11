// **********************************************
// Filename: ObstacleSlowDmg.cpp
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
//
// ************************************************

#include "../hdr/ObstacleSlowDmg.h"

ObstacleSlowDmg::ObstacleSlowDmg(int x, int y, int w, int h, int slow, int dmg) 
: ObstacleSlow(x,y,w,h,slow) , ObstacleDmg(x,y,w,h,dmg) {}
