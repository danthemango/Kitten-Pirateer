//******************************************//
//********** Title: ItemHandler.h **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//**********List of Items and ID's**********//
//**********                      **********//
//**********Item ID:              **********//
//**********   0: sword           **********//
//**********   1:                 **********//
//**********   2:                 **********//
//**********   3:                 **********//
//**********   4:                 **********//
//**********   5:                 **********//
//**********   6:                 **********//
//**********   7:                 **********//
//**********   8:                 **********//
//**********   9:                 **********//
//**********   10:lemon           **********//
//**********   11:health          **********//
//**********   12:                **********//
//**********   13:                **********//
//**********   14:                **********//
//**********   15:                **********//
//**********   16:                **********//
///**********  17:                **********//
//**********   18:                **********//
//**********   19:                **********//
//******************************************//


#ifndef ITEMHANDLER_H_
#define ITEMHANDLER_H_
#define MAXITEMS 50
#define MAXINV 10
/*
#include "Items.h"
#include "GameObject.h"
#include "Weapon.h"
*/
#include "../hdr/Items.h"
#include "../hdr/GameObject.h"
#include "../hdr/Weapon.h"

class ItemHandler {
   public:
      static ItemHandler& getInstance()
      {
         static ItemHandler instance;
         
         return instance;
      };
   private:
      ItemHandler(){
         m_currWeapon = 0;
         m_currItem = 0;
         m_lastWeapon = 0;
         m_lastItem = 0;
         m_numOfItems = 0;
         //start with a sword and 1 lemon
         m_weaponInv[0] = new Weapon(10,3,0,0,"Sword", 0,true,-1,-1,-1);
         m_itemInv[0] = new Items(0,0,10, "Lemon",true,-1,-1,-1);
         
         
         //for now, I will create 10 Item objects into the m_itemList[]. 
         //final product will have a 2D array, which creates items and
         //deletes Items per screen, it will also randomize the placement
         //of the lemons.
         
         
         //*********TEST ITEMS FOR USE WITH COLLISIONSLAB*********/
         //m_itemList[0] = new Items(0,-1, 10, "Lemon", false, 100, 100, 1);
         //m_itemList[1] = new Items(0, -1, 11, "heart", false, 200,200,2);
         //m_itemList[2] = new Items(0,-1, 10, "Lemon", false, 500, 100, 3);
          
         
      }
      
      ItemHandler(ItemHandler const&);
      void operator=(ItemHandler const&);
   
   private:
         Items *m_itemList[MAXITEMS];  //list of all items on map
         Items *m_itemInv[MAXINV];     //items inventory
         Items *m_weaponInv[MAXINV];   //weapon inventory
         int m_invStack[MAXINV]; //amount of that item you are holding. ie character has
                                 //3 lemons, lemons are in slot 10, so m_invStack[10] = 3; 
         int m_currWeapon;       //current weapon in item array
         int m_currItem;         //current item in item array
         int m_lastWeapon;       //last weapon slot in your inventory
         int m_lastItem;         //last item slot in your inventory
         int m_numOfItems;       //number of Items on map
      
   public:
      //may be implemented if we implement inventory screen
      Items* getWeaponInv() {return *m_weaponInv;} 
      Items* getItemInv() {return *m_itemInv;}
      //may be implemented if we implement inventory screen
      int getWeaponSlot() {return m_currWeapon;}
      int getItemSlot() {return m_currItem;}
      //returns current Item to use for HUD&Player
      Items* getWeapon() {return m_weaponInv[m_currWeapon];}
      Items* getItem() {return m_itemInv[m_currItem];}
      //add new item to inventory Used by Items.cpp
      void addItemToInv(Items* item);
      //calls Items::display(), and Items::pickUp()
      void update();
      //switch current Item to next one, loops around when at last item 
      void iSwitch();
      void wSwitch();
      //use Current Item (to be implemented later)
      void iUse();      

};
#endif
