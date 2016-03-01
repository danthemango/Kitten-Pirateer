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
   //deletes obstacles from previous tile
   /*
   for(int i=0;i<m_numObs[m_currTile];i++)
   {
      delete m_obs[i];
   }
	*/

   //sets current tile number to the new tile number
   m_currTile = x;


   //uses the factory to construct new obstacles in the tile
   for(int i=0;i<m_numObs[m_currTile];i++)
   {
      m_obs[i] = ObjectFactory::createObstacle
         (
          m_obs3DArray[m_currTile][i][0],
          m_obs3DArray[m_currTile][i][1],
          m_obs3DArray[m_currTile][i][2],
          m_obs3DArray[m_currTile][i][3],
          m_obs3DArray[m_currTile][i][4]
         );
   }
	
	//Game::getInstance.updateTile(m_tileTextureArray[x]);
	//ZombieHandler::getInstance.updateTile(x);
	//ItemHandler::getInstance.updateTile(x);

}

