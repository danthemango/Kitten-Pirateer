//******************************************//
//********** Title: Items.h       **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//**********   All Items, heart,  **********//
//**********   Health Potion,     **********//
//**********   Lemon.             **********//
//******************************************//


#ifndef ITEMS_H_
#define ITEMS_H_

#include "ItemObject.h"
#include <string>
#include <GL/freeglut.h>
//#include "../hdr/GameObject.h"
#include "GameObject.h"

class Items: public ItemObject
{
   public:
   
      void pickUp(int x, int y);  //when picked up
      void use();
      
      Items(int id, int x, int y, std::string name, bool display, int r, int tile);
      Items (){};
      ~Items(){};
};
#endif
