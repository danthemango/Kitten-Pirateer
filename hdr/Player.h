// **********************************************
// Filename:   Player.h
// Author:     Anand Sundar
// Date:       2016-02-25
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    The player of the game
//
// Note:
//    the player class is a singleton
// ************************************************

#ifndef PLAYER_H
#define PLAYER_H
#include <GL/freeglut.h>
#include "GameObject.h"
#include "Obstacle.h"
#include "Weapon.h"
#include "ImageLoader.h"
#include "config.h"

class Player
{
   public:
      // returns the currently existing instance
      static Player &getInstance();
      // updates all contained zombies
      void update();
      // draws all zombies
      void display();
      // damages every Player in the range
      // function will return health for HUD
      int getHealth();   
      // x1 y1 - bottom left corner coordinates
      // x2 y2 - top right corner coordinates
      // int damage - damage amount
      void attacked(int x1, int y1, int x2, int y2, int damage);
      void attack(); //to attack someone
      //returns the height of the player spright
      int getHeight();
      //returns the width of the player spright

      bool stopup,stopdown,stopleft,stopright;
      int getWidth();
      void left();
      void right();
      void up();
      void down();
      void displayTexture();
      void init();
      void collisions();
      void addHealth(int x);
   private:
      // for a singleton, we don't share the default methods
      Player();
      Player(const Player &old); // no copying
      const Player &operator= (const Player &old); // no assignment
      ~Player();
      int m_health;
      int m_direction; //up,down,left,right
      int m_x; //pos of player
      int m_y; //pos of player
      float m_speed; //player movement speed
      int m_arraypos;
      bool c_up,c_down,c_left,c_right;
      GLuint m_PlayerTexture;
};
#endif

