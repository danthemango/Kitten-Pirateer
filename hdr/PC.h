//Author: Anand Sundar
//Purpose: Player control or PC is not a singletonn class. Its an abstract class
//for the entire program

#ifndef PC_H_
#define PC_H_

#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <GL/freeglut.h>
#include <cstdio>

class pc {
   private:
      void movement(check_boundary); //function responsible for PC's movement and checking screen boundary
      void attack(weapons,var_health);//function to attack the NPC using the weapons available 
      int var_health; //keeps track of the pc's health

   public:
      static pc& getInstance() {
         static pc instance; //creates a pc singleton
         return instance;
      };

      void get_damage(var_health); //function to get damage from npc attacks
      bool check_pc_ammo(weapons->ammo);// checks for ammo everytime the gun is fired
      bool check_pc_health(var_health);// checks pc health for every refresh of the screen
      void update(var_health,weapons->ammo,Inventory);// updates the necessary variables to be displayed in HUD
      static void controls();// calls the movement and attack functions in private
};

#endif 
