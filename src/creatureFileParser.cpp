// **********************************************
// Filename: creatureFileParser.cpp
// Author: Daniel Guenther
// Date: 2016-03-27
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//    reads the creatureFile and returns a creature's signature
// ************************************************

#include "../hdr/config.h"
#include <iostream>
#include "../hdr/creatureFileParser.h"
using namespace std;

// *************** creatureSignature ************
// creates the signature with a specific position
creatureSignature::creatureSignature(string name, int world, int tile, int x, int y)
{
   // initialize contents
   m_name = name;
   m_x = x;
   m_y = y;
   m_world = world;
   m_tile = tile;
   m_isRandom = false;
}

// creates a signature with random position
creatureSignature::creatureSignature(string name, int world, int tile)
{
   // initialize contents
   m_name = name;
   m_world = world;
   m_tile = tile;
   m_isRandom = true;
}

// returns true if the creature has been created with random position
bool creatureSignature::isRandom()
{
   return m_isRandom;
}

// returns the creature's position
// returns 0 if it was supposed to be random
int creatureSignature::getX()
{
   return m_x;
}

int creatureSignature::getY()
{
   return m_y;
}

// returns the creatures world
int creatureSignature::getWorld()
{
   return m_world;
}

// returns the creatures tile
int creatureSignature::getTile()
{
   return m_tile;
}

// ************* creatureFileParser *******
// opens the file specified in filename
creatureFileParser::creatureFileParser(string filename)
{
   // ensure file is successfully open
   m_file.open(filename);
   if(m_file.fail()){
      cerr << "creatureFileParser:: " << filename << "could not be opened" << endl;
   }
   m_curr = NULL;
}

// closes the file
creatureFileParser::~creatureFileParser()
{
   // close the file 
   if(m_file.is_open()){
      m_file.close();
   }
   // delete creatureSignature
   if(m_curr){
      delete m_curr;
   }
}

// returns true when creature's signature can be received with get()
// false at the end of the file
bool creatureFileParser::next()
{
   // ensure a file is open to be read
   if(!m_file.is_open()){
      return false;
   }
   
   // delete the previous creature, if any
   if(m_curr){
      delete m_curr;
   }

   // get the next word in the file
   string buffer;
   m_file >> buffer;
}

// returns the current creature's profile
creatureSignature* creatureFileParser::get()
{
   return m_curr;
}

