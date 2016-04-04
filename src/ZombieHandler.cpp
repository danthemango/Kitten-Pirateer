// **********************************************
// Filename:   ZombieHandler.cpp
// Author:     Daniel Guenther
// Date:       2016-02-25
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    instatiates and holds Zombies (objects)
// ************************************************

#include "../hdr/ZombieHandler.h"
#include "../hdr/config.h"
#include "../hdr/Player.h"

// load the positions of the zombies 
void ZombieHandler::loadZombies()
{
   // TODO put zombies in better positions
   // add the positions of the zombies
   m_map[1].add(3,3);
   m_map[1].add(300,300);
   m_map[1].add(500,300);
   m_map[2].add(3,3);
   m_map[2].add(300,300);
   m_map[2].add(500,300);
   m_map[3].add(3,3);
   m_map[3].add(300,300);
   m_map[3].add(500,300);
   m_map[4].add(3,3);
   m_map[4].add(300,300);
   m_map[4].add(500,300);
   m_map[5].add(3,3);
   m_map[5].add(300,300);
   m_map[5].add(500,300);
   m_map[6].add(3,3);
   m_map[6].add(300,300);
   m_map[6].add(500,300);
   m_map[7].add(3,3);
   m_map[7].add(300,300);
   m_map[7].add(500,300);
   m_map[8].add(3,3);
   m_map[8].add(300,300);
   m_map[8].add(500,300);
   m_map[9].add(3,3);
   m_map[9].add(300,300);
   m_map[9].add(500,300);
}

// returns the current instance
ZombieHandler &ZombieHandler::getInstance()
{
   static ZombieHandler *c_instance = new ZombieHandler;
   return *c_instance; // alway return same instance
}

ZombieHandler::ZombieHandler()
{
   // load the zombies
   loadZombies();
   for(int i = 0; i < MAXZOMBIES; i++){
      m_ZombieList[i] = new Zombie;
   }
   updateTile(START_TILE);
}

ZombieHandler::~ZombieHandler()
{
   for(int i = 0; i < MAXZOMBIES; i++){
      delete m_ZombieList[i];
   }
}

// updates all contained zombies
void ZombieHandler::update()
{
   
   for(int i = 0; i < m_num_zombies; i++){
      m_ZombieList[i]->update(Player::getInstance().getX(),Player::getInstance().getY());
   }
}

// draws all zombies
void ZombieHandler::display()
{
   for(int i = 0; i < m_num_zombies; i++){
      m_ZombieList[i]->display();
   }
}

// damages every Zombie in the range
// x1 y1 - bottom left corner coordinates
// x2 y2 - top right corner coordinates
// int damage - damage amount
void ZombieHandler::attacked(int x1, int y1, int x2, int y2, int damage)
{
   for(int i = 0; i < m_num_zombies; i++){
      m_ZombieList[i]->attacked(x1,y1,x2,y2, damage);
   }
}

// turn all zombies into corpses
void ZombieHandler::killAllZombies()
{
   for(int i = 0; i < m_num_zombies; i++){
      m_ZombieList[i]->kill();
   }
}

// make all zombies disappear
void ZombieHandler::removeAllZombies()
{
   for(int i = 0; i < m_num_zombies; i++){
      m_ZombieList[i]->disappear();
   }
}

// switch to a new tile
void ZombieHandler::updateTile(int x)
{
   if(x > NUM_TILES || x < 1){
      return;
   }
   m_tile = x;
   // get the current zombie map
   PositionMap &curmap = m_map[m_tile];
   m_num_zombies = curmap.size();
   
   // cap the number of zombies
   if(m_num_zombies > MAXZOMBIES){
      m_num_zombies = MAXZOMBIES;
   }
   // ensure the superfluous zombies aren't on the map
   for(int i = MAXZOMBIES-1;i > m_num_zombies-1; i--){
      m_ZombieList[i]->disappear();
   }
   int i = 0;
   // spawn the zombies at the specified locations
   for(PositionMap::Iterator zombiePoint = curmap.Begin();
         zombiePoint != curmap.End(); zombiePoint++){
      Point ZombiePos(**zombiePoint);
      m_ZombieList[i]->spawn(ZombiePos);
      i++;
   }
}
