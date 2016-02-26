#ifndef WEAPONS_H_
#define WEAPONS_H_
#include <string>
#include "../hdr/Items.h"
class Weapon: public Items{
   private:
      int m_damage;  //weapon damage
      int m_type;

   public:
      int getDamage(){return m_damage;}//returns current weapon damage
      int setDamage(int d);//set's damage of weapon
                     //if certain items are used.
      int getType(){return m_type;}
      void display();
      void update();
      Weapon(int d, int r, int invs, int id, std::string name, int type);
      Weapon(){};
};

#endif
