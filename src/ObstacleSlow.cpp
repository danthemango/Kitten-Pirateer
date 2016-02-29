// **********************************************
// Filename: ObstacleSlow.cpp
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//
// ************************************************

#include "../hdr/ObstacleSlow.h"
#include "../hdr/Player.h"




ObstacleSlow::ObstacleSlow(int x, int y, int w, int h, int slow)
{
   m_x = x;
   m_y = y;
   m_width = w;
   m_height = h;
   m_slow = slow;
}
