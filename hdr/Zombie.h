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
// ************************************************
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "HostileNPC.h"

class Zombie: HostileNPC{
   private:
      int health;
   public:
      Zombie();
      // update takes in the player's position
      // this function will act as the NPC's 'AI' 
      virtual void update(int x, int y);
      // display is used to draw this object
      virtual void display();
      // causes damage to the zombie (reduces health by amount)
      void damage(int amount);
      // returns true if Zombie has health <= 0
      int isDead();
};
#endif
