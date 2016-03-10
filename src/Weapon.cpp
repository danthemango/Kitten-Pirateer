//******************************************//
//********** Title: Weapon.cpp    **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//******************************************//


#include "../hdr/Weapon.h"
#include "../hdr/Items.h"
#include "../hdr/Game.h"
#include "../hdr/ImageLoader.h"
#include "../hdr/Player.h"
#include "../hdr/ItemHandler.h"
//#include "../hdr/ZombieHandler.h"
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>

//to be completed for final project
/*
void Weapon::display()
{

}
*/
	
void Weapon::pickUp()
{	
	int PlayerX = Player::getInstance().getX();
   int PlayerY = Player::getInstance().getY();
   int PlayerWidth = Player::getInstance().getWidth();
   int PlayerHeight = Player::getInstance().getHeight();
   
   if(PlayerX + PlayerWidth > m_x && PlayerX < m_x + m_itemWidth && 
      PlayerY + PlayerHeight > m_y && PlayerY < m_y + m_itemWidth &&
      Player::getInstance().getTile() == m_tilePos){
      if(m_displayed == true){//if Item hasn't been picked up yet
         ItemHandler::getInstance().addWeaponToInv(this);
			m_displayed = false;
		}
	}
}

void Weapon::use()
{
	int playerX = Player::getInstance().getX();
	int playerY = Player::getInstance().getY();
	int playerWidth = Player::getInstance().getWidth();
	int playerHeight = Player::getInstance().getHeight();
  

   
	int direction = Player::getInstance().getDirection();
   
	switch (direction){
		case 0:
			//up
			ZombieHandler::getInstance().attacked(playerX, playerY+playerHeight, playerX + playerWidth, playerY + m_range, m_damage);                      
			break;
		case 1:
			//right
			ZombieHandler::getInstance().attacked(playerX + playerWidth, playerY, playerX + m_range, playerY + playerHeight, m_damage);
			break;
		case 2:
			//down
			ZombieHandler::getInstance().attacked(playerX, playerY - m_range, playerX + playerWidth, playerY, m_damage);
			break;
		case 3:
			//left
			ZombieHandler::getInstance().attacked(playerX - m_range, playerY, playerX, playerY + playerHeight, m_damage);
			break;
	}
}

Weapon::Weapon(int id, int x, int y, std::string name, bool display, int r, int tile, int type, int d)
{  
   m_damage = d;
   m_range = r;
   m_itemID = id;
   m_name = name, 
   m_type = type;
   m_amount = 1;
   m_displayed = display;
   m_itemWidth = 20;
   m_x = x;
   m_y = y;
   m_tilePos = tile;
   m_itemTexture = ImageLoader::LoadTexture("./imgs/lemon.png");

}
