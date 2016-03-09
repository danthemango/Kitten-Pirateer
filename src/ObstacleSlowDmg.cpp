// **********************************************
// Filename: ObstacleSlowDmg.cpp
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//
// ************************************************

#include "../hdr/ObstacleSlowDmg.h"
#include "../hdr/Player.h"




ObstacleSlowDmg::ObstacleSlowDmg(int x, int y, int w, int h, int slow, int dmg)
{
   	m_x = x;
   	m_y = y;
   	m_width = w;
   	m_height = h;
   	m_slow = slow;
	m_dmg = dmg;
	m_cond = SLOWDMGCOND;
}
