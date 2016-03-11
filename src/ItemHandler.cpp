//********************************************//
//********** Title: ItemHandler.cpp **********//
//********** Author: Robert Dunn    **********//
//********************************************//


#include "../hdr/ItemHandler.h"
#include "../hdr/Items.h"
#include "../hdr/Weapon.h"
#include "../hdr/Jukebox.h"
#include "../hdr/Game.h"
#include "../hdr/ItemsFactory.h"
#include "../hdr/ObsArr.h"
#include "../hdr/Player.h"

/*
#include "../hdr/ItemHandler.h"
#include "../hdr/Items.h"
*/
#include <iostream>
#include <string>
#include <time.h>

void ItemHandler::addItemToInv(ItemObject* item)
{
   bool placed;
   for(int i=0;i<=m_lastItem;i++){
      if(item->getItemID() == m_itemInv[i]->getItemID()){
         m_itemInv[i]->setAmount(item->getAmount() + m_itemInv[i]->getAmount());
         placed = true;
         //std::cout << "item++" << std::endl;
      }
   }
   if(placed == false){
		//std::cout << "add item" << std::endl;
      m_lastItem++;
      m_itemInv[m_lastItem] = item;
   }
}

void ItemHandler::addWeaponToInv(ItemObject* weapon)
{
   bool placed;
   for(int i=0;i<=m_lastWeapon;i++){
      if(weapon->getItemID() == m_weaponInv[i]->getItemID()){
         m_weaponInv[i]->setAmount(weapon->getAmount() + m_weaponInv[i]->getAmount());
         placed = true;
         //std::cout << "test1" << std::endl;
      }
   }
   if(placed == false){
	   //std::cout << "test2" << std::endl;
      m_lastWeapon++;
      m_weaponInv[m_lastWeapon] = weapon;
   }	
	
}


void ItemHandler::update()
{
   for(int i = 0; i < m_numOfItems; i++){
      m_itemList[i]->display();
      m_itemList[i]->pickUp(Player::getInstance().getX(),Player::getInstance().getY());
   }
   if(m_itemInv[0]->getAmount() == m_lemons){
		//std:cout<< "found all lemons" << std::endl;
		m_itemInv[0]->setAmount(0);
		for(int i = 0; i < m_numOfItems; i++){
			if(m_itemList[i]->getItemID() == 13){
				m_itemList[i]->setDisplayed(true);
			}
		}
	}
   
}

void ItemHandler::init()
{
	buildItemArray("./config/INPUT_ITEMS");
}

void ItemHandler::buildItemArray(std::string file)
{
	srand (time(NULL));
	m_3DItems = new ObsArr(file);
	m_numTiles = m_3DItems->numTiles();
	m_tileItems = m_3DItems->numObsArr();
	
	
	std:string name;
	int damage;
	int range;
	int type;
	int id;
	int itempos = 0;
	
	
	for(int i = 0; i < m_numTiles; i++){
		for(int k = 0; k < m_tileItems[i]; k++){
			id = m_3DItems->m_array[i][k][0];
			if(randomize(id)){
			
				switch (id) {
					case 0:
						name = "Sword";
						range = 25;
						damage = 10;
						type = 0;
						break;
					case 1:
						name = "AOE Spell";
						range = 100;
						damage = 50;
						type = 2; //change this later.
						break;
					case 2:
						name = "Fire Ball";
						range = 900;
						damage  = 5;
						type = 2;
						break;
					case 3:
						name = "Boomerang";
						range = 350;
						damage = 0;
						type = 3;
						break;
					case 10:
						name = "Lemon";
						range = 0;
						type = -1; //n/a
						damage = -1;
						break;
					case 11:
						name = "Heart";
						range = 0;
						type = -1;
						damage = -1;
						break;
					case 12:
						name = "Health Potion";
						range = 0;
						type = -1;
						damage = -1;
						break;
					case 13:
						name = "Bomb";
						range = 0;
						type = -1;
						damage = 0;
						break;
				}
				m_itemList[itempos] = ItemsFactory::createItem
				(
					m_3DItems->m_array[i][k][0],
					m_3DItems->m_array[i][k][1],
					m_3DItems->m_array[i][k][2],
					name, range, i, type, damage
				
				);
				itempos++;
			}
		}
	}
	m_itemList[itempos] = ItemsFactory::createItem(10, 420, 785, "Lemon", 0, 5, -1, -1);
	m_lemons++;
	itempos++; 
	m_numOfItems = itempos;
	
}

bool ItemHandler::randomize(int id)
{
	int iRand;
	iRand = rand() % 100;
	if(id == 10){
		if(iRand < PERCENT_LEMON){
			m_lemons++;
			return true;
		}else{
		return false;
		}
	}else if(id == 1){
		if(iRand < PERCENT_AOE){
			return true;
		}else{
			return false;
		}	
	}else if(id == 2){
		if(iRand < PERCENT_FIREBALL){
			return true;
		}else{
			return false;
		}
	}else if(id == 11){
		if(iRand < PERCENT_HEART){
			return true;
		}else {
			return false;
		}
	}else if(id == 12){
		if(iRand < PERCENT_HEALTHPOTION){
			return true;
		}else{
			return false;
		}
	}else{
		return true;
	}
}

void ItemHandler::iSwitch()
{	
   if(m_currItem == m_lastItem){
      m_currItem = 0;
   }else{
      m_currItem = m_currItem +1;   
   }
}

void ItemHandler::wSwitch()
{
	if(m_currWeapon == m_lastWeapon){
		m_currWeapon = 0;
	}else{
		m_currWeapon++;
	}
	
	if(getWeapon()->getAmount() == 0){
		wSwitch();
	}
}

void ItemHandler::iUse()
{  
   getItem()->use();
}



