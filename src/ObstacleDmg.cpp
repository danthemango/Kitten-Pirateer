// **********************************************
// Filename: ObstacleDmg.cpp
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//    
// ************************************************

#include "../hdr/ObstacleDmg.h"
#include "../hdr/Player.h"




ObstacleDmg::ObstacleDmg(int x, int y, int w, int h, int dmg)
{
   	m_x = x;
   	m_y = y;
   	m_width = w;
   	m_height = h;
	m_cond = DMGCONDITION;
  	m_dmg = dmg;
}
