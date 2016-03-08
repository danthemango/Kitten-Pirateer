// **********************************************
// Filename: Obstacle.h
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: Parent class for obstacles found in the games 2D top down maps . 
// These obstacles as of now will all be simple rectangular structure.
// though they can be combined to form other more complex shapes. 
//
// For each map we will be building an list or array of these structures 
// unique to each tile that is displayed at a time
//    
// ************************************************



#ifndef OBSARR_H_
#define OBSARR_H_
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

class ObsArr;

class ObsArr
{

private:
	int m_numTiles, m_numAttributes;
	int *m_numObs;
	//int ***m_array;
    
public:
	
	int ***m_array;
	int numTiles() {return m_numTiles;};
	int* numObsArr() {return m_numObs;};
	ObsArr(string file);
	~ObsArr();
	
};

#endif /*OBSTACLE_H_*/
