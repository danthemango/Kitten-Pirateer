// ************************************************
// File:    Zombie.cpp
// Author:  Daniel Guenther
// Date:    2016-02-28
// Class:   CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//    A 'Zombie' is a NPC which slowly follows the player
//    and deals damage when close enough
// ************************************************
#include "../hdr/Zombie.h"
#include "../hdr/config.h"
#include "../hdr/Timer.h"
#include "../hdr/Player.h"

// define the directions
#define UP 0
#define DOWN 1
#define LEFT 2 
#define RIGHT 3

Zombie::Zombie()
{
   m_visible = false;
   m_speed = 1;
   m_dead = false;
   m_direction = UP;
   // this is the attack strength of the zombie
   m_damage = 5;
   m_attackRange = SPRITE_SIZE_Y /2;
   m_attackDelay = 800;
   m_animDelay = 200;
}

// determine the absolute difference between two numbers
int difference(int a, int b){
   if(a < b){
      return b - a;
   }else{
      return a - b;
   }
}

// update takes in the player's position
// this function will act as the NPC's 'AI' 
void Zombie::update(int x, int y)
{
   if(!m_visible || m_dead){
      return;
   }

   // attack the player if he's close
   if(difference(x,m_x) < m_attackRange && difference(y,m_x) < m_attackRange){
      attack();
   }

   /*
   // round down the difference between the player and zombie if zombie is close 
   if(difference(x,m_x) < m_speed){
      m_x = x;
   }
   if(difference(y,m_y) < m_speed){
      m_y = y;
   }
   */

   // follow the player
   if(x < m_x){
      m_x -= m_speed;
      m_direction = LEFT;
   }else if(x > m_x){
      m_x += m_speed;
      m_direction = RIGHT;
   }
   if(y < m_x){
      m_y -= m_speed;
      m_direction = DOWN;
   }else if(y > m_x){
      m_y += m_speed;
      m_direction = UP;
   }
}

// attack the player
void Zombie::attack()
{
   //TODO attack sound
   // ensure the attack doesn't happen too often
   static Timer lastAttack;
   if(lastAttack.elapsed(m_attackDelay)){
      lastAttack.set();
      Player::getInstance().attacked(m_damage);
   }
}

// display is used to draw this object
void Zombie::display()
{
   if(!m_visible){
      return;
   }
   if(m_dead){
      m_texture = ImageLoader::LoadTexture("imgs/Sprites/zombies/ZombieA/Dead.png");
      return;
   }else{
      m_texture = ImageLoader::LoadTexture("imgs/Sprites/zombies/ZombieA/DownA.png");
   }

   /*TODO animation
   // ensure that the frame either needs to be updated or the zombie has changed direction
   static int lastDirection = 0;
   static Timer lastFrame;
   if(!lastFrame.elapsed && lastDirection == m_direction){
      return;
   }
   lastFrame.set();
   // each of the directions has three frames, update the picture every frame
   static curframe = 0;
   // draw a sprite with respect to the direction and current frame
   switch(m_direction){
      case(UP):
         
         break;
      case(DOWN):
         break;
      case(LEFT):
         break;
      case(RIGHT):
         break;
   }
   */

   //draw the Zombie
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
   glBindTexture (GL_TEXTURE_2D, m_texture);
   ImageLoader::rectangle(m_x,m_y, SPRITE_SIZE_X, SPRITE_SIZE_Y);
   glDisable(GL_TEXTURE_2D);
   glFlush();
}

// kill the zombie immediately
void Zombie::kill()
{
   m_dead = true;
}

// make the zombie disappear
void Zombie::disappear()
{
   m_visible = false;
}

void Zombie::spawn(int x, int y)
{
   // revive or vive the zombie
   m_dead = false;
   m_visible = true;
   m_health = 100;
   m_x = x;
   m_y = y;
}

void Zombie::attacked(int x1, int y1, int x2, int y2, int damage)
{
   // TODO hurt sprite, sound?
   if(m_dead || !m_visible){
      return;
   }
   // see if the sprite box touches the 'damage' box
   Square damageBox(x1, y1, x2, y2);
   Square spriteBox(m_x, m_y, m_x + SPRITE_SIZE_X, m_y + SPRITE_SIZE_Y);
   // take damage if zombie is in attack range
   if(damageBox.collides(spriteBox)){
      m_health -= damage;
      // kill zombie if hurt enough
      if(m_health <= 0){
         m_dead = true;
      }
   }
}

void Zombie::update(Point &playerpos)
{
   update(playerpos.getX(),playerpos.getY());
}

void Zombie::spawn(Point &pos)
{
   spawn(pos.getX(),pos.getY());
}
