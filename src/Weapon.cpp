//******************************************//
//********** Title: Weapon.cpp    **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//******************************************//

/*
#include "Weapon.h"
#include "Items.h"
*/
#include "../hdr/Weapon.h"
#include "../hdr/Items.h"
#include <GL/glut.h>
#include <GL/freeglut.h>

//to be completed for final project
void Weapon::display()
{

}

void Weapon::update()
{

}

Weapon::Weapon(int d, int r, int invs, int id, std::string name, int type, bool pickup,int x, int y, int tile)
{  
   m_damage = d;
   m_range = r;
   m_invslot = invs;
   m_itemID = id;
   m_name = name, 
   m_type = type;
   m_ammount = 1;
   m_pickedUp = pickup;
   m_x = x;
   m_y = y;
   m_tilePos = tile;

}
