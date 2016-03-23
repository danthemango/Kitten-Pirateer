//******************************************//
//********** Title: ItemsFactory.h**********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//**********   Factory Pattern    **********//
//**********   for all item       **********//
//**********   related creation   **********//
//******************************************//


#ifndef ITEMS_FACTORY_H_
#define ITEMS_FACTORY_H_

#include "../hdr/ItemObject.h"
#include "../hdr/Items.h"
#include "../hdr/Weapon.h"

// DrJ Pattern 2 Factory
/*
 * Name:
 * 	Factory Pattern
 * 
 * Problem:
 * 	want to create objects without exposing the instantiation logic 
 * 	to the client
 * 	want to refer to the newly created object through a common 
 * 	interface	
 * 	
 * Solution:
 * 	factory pattern creates all objects through a common interface,
 * 	eg createItem
 * 	it creates all different item types without client knowing how.
 * 
 * Consequences and Trade Offs:
 * 	+Isolates concrete classes by helping programmer to control the 
 * 	 classes of objects that a client creates
 * 	+Makes exchanging product families easy because the class of a 
 * 	 concrete factory appears only once in an application, at the 
 * 	 place of its instantiation. This makes it easy to change the 
 * 	 concrete factory that an application uses.
 *    +Promotes consistency among products by enforcing to use objects 
 * 	 from the same family of objects
 * 	-Adds more layers of abstraction and complexity
 * 	-If any underlying details change of one factory, the interface 
 * 	 might have to be modified for all factories
 * 
 */



class ItemsFactory {
	
	public:
		static ItemObject *createItem(int id, int x, int y, std::string name, int r, int tilepos, int type, int d);
};



#endif
