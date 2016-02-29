// **********************************************
// Filename:   ZombieHandler.h
// Author:     Daniel Guenther
// Date:       2016-02-01
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    instatiates and holds Zombies (objects)
//
// Note:
//    ZombieHandler is a singleton class, every method must be 
//    used like: ZombieHandler::getInstance().method()
//    ZombieHandler is also a proxy for the Zombie Objects
// ************************************************

#ifndef ZombieHandler_H
#define ZombieHandler_H
#include "Zombie.h"
#include "GameObject.h"
#include "config.h"
#include "PositionMap.h"

class ZombieHandler: public GameObject
{
   public:
      // returns the currently existing instance
      static ZombieHandler &getInstance();
      // updates all contained zombies
      void update(int x, int y);
      // draws all zombies
      void display();
      // damages every Zombie in the range
      // x1 y1 - bottom left corner coordinates
      // x2 y2 - top right corner coordinates
      // int damage - damage amount
      void attacked(int x1, int y1, int x2, int y2, int damage);
      // switch to a new tile
      void updateTile(int x);
      // turn all zombies into corpses
      void killAllZombies();
      // make all zombies disappear
      void removeAllZombies();
   private:
      // an array containing the zombie objects
      Zombie* m_ZombieList[MAXZOMBIES];
      // map which stores the positions with respect to the tiles of the map
      PositionMap m_map[NUM_TILES];
      // current number of zombies
      int m_num_zombies;
      // currently loaded tile
      int m_tile;
      // for a singleton, we don't share the default methods
      ZombieHandler();
      ZombieHandler(const ZombieHandler &old); // no copying
      const ZombieHandler &operator= (const ZombieHandler &old); // no assignment
      ~ZombieHandler();
};
#endif
