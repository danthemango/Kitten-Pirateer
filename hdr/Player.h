// **********************************************
// Filename:   Player.h
// Author:     Anand Sundar
// Date:       2016-02-25
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    The player of the game is the singleton. Only one instance can be created
//
// Note:
//    the player class is a singleton
// ************************************************

#ifndef PLAYER_H
#define PLAYER_H
#include <GL/freeglut.h>
#include "../hdr/GameObject.h"
#include "../hdr/Obstacle.h"
#include "../hdr/Weapon.h"
#include "../hdr/Items.h"
#include "../hdr/ItemHandler.h"
#include "../hdr/ImageLoader.h"
#include "../hdr/config.h"

class Player : public GameObject
{
   public:
      
      // returns the currently existing instance
      static Player &getInstance(){
        static Player instance;
        return instance;
      }
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
      void getPos();
      void left();
      void right();
      void up();
      void down();
      void displayTexture();
      void init();
      void collision(int xpos, int ypos, int width, int height, int cond);
      void addHealth(int x);
      int getDirection();
      bool c_up,c_down,c_left,c_right;
      int getTile();
      int getX();
      int getY();
   private:
      Player();
      ~Player();
      // for a singleton, we don't share the default methods
      Player(Player const &); // no copying
      void operator= (Player const &); // no assignment
      int m_health;
      int m_direction; //up(0),down(2),left(3),right(1)
      int m_x; //pos of player
      int m_y; //pos of player
      float m_speed; //player movement speed
      int m_arraypos;
      int m_stepSize;
      int m_currTile;
      GLuint m_PlayerTexture;
};
#endif

