// **********************************************
// Filename:   HostileNPC.h
// Author:     Daniel Guenther
// Date:       2016-02-01
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    abstract class for hostile non-player characters
// ************************************************
#ifndef HOSTILENPC_H
#define HOSTILENPC_H
#include "NPC.h"

class HostileNPC: NPC{
   public:
      // update takes in the player's position
      // this function will act as the NPC's 'AI' 
      virtual void update(int x, int y){}
      virtual void update(){}
      // display is used to draw this object
      virtual void display(){}
};
#endif
