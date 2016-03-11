// **********************************************
// Filename: ObsArr.h
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//	A proxy class to hold information that will be used for more memory intensive things 
// 	in the future. For example obstacle data and item data. Takes the information in
//	from a space delimnated file in a format that a python script tmx2txt.py outputs
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
	// number of Tiles in the Level
	int m_numTiles;
	// number of Attributes array[][][x]
	int m_numAttributes;
	// pointer to an array containing the number of obstacles in each tile
	int *m_numObs;
    
public:
	// 3D array pointer
	int ***m_array;
	// returns the number of tiles in the level
	int numTiles() {return m_numTiles;};
	// returns a pointer to the array of number of obstacles in each tile
	int* numObsArr() {return m_numObs;};
	// contructor that takes in a space deliminated file name as a parameter
	ObsArr(string file);
	~ObsArr();
	
};

#endif /*OBSTACLE_H_*/
