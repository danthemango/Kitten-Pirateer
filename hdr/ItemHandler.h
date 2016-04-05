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

/*
#define PERCENT_LEMON 100
#define PERCENT_AOE 100
#define PERCENT_FIREBALL 100
#define PERCENT_HEART 100
#define PERCENT_HEALTHPOTION 100
*/

#define PERCENT_LEMON 30
#define PERCENT_AOE 20
#define PERCENT_FIREBALL 30
#define PERCENT_HEART 50
#define PERCENT_HEALTHPOTION 35



// DrJ Header File
/*	I produced the functionality of items & weapons in the game.
 * Having many types of items and weapons allow the player to 
 * interact with enemies and other items.
 * I made the required header files for other team members to use
 * which are commented out for all the functions they will need.
 */


// DrJ Abstraction 
/* Abstraction is a technique for managing complexity of 
 * computer systems. It works by establishing a level of 
 * complexity on which a person interacts with the system, 
 * suppressing the more complex details below the current level.
 * 
 * This is an abstraction because an interface
 */
 
// DrJ Encapsulation
/* Encapsulation is used to refer to one of two related but distinct
 * notions, and sometimes to the combination[1][2] thereof:
 * 
 * A language mechanism for restricting access to some of the object's
 * components.
 * 
 * A language construct that facilitates the bundling of data with 
 * the methods (or other functions) operating on that data.
 * 
 * I use Encapsulation with public, and private. Keeping the variables
 * that I don't want others to access, but maybe only access through
 * a get. ex. curr weapon, I don't want others to access the variables
 * and set the curr weapon since there is no need for it. But HUD need
 * to know what the current weapon is, so through a getWeapon() it 
 * returns pointer to current weapon.
 * 
 */

// DrJ Polymorphism
/* Polymorphism is the provision of a single interface to entities of
 * different types.
 * 
 * Subtyping: when a name denotes instances of many different classes
 * related by some common superclass.[3] In the object-oriented 
 * programming community, this is often simply referred to as 
 * polymorphism.
 * 
 * I use polymorphism for putting my Weapon/Items type into a single
 * type of ItemObject (which using method template pattern)
 * 
 * Good example is also in src/ItemsFactory.cpp  which is a factory
 * pattern.
 * 
 */

// DrJ Class/object
/*
 * Instance variables belong to an instance of a class. Another way of 
 * saying that is instance variables belong to an object, since an 
 * object is an instance of a class. 
 * 
 * Class variables, however, only have one copy of the variable(s) 
 * shared with all instances of the class.
 * 
 * I use a class variable for my item list, c_itemList. Tones of members
 * 
 * method defined in a class which is only accessable through the 
 * Object of the class are called Instance method. 
 * 
 * Class methods are methods that are called on a class rather than 
 * an instance.
 *
 *	getInstance() is a class method, all others here are instance methods 
 */

// DrJ Static and dynamic types and bindings
// look in ItemObject.h

// DrJ Clean Room
/*
 * create instances statically or dynamically
 * for me using new Weapon is dynamically allocated, and the instance
 * is statically created.
 * 
 * life time of static is program time, dynamic is scope time
 * 
 * use delete object;
 * 
 */

// DrJ Pattern Singleton
/* Name:
 * 	Singleton
 * 
 * Problem:
 * 	There must be exactly one instance of a class, and it must be
 * 	accessible from a well-known access point.
 * 	
 * Solution:
 * 	the singleton pattern ensures a class has only one instance, and
 * 	provides a global point to access it.
 * 
 * Consequences and Trade Offs:
 * 	+reduces namespace pollution
 * 	+makes ie easy to change your mind and allow more than one 
 * 	 instance
 * 	+allow extension by subclassing
 * 	-same drawbacks of a global if misused
 * 	-implementation may be less efficient than a global
 * 	-concurrency pitfalls
 * 
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
        m_level = 0;
        m_currItem = 0;
        m_lastWeapon = 0;
        m_lastItem = 0;
        m_lemons = 0;
        m_bombPlaced = false;
        //m_numOfItems = 21;
        //start with a sword and 1 lemon
        m_weaponInv[0] = new Weapon(0,-1,-1,"Sword", false, 25,-1,0,10);
        m_itemInv[0] = new Items(10,-1,-1,"Lemon",false,0,-1);  
        m_itemInv[0]->setAmount(0);       
        
		init();
      }
      ~ItemHandler(){}
      ItemHandler(ItemHandler const&);
      void operator=(ItemHandler const&);
   
   private:
        // ItemObject *c_itemList[MAXITEMS];  //list of all items on map
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
         bool m_bombPlaced;
         int m_level;
      
   public:
		int getNumOfItems(){return m_numOfItems;}
		static ItemObject *c_itemList[];	
			
		//may be implemented if we implement inventory screen
		/*ItemObject* getWeaponInv() {return *m_weaponInv;} 
		ItemObject* getItemInv() {return *m_itemInv;}
		*/
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
		void resetLemons();
		void removeItems();
		void setLevel(int x) {m_level = x;}
};
#endif
