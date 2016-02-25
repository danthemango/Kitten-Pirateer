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

// returns the currently existing instance
// NOTE: only access methods of this class with ZombieHandler::getInstance().methodname()
static ZombieHandler::ZombieHandler &getInstance()
{
   static ZombieHandler *instance = new ZombieHandler;
   return *instance; // alway return same instance
}

ZombieHandler::ZombieHandler()
{
   // load the zombies
   loadZombies();
}

ZombieHandler::~ZombieHandler()
{
   //TODO
}

// updates all contained zombies
void ZombieHandler::update()
{
   for(int i = 0; i < m_numZombies; i++){

}

// draws all zombies
void ZombieHandler::display()
{
   //TODO
}

// damages every Zombie in the range
// x1 y1 - bottom left corner coordinates
// x2 y2 - top right corner coordinates
// int damage - damage amount
void ZombieHandler::attacked(int x1, int y1, int x2, int y2, int damage)
{
   //TODO
}

// tell the ZombieHandler we're moving to the next tile
void ZombieHandler::down()
{
   //TODO
}

void ZombieHandler::up()
{
   //TODO
}

void ZombieHandler::left()
{
   //TODO
}

void ZombieHandler::right()
{
   //TODO
}

// load zombie positions from config/Zombies
void ZombieHandler::loadZombies()
{
   //TODO
}

// turn all zombies into corpses
void ZombieHandler::killAllZombies()
{
   //TODO
}

// make all zombies disappear
void ZombieHandler::disappearAllZombies()
{
   //TODO
}
