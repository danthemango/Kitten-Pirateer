#ifndef ITEMS_H_
#define ITEMS_H_

#include <string>
#include "../hdr/GameObject.h"

class Items: public GameObject{
   protected:
      int m_range;//range of item 0 if N/A
      std::string m_name;
      int m_ammount;
      int m_invslot; //which inventory slot
                     //item is currently in
      int m_itemID;  //item id states which
                     //type of item it is     


   public:
      int getInvSlot(){return m_invslot;}//get current inv slot
      int getItemID(){return m_itemID;}
      int getAmmount(){return m_ammount;}
      int getRange(){return m_range;}
      std::string getName(){return m_name;}
      void pickUp();  //when picked up
      virtual void display();
      virtual void update();
      Items(int r, int inv, int id, std::string name);
      Items (){};
};
#endif
