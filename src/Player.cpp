// Author:   Anand Sundar
// Class:    CSCI 331
// Project:  Kitty Pirateer
//
// Purpose:
//     Player functionality implementation
//


// constructor to initialize the variables
Player::Player()
{
  m_health =100; //full health when the singleton is created
  m_x = PLAYER_START_X; //start X-pos of player
  m_y = PLAYER_START_Y; //start Y-pos of player
}

//player singleton
static Player Player:: &getInstance()
{
   static Player *instance = new Player;
   return *instance;
}

int Player::getHealth()
{
   return m_health;        
}
//returns the player height 
int getHeight() 
{
   return SPRITE_SIZE_Y;
}
//returns the player width
int getWidth()
{
   return SPRITE_SIZE_X;
}


