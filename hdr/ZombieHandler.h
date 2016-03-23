// **********************************************
// Filename:   ZombieHandler.h
// Author:     Daniel Guenther
// Date:       2016-02-01
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    instatiates and holds Zombies (objects)
// DrJ Header File
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

/* DrJ Pattern Singleton
Problem: - we only want a single entry point to our class
         - we want a single resource being responsible for a service
Solution: - make the class itself responsible for its own creation and deletion
          - the class initializes itself and allows a single entry point to any
            of its methods (getinstance())
Contraindications: 
         - it works sort of like a 'global' variable, which is an antipattern
         - there is no-one responsible for this class, which might lead to high coupling
note: I'm using this here because I want to have a one-to-many relationship with zombieHandler 
      and zombies. I don't want the player to touch all of the zombies personally, 
      and I don't want a bunch of zombiehandlers floating around making it ambiguous as to
      who is responsible for the zombies. So this is a unique service and entry point for 
      dealing with the enemy zombies. 
 */

class ZombieHandler: public GameObject
{
   public:
      /* DrJ Class/object
          class method: 
             this method is the same for the whole class, and doesn't need an
             instance to be used.
             note that class methods can only affect class variables
             and can never touch instance variables
         the message is bound to the type
       */

      // returns the currently existing instance
      static ZombieHandler &getInstance();
      // update all of the zombies
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
      Zombie* m_ZombieList[MAXZOMBIES];
      // map which stores the positions with respect to the tiles of the map
      PositionMap m_map[NUM_TILES+1];
      // current number of zombies
      int m_num_zombies;
      // currently loaded tile
      int m_tile;
      // for a singleton we don't share the default methods
      ZombieHandler();
      ZombieHandler(const ZombieHandler &old); // no copying
      const ZombieHandler &operator= (const ZombieHandler &old); // no assignment
      ~ZombieHandler();
      void loadZombies();
};
#endif
