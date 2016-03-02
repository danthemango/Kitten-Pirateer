//********************************************//
//********** Title: ItemHandler.cpp **********//
//********** Author: Robert Dunn    **********//
//********** Purpose:               **********//
//********************************************//


#include "../hdr/ItemHandler.h"
#include "../hdr/Items.h"
#include "../hdr/Jukebox.h"
#include "../hdr/Game.h"

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
      }
   }
   if(placed == false){
      m_lastItem++;
      m_itemInv[m_lastItem] = item;
   }
}


void ItemHandler::update()
{
   for(int i = 0; i < m_numOfItems; i++){
      m_itemList[i]->display();
      m_itemList[i]->pickUp(m_itemList[i]);
   }
   
}

void ItemHandler::iSwitch()
{
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
   if(m_currWeapon == m_lastWeapon){
      m_currWeapon == 0;
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



