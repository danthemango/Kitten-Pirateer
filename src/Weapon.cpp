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
void Weapon::update()
{

}
	
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

void Weapon::attack()
{

/*
   int playerX = Player::getInstance().getX();
   int playerY = Player::getInstance().getY();
   int playerWidth = Player::getInstance().getWidth();
   int playerHeight = Player::getInstance().getHeight();
  
   //for personal debugging
   int playerX = Game::getInstance().m_myPlayer.getX();
   int playerY = Game::getInstance().m_myPlayer.getY();
   int playerWidth = Game::getInstance().m_myPlayer.getWidth();
   int playerHeight = Game::getInstance().m_myPlayer.getHeight();
   
   /* for later use
   bool up = Player::getInstance().getUp();
   bool left = Player::getInstance().getLeft();
   bool right = Player::getInstance().getRight();
   bool down = Player::getInstance().getDown();
   
   //int direction = Player::getInstance().getDirection();
   int direction = Game::getInstance().m_myPlayer.getDirection();
   
   switch (direction){
      case 0:
         //up
         //ZombieHandler::getInstance().attacked(playerX, playerY+playerHeight, playerX + playerWidth, playerY + m_range, m_damage);                      
         std::cout << "up: " << m_damage << std::endl;                  
         break;
      case 1:
         //right
         //ZombieHandler::getInstance().attacked(playerX + playerWidth, playerY, playerX + m_range, playerY + playerHeight, m_damage);
         std::cout << "right: " << m_damage << std::endl;                          
         break;
      case 2:
         //down
         //ZombieHandler::getInstance().attacked(playerX, playerY - m_range, playerX + playerWidth, playerY, m_damage);
         std::cout << "down: " << m_damage << std::endl;                       
         break;
      case 3:
         //left
         //ZombieHandler::getInstance().attacked(playerX - m_range, playerY, playerX, playerY + playerHeight, m_damage);
         std::cout << "left: " << m_damage << std::endl;
         break;
   }
    
   */
   /*
   if (up && right){
      //coordinates of upright area
   }else if(up && left){
      //coordinates of upleft area
   }else if(down && right){
      //coordinates of down right
   }else if( down && left){
      // coordinates of down left
   }

   */
   

}
      //Weapon(int id, int x, int y, std::string name, bool pickup, int r, int type, int d);
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
