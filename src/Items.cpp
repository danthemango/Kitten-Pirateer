//******************************************//
//********** Title: Items.cpp     **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//******************************************//

#include "../hdr/Player.h"
#include "../hdr/ImageLoader.h"
#include "../hdr/Items.h"
#include "../hdr/Game.h"
#include "../hdr/Jukebox.h"

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string>
#include <iostream>
//REMOVE
//#include "Player.h"

class ImageLoader;

//void Items::pickUp(Items* item)
void Items::pickUp()
{  
   //temp x, y and size for Player to keep code cleaner
   
   //REMOVE Comments
   int PlayerX = Player::getInstance().getX();
   int PlayerY = Player::getInstance().getY();
   int PlayerWidth = Player::getInstance().getWidth();
   int PlayerHeight = Player::getInstance().getHeight();
   /*
         //following was used for testing
   int PlayerX = Game::getInstance().m_myPlayer.getX();
   int PlayerY = Game::getInstance().m_myPlayer.getY();
   int PlayerWidth = Game::getInstance().m_myPlayer.getWidth();
   int PlayerHeight = Game::getInstance().m_myPlayer.getHeight();
  */
   //checks if item is colliding with Player
   if(PlayerX + PlayerWidth > m_x && PlayerX < m_x + m_itemWidth && 
      PlayerY + PlayerHeight > m_y && PlayerY < m_y + m_itemWidth &&
      //Game::getInstance().getArrayPos() == m_tilePos){
      Player::getInstance().getTile() == m_tilePos){
      if(m_displayed == true){//if Item hasn't been picked up yet
         switch (m_itemID){
            case 10://add item to inventory
               ItemHandler::getInstance().addItemToInv(this);
               Jukebox::PlaySound("./sounds/ItemPickUp.wav");
               m_displayed = false;
               break;
            case 11://heal Player
               //need a healPlayer(int x) which will add x to Player health
               
               //REMOVEComments
               //Game::getInstance().m_myPlayer.addHealth(10); 
               if(Player::getInstance().getHealth() < MAX_PLAYER_HEALTH){             
					Player::getInstance().addHealth(10);
					Jukebox::PlaySound("./sounds/HeartPickUp.wav");
					m_displayed = false;               
					}
               break;
            case 12:
               Jukebox::PlaySound("./sounds/ItemPickUp.wav");
               ItemHandler::getInstance().addItemToInv(this); 
               m_displayed = false;     
               break;            
      
         }
       
	}   
   }
}

void Items::use()
{
	switch (m_itemID){
      case 12:
         if(m_amount > 0){
			if(Player::getInstance().getHealth() < MAX_PLAYER_HEALTH){
				Jukebox::PlaySound("./sounds/HealthPotionUse.wav");
				Player::getInstance().addHealth(20);
				decreaseAmount();
			}
         }
         break;
   }
}

Items::Items(int id, int x, int y, std::string name, bool display, int r, int tile)
{
   m_range = r;
   m_itemID = id;
   m_name = name;
   m_amount = 1;
   m_displayed = display;
   m_x = x;
   m_y = y;
   m_tilePos = tile;
   m_itemWidth = 20;

   //switchcase
   switch (m_itemID){
      case 10:
         m_itemTexture = ImageLoader::LoadTexture("./imgs/lemon.png");
         break;
      case 11:
         m_itemTexture = ImageLoader::LoadTexture("./imgs/heart.png");
         break;
      case 12:
         m_itemTexture = ImageLoader::LoadTexture("./imgs/healthPotion.png");
         break; 
   }
   
}

