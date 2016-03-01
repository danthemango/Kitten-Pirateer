// **********************************************
// Filename: Zombie.h
// Author: Daniel Guenther
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//    A 'Zombie' is a NPC which slowly follows the player
//    and deals damage when close enough
// 
// Note: zombie won't appear on screen until spawn() has been used
// ************************************************

#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "HostileNPC.h"
#include "Shapes.h"
#include "ImageLoader.h"

#define UP 0
#define DOWN 1
#define LEFT 2 
#define RIGHT 3

class Zombie: public HostileNPC{
   public:
      Zombie();
      // update takes in the player's position
      // this function will act as the NPC's 'AI' 
      void update(int x, int y);
      void update(Point &playerpos);
      void update()
      {
         //
      };
      // display is used to draw this object
      virtual void display();
      // causes damage to the zombie (reduces health by amount)
      void damage(int amount);
      // kill the zombie immediately
      void kill();
      // make the zombie disappear
      void disappear();
      // make the zombie appear at a position
      void spawn(int x, int y);
      void spawn(Point &pos);
      // receives damage if zombie is in the area of the rectangle specified
      void attacked(int x1, int y1, int x2, int y2, int damage);
   private:
      // attack the player
      void attack();
      // amount of damage the zombie can take
      int m_health;
      // if Zombie is dead, it won't attack the player or take an attack from the player
      bool m_dead;
      // if zombie is not visible, it won't be shown on screen
      bool m_visible;
      int m_speed; // speed
      int m_direction; // direction
      // position of the zombie
      int m_x, m_y;
      // attack strength of the zombie
      int m_damage;
      GLuint m_texture;
};
#endif
