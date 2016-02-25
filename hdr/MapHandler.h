// **********************************************
// Filename: MapHandler.h
// Author: Nathan Hogman
// Date: 2016-02-22
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//
// 
//    
// ************************************************



#ifndef MAPPHANDLER_H_
#define MAPHANDLER_H_
#define NUMTILES 9
#define ATTRIBUTES 5
#define MAXOBS 50


#include "GameObject.h"
#include "Obstacle.h"
#inlcude "ObjectFactory.h"


class MapHandler: public GameObject {

private:
	
	Obstacle m_obs[MAXOBS];
    GLuint m_tileTextureArray[NUMTILES];
    
    int m_currTile; 
    int m_numObs[NUMTILES] = {22,22,23,25,22,24,27,26,25};
    
    double ***m_obs3DArray;
    
public:
	
	int getNumObstacles() {return m_numObs[m_currTile]};
	Obstacle getObstacles() {return m_obs;};
	Gluint getTile() {return m_tileTextureArray[m_currTile];};
	
	void updateTile(int x);
	
	MapHandler(int x);
	
	void update();
	
};

#endif MAPHANDLER_H_