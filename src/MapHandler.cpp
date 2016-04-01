// **********************************************
// Filename: MapHandler.cpp
// Author: Nathan Hogman
// Date: 2016-02-23
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//
// 
//    
// ************************************************


#include "../hdr/MapHandler.h"
#include <string.h>
#include "../hdr/ObjectFactory.h"

//***********************************************************//

void MapHandler::updateTile(int x)
{
   
   //sets current tile number to the new tile number
   m_currTile = x;


   //uses the factory to construct new obstacles in the tile
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
	
	Game::getInstance().updateTile(m_tileTextureArray[x]);

}

//Zombie Spawn area will always be the First obstacle on any tile 
//***This has to be taken into account when making new Maps****

Square* MapHandler::zombieSpawnArea()
{
	int x1 = m_ObstacleArr->m_array[m_currTile][0][0];
	int y1 = m_ObstacleArr->m_array[m_currTile][0][1];
	int x2 = m_ObstacleArr->m_array[m_currTile][0][0] + m_ObstacleArr->m_array[m_currTile][0][2];
	int y2 = m_ObstacleArr->m_array[m_currTile][0][1] + m_ObstacleArr->m_array[m_currTile][0][3];
	
	Square *Area = new Square(x1,y1,x2,y2);
	
	return Area;
	
}

void MapHandler::updateLevel(int x)
{
	delete m_ObstacleArr;
	
	
	
	
}
