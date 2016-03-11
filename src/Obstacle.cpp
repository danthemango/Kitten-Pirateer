// **********************************************
// Filename: Obstacle.cpp
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer 
//    
// ************************************************

#include "../hdr/Obstacle.h"

Obstacle::Obstacle(int x, int y, int w, int h, int cond)
	: m_x(x) , m_y(y) , m_width (w) , m_height (h) , m_cond(cond) {}
