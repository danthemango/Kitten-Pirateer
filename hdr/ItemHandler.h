//******************************************//
//********** Title: ItemHandler.h **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//**********   List of Items and  **********//
//**********   ID's. Handles all  **********//
//**********   item related stuff **********//
//**********                      **********//
//********** INPUT_ITEMS          **********//
//**********                      **********//
//**********                      **********//
//**********                      **********//
//**********Item ID:              **********//
//**********   0: sword           **********//
//**********   1: aoe spell       **********//
//**********   2: FireBall        **********//
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
//**********   13:bomb            **********//
//**********   14:                **********//
//**********   15:                **********//
//**********   16:                **********//
//**********   17:                **********//
//**********   18:                **********//
//**********   19:                **********//
//******************************************//


#ifndef ITEMHANDLER_H_
#define ITEMHANDLER_H_
#define MAXITEMS 200
#define MAXINV 10

#include "Items.h"
#include "ItemObject.h"
#include "GameObject.h"
#include "Weapon.h"
#include "ObsArr.h"
#include <string>

#define PERCENT_LEMON 30
#define PERCENT_AOE 20
#define PERCENT_FIREBALL 30
#define PERCENT_HEART 50
#define PERCENT_HEALTHPOTION 35



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
        m_lemons = 1;
        //m_numOfItems = 21;
        //start with a sword and 1 lemon
        m_weaponInv[0] = new Weapon(0,-1,-1,"Sword", false, 25,-1,0,10);
        m_itemInv[0] = new Items(10,-1,-1,"Lemon",false,0,-1);         
        
		init();
      }
      ~ItemHandler(){}
      ItemHandler(ItemHandler const&);
      void operator=(ItemHandler const&);
   
   private:
        // ItemObject *m_itemList[MAXITEMS];  //list of all items on map
         ItemObject *m_itemInv[MAXINV];     //items inventory
         ItemObject *m_weaponInv[MAXINV];   //weapon inventory
         int m_invStack[MAXINV]; //amount of that item you are holding. ie character has
                                 //3 lemons, lemons are in slot 10, so m_invStack[10] = 3; 
         int m_currWeapon;       //current weapon in item array
         int m_currItem;         //current item in item array
         int m_lastWeapon;       //last weapon slot in your inventory
         int m_lastItem;         //last item slot in your inventory
         int m_numOfItems;       //total number of Items on map
         int *m_tileItems;        //num of items in a given tile.
         ObsArr *m_3DItems;
         int m_numTiles;
         int m_currTile;
         int m_lemons;
      
   public:
		int getNumOfItems(){return m_numOfItems;}
		ItemObject *m_itemList[MAXITEMS];	
			
		//may be implemented if we implement inventory screen
		ItemObject* getWeaponInv() {return *m_weaponInv;} 
		ItemObject* getItemInv() {return *m_itemInv;}
		//may be implemented if we implement inventory screen
		int getWeaponSlot() {return m_currWeapon;}
		int getItemSlot() {return m_currItem;}
		//returns pointer to current Item to use for HUD&Player
		//then use that to access that items methods like so:
		// Items* item = getItem();
		//item->getName();
		ItemObject* getWeapon() {return m_weaponInv[m_currWeapon];}
		ItemObject* getItem() {return m_itemInv[m_currItem];}
		//add new item to inventory Used by Items.cpp
		void addItemToInv(ItemObject* item);
		//add new weapon to inventory used by Weapon.cpp
		void addWeaponToInv(ItemObject* weapon);
		//calls Items::display(), and Items::pickUp()
		void update();
		//initialized first map, called on load.
		void init();
		//switch current Item to next one, loops around when at last item 
		void iSwitch();
		void wSwitch();
		//use Current Item (to be implemented later)
		void iUse();
		void buildItemArray(std::string file);
		bool randomize(int id);

};
#endif
