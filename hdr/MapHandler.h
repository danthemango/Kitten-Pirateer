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
#define MAXOBS 30


#include "GameObject.h"
#include "Obstacle.h"
#include "ObjectFactory.h"
#include <SOIL/SOIL.h>
#include "ImageLoader.h"


class MapHandler: public GameObject {

private:
	
	Obstacle m_obs[MAXOBS];
    GLuint m_tileTextureArray[NUMTILES];
    int m_currTile = 3; 
    int m_numObs[NUMTILES] = {22,22,23,25,22,24,27,26,25};
    
    double ***m_obs3DArray;
    
    MapHandler(MapHandler const&);
    void operator=(MapHandler const&);
    MapHandler()
    {
	m_tileTextureArray[0] = ImageLoader::LoadTexture("./imgs/tile0.png");
	m_tileTextureArray[1] = ImageLoader::LoadTexture("./imgs/tile1.png");
	m_tileTextureArray[2] = ImageLoader::LoadTexture("./imgs/tile2.png");
	m_tileTextureArray[3] = ImageLoader::LoadTexture("./imgs/tile3.png");
	m_tileTextureArray[4] = ImageLoader::LoadTexture("./imgs/tile4.png");
	m_tileTextureArray[5] = ImageLoader::LoadTexture("./imgs/tile5.png");
	m_tileTextureArray[6] = ImageLoader::LoadTexture("./imgs/tile6.png");
	m_tileTextureArray[7] = ImageLoader::LoadTexture("./imgs/tile7.png");
	m_tileTextureArray[8] = ImageLoader::LoadTexture("./imgs/tile8.png");
	}
    ~MapHandler(){};
    
public:
	
	static MapHandler &getInstance()
	{
		static MapHandler instance;
		return instance;
		};
	
	int getNumObstacles() {return m_numObs[m_currTile];};
	Obstacle getObstacles() {return *m_obs;};
	GLuint getTile(int n){return m_tileTextureArray[n];};
	
	void updateTile(int x);
	
	
	void update (){};
	void display (){};
	bool collide (Player *C){};
	
	
};

#endif 
