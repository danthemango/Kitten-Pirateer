// Author:   Anand Sundar
// Class:    CSCI 331
// Project:  Kitty Pirateer
//
// Purpose:
//     Player functionality implementation
//


// constructor to initialize the variables

#include "Player.h"
#include "Jukebox.h"
#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GL/freeglut.h>
#include <iostream>

#include "ImageLoader.h" 
#include "Game.h"

Player::Player()
{
  m_health =100; //full health when the singleton is created
  m_x = PLAYER_START_X; //start X-pos of player
  m_y = PLAYER_START_Y; //start Y-pos of player
  stopup=stopdown=stopleft=stopright=false;
  m_arraypos = 0;
  m_speed = 1;
  c_up=c_down=c_left=c_right=false;



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
int getHeight() 
{
   return SPRITE_SIZE_Y;
}
//returns the player width
int getWidth()
{
   return SPRITE_SIZE_X;
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

void Player::attack()
{
   //what to do here??
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
    m_direction = 3;
    m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Left.png" );
}
