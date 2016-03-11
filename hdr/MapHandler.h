// **********************************************
// Filename: MapHandler.h
// Author: Nathan Hogman
// Date: 2016-02-22
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//	This Singleton Class is responsible for the core of the interactions with the Map
//	It is a key component for handling the switches between tiles and giving the Enemy spawn location
// 	and item locations to their respective handlers as per each tile. This Class will also be able to handle the switching
// 	between levels. Being able to call a proxy class ObsArr To construct a data array from input files generated from
// 	a map creating open source program called Tiled (tm). Then using a Python script to convert it into a space delimitated
// 	file to be read in from the parameter in calling ObsArr.
//
//	I make it very easy to interact as i give data to various other classes and also there are not to many calls needed 
//	actually be made, as this class is very self sufficient.
//   
// ************************************************

#ifndef MAPHANDLER_H_
#define MAPHANDLER_H_
#define NUMTILES 9
#define MAXOBS 40

#include "Game.h"
#include "Obstacle.h"
#include "ObjectFactory.h"
#include <SOIL/SOIL.h>
#include "ImageLoader.h"
#include "ObsArr.h"
#include "Shapes.h"

class MapHandler {

private:
	
	//Array of Obstacles set to the Max amount
	Obstacle m_obs[MAXOBS];
    
    //array of textures for each of the tiles
    GLuint m_tileTextureArray[NUMTILES];
    
    //int to keep track of the current tile   
    int m_currTile; 
    
    //pointer to an array of the number of obstacles in each corresponding tile
    int *m_numObs;
    
    //number of tiles used when the game is expanded to varrying tile sized levels
    int m_numTiles;
    
    //Creates a pointer to the ObsArr class that will be used as a proxy for the obstacle data
    ObsArr *m_ObstacleArr;
    
    
    MapHandler(MapHandler const&);
    void operator=(MapHandler const&);
    
    MapHandler()
    {
		//	Initializes the MapHandler setting up the First Level
		m_currTile = 3;
		
		//Creates a new 3D Obstacle Array that contains the obstacle Data
		m_ObstacleArr = new ObsArr("./config/INPUT_OBS");
		m_numTiles = m_ObstacleArr->numTiles();
		m_numObs = m_ObstacleArr->numObsArr();
		
		//Sets up the Array of texture for the First Level
		m_tileTextureArray[0] = ImageLoader::LoadTexture("./imgs/tile0.png");
		m_tileTextureArray[1] = ImageLoader::LoadTexture("./imgs/tile1.png");
		m_tileTextureArray[2] = ImageLoader::LoadTexture("./imgs/tile2.png");
		m_tileTextureArray[3] = ImageLoader::LoadTexture("./imgs/tile3.png");
		m_tileTextureArray[4] = ImageLoader::LoadTexture("./imgs/tile4.png");
		m_tileTextureArray[5] = ImageLoader::LoadTexture("./imgs/tile5.png");
		m_tileTextureArray[6] = ImageLoader::LoadTexture("./imgs/tile6.png");
		m_tileTextureArray[7] = ImageLoader::LoadTexture("./imgs/tile7.png");
		m_tileTextureArray[8] = ImageLoader::LoadTexture("./imgs/tile8.png");
		 
		//creates the first array of Obstacles for the initial Tile
		
		for(int i=0;i<m_numObs[m_currTile];i++)
		{
			m_obs[i] = ObjectFactory::createObstacle
			(
				m_ObstacleArr->m_array[m_currTile][i][0],
				m_ObstacleArr->m_array[m_currTile][i][1],
				m_ObstacleArr->m_array[m_currTile][i][2],
				m_ObstacleArr->m_array[m_currTile][i][3],
				m_ObstacleArr->m_array[m_currTile][i][4]
			);
		}
	}
    
    ~MapHandler()
    {
		delete m_ObstacleArr;
	};
    
public:
	
	// Allows for others to get this instance of the singleton map handler
	
	static MapHandler &getInstance()
	{
		static MapHandler instance;
		return instance;
		};
	
	// Returns the number of obstacles in the current tile
	
	int getNumObstacles() {return m_numObs[m_currTile];};
	
	// Returns a pointer to the array of Obstacles in the current tile
	Obstacle* getObstacles() {
	   Obstacle * pointer;
	   pointer = m_obs;
	   return pointer;};
	
	// Returns the texture of the current tile
	
	GLuint getTile(int n){return m_tileTextureArray[n];};
	
	// Switches the tile to a new tile, Updates the information in maphandler, including constructing new obstacles 
	// in the new tile
	
	void updateTile(int x);
	
	// Returns a Rectangle(square) that the zombies can spawn in on the current tile
	Square* zombieSpawnArea(); 
	
};

#endif 
