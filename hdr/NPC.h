// **********************************************
// Filename:   NPC.h
// Author:     Daniel Guenther
// Date:       2016-02-01
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    The generic 'non-player character' type
//    NOTE: abstract class
// ************************************************

#ifndef NPC_H
#define NPC_H

// DrJ dynamic typing
class NPC{
   public:
      // update should be run in every frame that the game is going on for
      virtual void update() = 0;
      // display is used to draw this object
      virtual void display() = 0;
};
#endif
