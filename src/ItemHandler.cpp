//********************************************//
//********** Title: ItemHandler.cpp **********//
//********** Author: Robert Dunn    **********//
//********** Purpose:               **********//
//********************************************//


#include "../hdr/ItemHandler.h"
#include "../hdr/Items.h"

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
         m_itemInv[i]->setAmmount(item->getAmmount() + m_itemInv[i]->getAmmount());
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
  // std::string name = m_itemInv[m_currItem]->getName();
   //int ammount = m_itemInv[m_currItem]->getAmmount();
   //std::cout << name << ": " << ammount << std::endl;

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
{
   
}



