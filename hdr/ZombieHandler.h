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
// ************************************************

#ifndef ZombieHandler_H
#define ZombieHandler_H
#include "Zombie.h"
#include "GameObject.h"
#include "config.h"

class ZombieHandler: public GameObject
{
   public:
      // returns the currently existing instance
      static ZombieHandler &getInstance();
      // updates all contained zombies
      void update();
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
      Zombie m_ZombieList[MAXZOMBIES];
      // load zombie positions from config/Zombies
      void loadZombies();
      // number of zombies in each tile
      int m_numZombies[NUM_TILES_X][NUM_TILES_Y];
      // defines an x,y position
      struct pos{
         int x,y;
      }
      // array to hold positions of zombies
      // in order, this array holds the 
      // [tilepositionx][y][zombienumber][zombiepositionx][y]
      pos m_ZombiePosition[TILE_NUM_X][TILE_NUM_Y][MAXZOMBIES];
      // current tile position
      int x,y;

      // for a singleton, we don't share the default methods
      ZombieHandler();
      ZombieHandler(const ZombieHandler &old); // no copying
      const ZombieHandler &operator= (const ZombieHandler &old); // no assignment
      ~ZombieHander();
};
#endif
