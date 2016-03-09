//******************************************//
//********** Title: ItemHandler.h **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//**********List of Items and ID's**********//
//********** INPUT_ITEMS          **********//
//**********                      **********//
//**********                      **********//
//**********                      **********//
//**********Item ID:              **********//
//**********   0: sword           **********//
//**********   1: aoe spell       **********// *test
//**********   2:                 **********//
//**********   3:                 **********//
//**********   4:                 **********//
//**********   5:                 **********//
//**********   6:                 **********//
//**********   7:                 **********//
//**********   8:                 **********//
//**********   9:                 **********//
//**********   10:lemon           **********//
//**********   11:heart           **********//
//**********   12:health Potion   **********//
//**********   13:                **********//
//**********   14:                **********//
//**********   15:                **********//
//**********   16:                **********//
//**********   17:                **********//
//**********   18:                **********//
//**********   19:                **********//
//******************************************//


#ifndef ITEMHANDLER_H_
#define ITEMHANDLER_H_
#define MAXITEMS 50
#define MAXINV 10

#include "Items.h"
#include "GameObject.h"
#include "Weapon.h"
#include "ObsArr.h"

/*
#include "../hdr/Items.h"
#include "../hdr/GameObject.h"
#include "../hdr/Weapon.h"
*/
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
         //m_numOfItems = 21;
         //start with a sword and 1 lemon
         m_weaponInv[0] = new Weapon(0,-1,-1,"Sword", false, 25,-1,0,10);
         m_itemInv[0] = new Items(10,-1,-1,"Lemon",false,0,-1);         
         
         //for now, I will create 10 Item objects into the m_itemList[]. 
         //final product will have a 2D array, which creates items and
         //deletes Items per screen, it will also randomize the placement
         //of the lemons.
         
         
         //*********TEST ITEMS FOR USE WITH COLLISIONSLAB*********/
         /*
         m_itemList[0] = new Items(0,-1, 10, "Lemon", false, 246, 596, 0);
         m_itemList[1] = new Items(0,-1, 11, "heart", false, 507, 297, 0);
         m_itemList[2] = new Items(0,-1, 11, "Heart", false, 729, 603, 0);
         m_itemList[3] = new Items(0,-1, 10, "Lemon", false, 203, 572, 1);
         m_itemList[4] = new Items(0,-1, 12, "Potion", false, 795, 105, 1);
         m_itemList[5] = new Items(0,-1, 11, "Heart", false, 208, 130, 2);
         m_itemList[6] = new Items(0,-1, 11, "Heart", false, 621, 462, 2);
         m_itemList[7] = new Items(0,-1, 11, "Heart", false, 838, 90, 3);
         m_itemList[8] = new Items(0,-1, 10, "Lemon", false, 214, 380, 4);
         m_itemList[9] = new Items(0,-1, 11, "Heart", false, 834, 695, 4);
         m_itemList[10] = new Items(0,-1, 12, "Potion", false, 422, 159, 4);
         m_itemList[11] = new Items(0,-1, 11, "Heart", false, 313, 799, 4);
         m_itemList[12] = new Items(0,-1, 12, "Potion", false, 471, 136, 5);
         m_itemList[13] = new Items(0,-1, 11, "Heart", false, 201, 446, 5);
         m_itemList[14] = new Items(0,-1, 10, "Lemon", false, 687, 478, 6);
         m_itemList[15] = new Items(0,-1, 11, "Heart", false, 504, 480, 6);
         m_itemList[16] = new Items(0,-1, 11, "Heart", false, 820, 215, 7);
         m_itemList[17] = new Items(0,-1, 12, "Potion", false, 445, 764, 7);
         m_itemList[18] = new Items(0,-1, 10, "Lemon", false, 474, 13, 8);
         m_itemList[19] = new Items(0,-1, 11, "Heart", false, 336, 824, 8);
         */
         //*test*//
         //m_itemList[20] = new Weapon(20,100,1,1,"AOESpell", 0,false,500,500,3);
         
		init();
                   
      }
      //~ItemHandler(){}
      ItemHandler(ItemHandler const&);
      void operator=(ItemHandler const&);
   
   private:
         Items *m_itemList[MAXITEMS];  //list of all items on map
         Items *m_itemInv[MAXINV];     //items inventory
         Weapon *m_weaponInv[MAXINV];   //weapon inventory
         int m_invStack[MAXINV]; //amount of that item you are holding. ie character has
                                 //3 lemons, lemons are in slot 10, so m_invStack[10] = 3; 
         int m_currWeapon;       //current weapon in item array
         int m_currItem;         //current item in item array
         int m_lastWeapon;       //last weapon slot in your inventory
         int m_lastItem;         //last item slot in your inventory
         int m_numOfItems;       //total number of Items on map
         int *m_tileItems;        //num of items in a given tile.
         ObsArr *m_level1Items;
         int m_numTiles;
      
   public:
      //may be implemented if we implement inventory screen
      Weapon* getWeaponInv() {return *m_weaponInv;} 
      Items* getItemInv() {return *m_itemInv;}
      //may be implemented if we implement inventory screen
      int getWeaponSlot() {return m_currWeapon;}
      int getItemSlot() {return m_currItem;}
      //returns pointer to current Item to use for HUD&Player
      //then use that to access that items methods like so:
      // Items* item = getItem();
      //item->getName();
      Weapon* getWeapon() {return m_weaponInv[m_currWeapon];}
      Items* getItem() {return m_itemInv[m_currItem];}
      //add new item to inventory Used by Items.cpp
      void addItemToInv(Items* item);
      //add new weapon to inventory used by Weapon.cpp
      void addWeaponToInv(Weapon* weapon);
      //calls Items::display(), and Items::pickUp()
      void update();
      //initialized first map, called on load.
      void init();
      //switch current Item to next one, loops around when at last item 
      void iSwitch();
      void wSwitch();
      //use Current Item (to be implemented later)
      void iUse();      

};
#endif
