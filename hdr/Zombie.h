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

// TODO Pattern 2
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "HostileNPC.h"
#include "Shapes.h"
#include "ImageLoader.h"
#include "../hdr/Timer.h"

/* DrJ Header File
   I am responsible for this file, as well as PositionMap.h, Shapes.h, Timer.h and ZombieHandler.h

   Interfaced by Game, as well as by Player
 */

// DrJ Inheritance
//    'virtual' keyword allows for dynamic binding of messages
// DrJ Multiple Inheritance
//    multiple inheritance is different from single inheritance because
//    it allows for multiple inheritance
//    note: Java doesn't support multiple inheritance
/* DrJ Class/Object
      there will be an instance of a member variable m_ for each instance of the class (object)
      but there will only be one class varible shared amongst all instances of a class
 */
class Zombie: public HostileNPC, public Square{
   public:
      Zombie();
      /* DrJ Encapsulation
         it should be apparent that the following function has some effect 
         on the internal state, but this is the method we use and we don't 
         care how it changes the internal state
      */
      // update takes in the player's position
      // this function will act as the NPC's 'AI' 
      void update(int x, int y);
      void update(Point &playerpos);
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
      /* DrJ Abstraction
         the following function signater clearly communicates what this function
         is supposed to do, but not how it is done
      */
      // receives damage if zombie is in the area of the rectangle specified
      // (x1,y1) - bottom left corner of the area 
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
      // TODO replace direction with states
      // the different states of the zombie
      enum class state {
         left,
         right,
         up,
         down,
         eating,
      };
      state m_state;
      float m_speed; // speed
      // attack strength of the zombie
      int m_damage;
      // current displaying texture
      GLuint m_texture;
      // if the player is further away than this, attack the player
      int m_attackRange;
      // if the last attack was this many milliseconds ago, attack again
      Timer m_lastAttack;
      long int m_attackDelay;
      // animation rate
      long int m_animDelay;
      // let the zombies disappear after a few moments
      Timer m_killedTime;
      int m_disappearTime;
      void update(){} // empty declaration
};
#endif
