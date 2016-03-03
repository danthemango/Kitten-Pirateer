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

void Items::setAmount(int x)
{
   m_amount = x; 
}

void Items::pickUp(Items* item)
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
      if(m_pickedUp == false){//if Item hasn't been picked up yet
         switch (m_itemID){
            case 10://add item to inventory
               ItemHandler::getInstance().addItemToInv(item);
               Jukebox::PlaySound("./sounds/ItemPickUp.wav");
               m_pickedUp = true;
               break;
            case 11://heal Player
               //need a healPlayer(int x) which will add x to Player health
               
               //REMOVEComments
               //Game::getInstance().m_myPlayer.addHealth(10); 
               if(Player::getInstance().getHealth() < MAX_PLAYER_HEALTH){             
					Player::getInstance().addHealth(10);
					Jukebox::PlaySound("./sounds/HeartPickUp.wav");
					m_pickedUp = true;               
					}
               break;
            case 12:
               Jukebox::PlaySound("./sounds/ItemPickUp.wav");
               ItemHandler::getInstance().addItemToInv(item); 
               m_pickedUp = true;     
               break;            
      
         }
       
	}   
   }
}

void Items::display()
{
   //display if character is in correct tile
   //if(Game::getInstance().getArrayPos() == m_tilePos){
   
   //REMOVE
   if(Player::getInstance().getTile() == m_tilePos){
   
      if(m_pickedUp == false){
         //draw image
         glEnable(GL_TEXTURE_2D);
   
         glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
         glBindTexture (GL_TEXTURE_2D, m_itemTexture);
         ImageLoader::rectangle(m_x, m_y, m_itemWidth, m_itemWidth);
   
         glDisable(GL_TEXTURE_2D);
         glFlush();
         
      }
   }
}

void Items::update()
{

}

Items::Items(int r, int inv, int id, std::string name,bool pickup,int x, int y, int tile)
{
   m_range = r;
   m_invslot = inv;
   m_itemID = id;
   m_name = name;
   m_amount = 1;
   m_pickedUp = pickup;
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

