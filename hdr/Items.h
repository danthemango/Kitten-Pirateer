//******************************************//
//********** Title: Items.h       **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//******************************************//


#ifndef ITEMS_H_
#define ITEMS_H_

#include <string>
#include <GL/freeglut.h>
//#include "../hdr/GameObject.h"
#include "GameObject.h"
#include "ItemObject.h"

class Items: public ItemObject{
   protected:
      int m_range;//range of item 0 if N/A
      std::string m_name;
      int m_amount;
      int m_invslot; //which inventory slot
                     //item is currently in
      int m_itemID;  //item id states which
                     //type of item it is    
      bool m_displayed; //bool to see if item has been picked up
      int m_tilePos; //which tile item is in
      int m_x;//Xposition of item, -1 if N/A
      int m_y;//YPosition of item, -1 if N/A
      int m_itemWidth;
      
      GLuint m_itemTexture;


   public:
      //find out if anyone is using this
      int getInvSlot(){return m_invslot;}//get current inv slot
      //get's Item ID, 
      int getItemID(){return m_itemID;}
      //Gets amount of Items, default is 1
      int getAmount(){return m_amount;}
      //sets amount for use in Item use
      void decreaseAmount(){m_amount--;}
      //Gets range of Item
      int getRange(){return m_range;}
      //Gets Name of Item
      std::string getName(){return m_name;}
      //Sets amount the Item has. Ex: picked up another lemon, set amount to 2
      void setAmount(int x);
      //deals with picking up the Item
      virtual void pickUp();  //when picked up
      //displays Item
      void display();
      
      void update();
      
      //Items(int r, int inv, int id, std::string name, bool pickup, int x, int y, int tile);
      Items(int id, int x, int y, std::string name, bool display, int r, int tile);
      Items (){};
      ~Items(){};
};
#endif
