// **********************************************
// Filename: creatureFileParser.h
// Author: Daniel Guenther
// Date: 2016-03-27
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//    reads the creatureFile and returns a creature's signature
// ************************************************

#ifndef CREATUREFILEPARSER_H
#define CREATUREFILEPARSER_H

#include <string>
#include <fstream>
using namespace std;

// container for a creature's signature
// a signature is the creature's name and initial position (if not random)
class creatureSignature{
   public:
      // creates the signature with a specific position
      creatureSignature(string name, int world, int tile, int x, int y);
      // creates a signature with random position
      creatureSignature(string name, int world, int tile);
      // returns true if the creature has been created with random position
      bool isRandom();
      // returns the creature's position
      // returns 0 if it was supposed to be random
      int getX();
      int getY();
      // returns the creatures world and tile
      int getWorld();
      int getTile();
   private:
      // name
      string m_name;
      // position
      int m_x, m_y, m_world, m_tile;
      // true if creature isn't supposed to have a set initial position
      bool m_isRandom;
};

// creatureFileParser
// allows for developing creatureSignatures based on a well formatted creature-configuration-file
class creatureFileParser{
   public:
      // opens the file specified in filename
      creatureFileParser(string filename);
      // closes the file
      ~creatureFileParser();
      // returns true when creature's signature can be received with get()
      // false at the end of the file or if an error was encountered
      bool next();
      // returns the current creature's profile
      // (retains ownership of the pointer)
      creatureSignature* get();
   private:
      // the file being read
      ifstream m_file;
      // pointer to the current creature read
      creatureSignature* m_curr;
      // current world and tile
      int m_world, m_tile;
};
#endif
