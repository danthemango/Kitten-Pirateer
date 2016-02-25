// **********************************************
// Filename: ZombieHandler.h
// Author: Daniel Guenther
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//    instatiates and holds Zombies (objects)
// ************************************************
#ifndef ZombieHandler_H
#define ZombieHandler_H
#include "Zombie.h"

class ZombieHandler
{
   private:
      // number of zombie current instatiated
      int m_numZombies;
      // a linked list containing the zombie objects
      struct m_zlist{
         Zombie* n;
        m_zlist* next;
      }
      m_zlist* head;
   public:
      ZombieHandler();
      ~ZombieHander();
      // updates all contained zombies
      void update();
      // draws all zombies
      void display();
      // damages every Zombie in the range
      // x1 y1 - bottom left corner coordinates
      // x2 y2 - top right corner coordinates
      // int damage - damage amount
      void attacked(int x1, int y1, int x2, int y2, int damage);
};
#endif
