//******************************************//
//********** Title: ItemObject.h  **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//**********   Template class for **********//
//**********   Weapons & Items    **********//
//******************************************//



#ifndef ITEM_OBJECT_H_
#define ITEM_OBJECT_H_

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string>
#include <iostream>

// DrJ Static and dynamic types and bindings
/*
 * Static type of an instance for Weapon, is ItemObject, dynamic type is
 * Weapon
 * 
 */
 
 // DrJ Constructor
/*
 * Default constructer is the constructer that is exists by default.
 * It does not always exist if you define your own, to create a new one
 * in a subclass you have to define it.
 * 
 * for example of calling specific constructor see AOESpell.h
 * 
 */
 
 //DrJ Pattern 1 Template
 /*
  * Name:
  * 	Template Method
  * Problem:
  * 	Two different components have significant similarites, but 
  * 	demonstate no reuse of common interface or implementation. if a
  * 	change common to both components become necessary, duplicate 
  * 	effort must be expended
  * 
  * Solution:
  * 	implement invariant aspects of an algorithm once and let 
  * 	subclasses define variant parts 
  * 
  * 	localize common behavior in a class to increase code reuse
  * 
  * 	control sublclass extensions
  * 
  * Consequences and Trade Offs:
  * 	+Leads to inversion of control ("Hollywood principle" : don't 
  * 	 call us, we'll call you)
  * 	+Promotes cold reuse
  * 	+lets you enforce overrideing rules
  * 	-must sublcass to specialize behavior
  * 
  * 
  */

class ItemObject {
	protected:
		int m_range;//range of item 0 if N/A
		std::string m_name;
		int m_amount;
		int m_itemID;  //item id states which
                     //type of item it is    
		bool m_displayed; //bool to see if item has been picked up
		int m_tilePos; //which tile item is in
		int m_x;//Xposition of item, -1 if N/A
		int m_y;//YPosition of item, -1 if N/A
		int m_itemWidth;
		int m_damage;  //weapon damage
		int m_type; //weapon type
                  //0:melee
                  //1:gun
                  //2:spell
                  //3:boomerang
      
		GLuint m_itemTexture;
	
	public: 
		//find out if anyone is using this
		
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
		void setAmount(int x){m_amount = x;}
		
		//return's Damage
		int getDamage(){return m_damage;}
		
		//displays Item
		virtual void display();
		
		//set's damage of weapon if certain items are used
		int setDamage(int d){ m_damage = d;}
		
		//returns type of weapon as defined above
		int getType(){return m_type;}
		
		void setDisplayed(bool display){m_displayed = display;}
      
		void update(){}
		//ItemObject(){};
		
		//attack function for weapon
		virtual void use()=0;
		
		//deals with picking up the Item
		virtual void pickUp(int x, int y)=0;  //when picked up	
		
		virtual ~ItemObject(){};
};

#endif
