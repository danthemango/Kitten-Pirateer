//********************************************//
//********** Title: ItemHandler.cpp **********//
//********** Author: Robert Dunn    **********//
//********** Purpose:               **********//
//********************************************//


#include "../hdr/ItemHandler.h"
#include "../hdr/Items.h"
#include "../hdr/Weapon.h"
#include "../hdr/Jukebox.h"
#include "../hdr/Game.h"
#include "../hdr/ItemsFactory.h"
#include "../hdr/ObsArr.h"

/*
#include "../hdr/ItemHandler.h"
#include "../hdr/Items.h"
*/
#include <iostream>
#include <string>

void ItemHandler::addItemToInv(Items* item)
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

void ItemHandler::addWeaponToInv(Weapon* weapon)
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
      m_itemList[i]->pickUp();
   }
   
}

void ItemHandler::init()
{
	m_level1Items = new ObsArr("./config/INPUT_ITEMS");
	m_numTiles = m_level1Items->numTiles();
	m_tileItems = m_level1Items->numObsArr();
	
	
	std:string name;
	int damage;
	int range;
	int type;
	int id;
	int itempos = 0;
	
	
	for(int i = 0; i < m_numTiles; i++){
		for(int k = 0; k < m_tileItems[i]; k++){
			id = m_level1Items->m_array[i][k][0];
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
					type = 0; //change this later.
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
			}
			//int id, int x, int y, std::string name, int r, int tile pos, int type, int d
			m_itemList[itempos] = ItemsFactory::createItem
			(
				m_level1Items->m_array[i][k][0],
				m_level1Items->m_array[i][k][1],
				m_level1Items->m_array[i][k][2],
				name, range, i, type, damage
				
			);
			itempos++;
			
		}
	}

	m_numOfItems = itempos;
	
}

void ItemHandler::iSwitch()
{
	//std::cout << "switch item" << m_currItem << std::endl;
	
   if(m_currItem == m_lastItem){
      m_currItem = 0;
   }else{
      m_currItem = m_currItem +1;   
   }
 
 //  FOR TESTING
   //std::string name = m_itemInv[m_currItem]->getName();
   //int amount = m_itemInv[m_currItem]->getAmount();
   //std::cout << name << ": " << amount << std::endl;

}

void ItemHandler::wSwitch()
{
	//sstd::cout << "switch weapon" << m_currWeapon << std::endl;
   if(m_currWeapon == m_lastWeapon){
      m_currWeapon = 0;
   }else{
      m_currWeapon++;
   }
}

void ItemHandler::iUse()
{  int id = getItem()->getItemID();

   switch (id){
      case 12:
         if(getItem()->getAmount() > 0){
			if(Player::getInstance().getHealth() < MAX_PLAYER_HEALTH){
				Jukebox::PlaySound("./sounds/HealthPotionUse.wav");
				Player::getInstance().addHealth(20);
				getItem()->decreaseAmount();
			}
         }
         break;
   }
   
   
}



