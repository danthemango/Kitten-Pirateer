// Author:   Anand Sundar
// Class:    CSCI 331
// Project:  Kitty Pirateer
//
// Purpose:
//     Player functionality implementation
//


// constructor to initialize the variables

#include "../hdr/Player.h"
#include "../hdr/Jukebox.h"
#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GL/freeglut.h>
#include <iostream>

#include "../hdr/ImageLoader.h" 
#include "../hdr/Game.h"

Player::Player()
{
  m_health =100; //full health when the singleton is created
  m_x = PLAYER_START_X; //start X-pos of player
  m_y = PLAYER_START_Y; //start Y-pos of player
  stopup=stopdown=stopleft=stopright=false;
  m_arraypos = 0;
  m_speed = PLAYER_SPEED;
  c_up=c_down=c_left=c_right=false;
  m_stepSize = 4;
}

//player singleton
static Player Player:: &getInstance()
{
   static Player *instance = new Player;
   return *instance;
}

int Player::getHealth()
{
   return m_health;        
}
//returns the player height 
int Player:: getHeight() 
{
   return SPRITE_SIZE_Y;
}
//returns the player width
int Player::getWidth()
{
   return SPRITE_SIZE_X;
}

//returns the player direction used by robert
int Player::getDirection()
{
   return m_direction;
}
void Player::init()
{
   m_PlayerTexture = ImageLoader::LoadTexture("./imgs/Up.png");   
}

void Player::update()
{
   displayTexture();
}

void Player::addHealth(int addHealth)
{
   if(m_health < 100 ) 
   {
      m_health+= addHealth;
      if(m_health == 100)
      {
         m_health = 100;
      } 
   }
}
void Player::displayTexture()
{
   //draw the player
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
   glBindTexture (GL_TEXTURE_2D, m_PlayerTexture);
   ImageLoader::rectangle(m_x,m_y, 50, 50);
   glDisable(GL_TEXTURE_2D);
   glFlush();
}

void Player::collision(int xpos, int ypos, int width, int height, int cond)
{
   //send the player position to the itemhandler and store the returned bool value and do
   //the check

   //bool check = ItemHandler::getInstance().
   if(m_x+m_width > xpos && m_x < xpos + width && m_y+m_height > ypos && m_y < ypos+height){
	   if(cond == 0){   
	      if(c_up){
      	   m_y -=m_stepSize;
         }
         if(c_right){
      	   m_x -=m_stepSize;
         }
         if(c_down){
      	   m_y +=m_stepSize;
         }
         if(c_left){
      	   m_x +=m_stepSize;
         }
      }else if(cond == 1){
         m_speed = 0.5;
      }
	}else{
	   m_speed = 1;
	}
	
   if(m_x+m_stepSize+m_size > xpos && m_x < xpos + width
      && m_y+m_size > ypos && m_y < ypos+height){
      stopright = true;
      m_x -=m_stepSize;
   }else if(m_x+m_size > xpos && m_x-m_stepSize < xpos + width
      && m_y+m_size > ypos && m_y < ypos+height){
      stopleft = true;
      m_x+=m_stepSize;
   }else if(m_y-m_stepSize < ypos+height  && m_y > ypos
      && m_x +m_size > xpos && m_x < xpos+width){
      stopdown = true;
      m_y+=m_stepSize;
   }else if(m_y+m_size+m_stepSize> ypos && m_y < ypos+height
      && m_x+m_size > xpos && m_x < xpos+width){
      stopup = true;
      m_y-=m_stepSize;
   }else{
      stopright = false;
      stopleft = false;
      stopup = false;
      stopdown = false;
   }

}

void Player::update()
{
   ZombieHandler::getInstance().update(m_x,m_y);

   //code from collision detection lab
   int size = MapHandler::getInstance().getNumObstacles();
   Obstacle* ob;
   ob = MapHandler::getInstance().getObstacles();
  
   for(int i=0;i<size;i++){
      int xpos = ob[i].getX();
      int ypos = ob[i].getY();
      int width = ob[i].getW();
      int height = ob[i].getH();
      int cond = ob[i].getC();

      collisions(xpos, ypos, width, height, cond);
      if(stopright == true || stopleft == true||stopup==true||stopdown==true)
      	break;   
   }

}

void Player::attacked(int x1, int y1, int x2, int y2, int damage)
{
    m_health -= 10;   

}

void Player::attack()
{
   //what to do here??
   //0 = melee attacks
   //1 = gun
   //2 = spell
   weaponId = ItemHandler::getinstance().getType(); // stores the weapon id
   int weaponDamage = ItemHandler::getinstance().getDamage() // gets the damage for the weapon
   int weaponRange = ItemHandler::getinstance().getRange();  
   int midpointx = SPRITE_SIZE_X / 2 + m_x;
   int midpointy = SPRITE_SIZE_y / 2 + m_y;
   
   switch (m_direction)
   {
      case 0://u
        float x1 = midpointx - weaponRange;
        float x2 = midpointx + weaponRange;
        float y1 = m_y + SPRITE_SIZE_Y;
        float y2 = m_y + SPRITE_SIZE_Y + 2*weaponRange;
        ZombieHandler::getInstance().attacked(x1,y1,x2,y2,weaponDamage);
        break;
      case 2://d
        float x1 = midpointx - weaponRange;
        float y1 = m_y - 2*weaponRange;
        float x2 = midpointx + weaponRange;
        float y2 = m_y;
        ZombieHandler::getInstance().attacked(x1,y1,x2,y2,weaponDamage);
        break;
      case 3://l
        float x1 = m_x - 2*weaponRange; 
        float y1 = midpointy - weponRange;
        float x2 = m_x; 
        float y2 = midpointy + weaponRange;
        ZombieHandler::getInstance().attacked(x1,y1,x2,y2,weaponDamage);
        break;
      case 1;//r
        float x1 = m_x; 
        float y1 = midpointy - weaponRange;
        float x2 = m_x + SPRITE_SIZE_X + 2*weaponRange;
        float y2 = midpointy + weaponRange;
        ZombieHandler::getInstance().attacked(x1,y1,x2,y2,weaponDamage);
        break;

   }
   
}

void Player::down ()
{
    if(!stopdown){
       m_arraypos = Game::getInstance().getArrayPos();

       if(m_y-5 <= 0)
       {
         if(Game::getInstance().getArrayPos() != 3 && Game::getInstance().getArrayPos() != 4){
                                                                                 m_arraypos +=2;
              Game::getInstance().changeScreen(m_arraypos);
              Game::getInstance().setArrayPos(m_arraypos);
              m_y = 676;
         }
        }else{
           m_y -= 4 * m_speed;
        }
     }
     m_x = m_x - m_speed; //updates the position of the player
     m_direction = 2;
     PlayerTexture= ImageLoader::LoadTexture( "./imgs/Down.bmp" );
}

void Player::up ()
{
           if(!stopup)
           {
              m_arraypos = Game::getInstance().getArrayPos();

              if(m_y+60 >= 731)
              {
                 if(Game::getInstance().getArrayPos() != 1 && Game::getInstance().getArrayPos() != 2)
                 {
                    m_arraypos-=2;
                    Game::getInstance().changeScreen(m_arraypos);
                    Game::getInstance().setArrayPos(m_arraypos);
                    m_y = 5;
                 }
              }else{
                 m_y +=4*m_speed;
              }
           }
    m_x = m_x + m_speed;
    m_direction = 0;
    m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Up.png" );
}

void Player::right ()
{
           if(!stopright)
           {
              m_arraypos = Game::getInstance().getArrayPos();
              if(m_x+55 >= 1023)
              {
                 if(Game::getInstance().getArrayPos() != 2 && Game::getInstance().getArrayPos() != 4)
                 {
                    m_arraypos +=1;
                    Game::getInstance().changeScreen(m_arraypos);
                    Game::getInstance().setArrayPos(m_arraypos);
                    m_x = 5;
                 }
              }else{
                 m_x += 4*m_speed;
              }
          }
    m_y = m_y + m_speed;
    m_direction = 1;
    m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Right.png" );
}

void Player::left ()
{
       if(!stopleft)
       {
          m_arraypos = Game::getInstance().getArrayPos();
          if(m_x-5 <= 0)
          {
             if(Game::getInstance().getArrayPos() != 3 && Game::getInstance().getArrayPos() != 1)
             {
                m_arraypos -= 1;
                Game::getInstance().changeScreen(m_arraypos);
                Game::getInstance().setArrayPos(m_arraypos);
                m_x = 968 ;
             }
          }else{
             m_x -= 4*m_speed;
          }
       }
    m_y = m_y - m_speed;
    m_direction = 3;
    m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Left.png" );
}


