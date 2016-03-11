// **********************************************
// Filename: ObstacleSlow.cpp
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
//
// ************************************************

#include "../hdr/ObstacleSlow.h"

ObstacleSlow::ObstacleSlow(int x, int y, int w, int h, int slow)
	: Obstacle(x,y,w,h,SLOWCONDITION) , m_slow(slow) {}
