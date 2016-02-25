//Author: Anand Sundar
//Purpose: Side_scrol class takes care of the camera angle of the game and pc movements for side scroll levels

#ifndef PC_SIDE_SCROLL_H_
#define PC_SIDE_SCROLL_H_


#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <GL/freeglut.h>
#include <cstdio>

class ImageLoader;

class pc_side_scroll : public pc {

   private:
   void side_movements();// moves the pc sideways when going uphill
   void side_attacks(weapons); //including movement of projectiles
   int gravity_control; // sets a value gravity so that the pc does not fall off the screen
   
   public:
   pc_side_scroll(){
	gravity = 50;
	}
   static void side_controls();
   void update(); //updates the gravity when needed
   bool gravity_check();//checks the gravity everytime the screen refreshes
   

};

#endif
