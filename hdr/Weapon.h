//******************************************//
//********** Title: Weapon.h      **********//
//********** Author: Robert Dunn  **********//
//********** Purpose:             **********//
//******************************************//


#ifndef WEAPONS_H_
#define WEAPONS_H_
#include <string>
#include "../hdr/Items.h"
class Weapon: public Items{
   private:
      int m_damage;  //weapon damage
      int m_type; //weapon type
                  //0:melee all types are melee right now
                  //1:gun
                  //2:spell

   public:
      int getDamage(){return m_damage;}//returns current weapon damage
      //set's damage of weapon
      //if certain items are used
      int setDamage(int d);
      //returns type of weapon as defined above
      int getType(){return m_type;}
      //displays weapons on map
      void display();
    
      void update();
      Weapon(int d, int r, int invs, int id, std::string name, int type, bool pickup,int x, int y, int tile);
      Weapon(){};
};

#endif
