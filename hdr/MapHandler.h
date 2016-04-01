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
#define NUMLEVELS 2
#define MAXOBS 45
#define STARTINGLEVEL 0

#include "Game.h"
#include "Obstacle.h"
#include "ObjectFactory.h"
#include <SOIL/SOIL.h>
#include "ImageLoader.h"
#include "ObsArr.h"
#include "Shapes.h"

class MapHandler {

private:
	
	int m_levelStartTile[NUMLEVELS] = {3,2};
	
	const char* m_level0TilesetPNG[NUMTILES] = {
			"./config/PNG/level0/tile0.png",
			"./config/PNG/level0/tile1.png",
			"./config/PNG/level0/tile2.png",
			"./config/PNG/level0/tile3.png",
			"./config/PNG/level0/tile4.png",
			"./config/PNG/level0/tile5.png",
			"./config/PNG/level0/tile6.png",
			"./config/PNG/level0/tile7.png",
			"./config/PNG/level0/tile8.png"};
			
	const char* m_level1TilesetPNG[NUMTILES] = {
			"./config/PNG/level1/tile0.png",
			"./config/PNG/level1/tile1.png",
			"./config/PNG/level1/tile2.png",
			"./config/PNG/level1/tile3.png",
			"./config/PNG/level1/tile4.png",
			"./config/PNG/level1/tile5.png",
			"./config/PNG/level1/tile6.png",
			"./config/PNG/level1/tile7.png",
			"./config/PNG/level1/tile8.png"};
	
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
		m_currTile = m_levelStartTile[STARTINGLEVEL];
		
		//Creates a new 3D Obstacle Array that contains the obstacle Data
		m_ObstacleArr = new ObsArr("./config/INPUT_OBS_LEVEL0");
		m_numTiles = m_ObstacleArr->numTiles();
		m_numObs = m_ObstacleArr->numObsArr();
		
		//Sets up the Array of texture for the First Level
		for (int i = 0;i<NUMTILES;i++)
		{
			m_tileTextureArray[i] = ImageLoader::LoadTexture(m_level0TilesetPNG[i]);
		}
		
		 
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
	
	
	// Updates the Level to the selected level (level0 being the first level and so forth)
	
	void updateLevel(int x);
	
};

#endif 
