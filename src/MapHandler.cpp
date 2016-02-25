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


#include "MapHandler.h"


MapHandler::MapHandler(int n)
{
   //sets value for the current tile
   int m_currTile = n;

   //loads all the tile images into textures
   for(i=0,i<NUMTILES,i++)
   {
      m_tileTextureArray[i] = SOIL_load_OGL_texture
         (
          "tile%s.png" %i,
          SOIL_LOAD_AUTO,
          SOIL_CREATE_NEW_ID,
          SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
         );

   }



   // Allocate memory for array to hold obstacle values 3D array 
   // [number of tiles] by [number of obstacles in that tile] by [attributes of a obstacle] 

   m_obs3DArray[ = new double**[NUMTILES];
   for (int i = 0; i < NUMTILES; ++i) {
      m_obs3DArray[i] = new double*[m_numObs[NUMTILES]];

      for (int j = 0; j < m_numObs[NUMTILES]; ++j)
         m_obs3DArray[i][j] = new double[ATTRIBUTES];
   }

   {
      // Tile 0 obstacles **********************************
      m_obs3DArray[0][0] = {31,990,636,37,136,0};
      m_obs3DArray[0][1] = {32,959,666,35,112,0};
      m_obs3DArray[0][2] = {33,923,699,51,84,0};
      m_obs3DArray[0][3] = {34,893,731,37,46,0};
      m_obs3DArray[0][4] = {36,289,289,483,134,0};
      m_obs3DArray[0][5] = {37,767,412,66,73,0};
      m_obs3DArray[0][6] = {38,893,505,37,41,0};
      m_obs3DArray[0][7] = {39,222,257,76,36,0};
      m_obs3DArray[0][8] = {40,178,283,50,41,0};
      m_obs3DArray[0][9] = {41,153,314,56,27,0};
      m_obs3DArray[0][10] = {42,134,330,61,27,0};
      m_obs3DArray[0][11] = {43,126,340,36,189,0};
      m_obs3DArray[0][12] = {44,140,501,54,150,0};
      m_obs3DArray[0][13] = {45,131,603,254,84,0};
      m_obs3DArray[0][14] = {188,758,260,298,33,0};
      m_obs3DArray[0][15] = {191,1038,280,17,379,0};
      m_obs3DArray[0][16] = {192,1026,623,19,29,0};
      m_obs3DArray[0][17] = {193,864,768,68,62,0};
      m_obs3DArray[0][18] = {194,898,831,47,100,0};
      m_obs3DArray[0][19] = {195,866,898,66,125,0};
      m_obs3DArray[0][20] = {196,897,1024,42,31,0};
      m_obs3DArray[0][21] = {197,346,688,41,367,0};
      // Tile 1 obstacles **********************************
      m_obs3DArray[1][0]={225,925,125,131,0};
      m_obs3DArray[1][1]={0,604,322,196,0};
      m_obs3DArray[1][2]={31,542,259,62,0};
      m_obs3DArray[1][3]={792,258,264,65,0};
      m_obs3DArray[1][4]={734,294,68,72,0};
      m_obs3DArray[1][5]={637,342,107,89,0};
      m_obs3DArray[1][6]={540,394,167,130,0};
      m_obs3DArray[1][7]={543,520,71,127,0};
      m_obs3DArray[1][8]={606,502,74,117,0};
      m_obs3DArray[1][9]={415,430,186,156,0};
      m_obs3DArray[1][10]={411,340,249,131,0};
      m_obs3DArray[1][11]={99,296,372,69,0};
      m_obs3DArray[1][12]={58,326,71,227,0};
      m_obs3DArray[1][13]={123,449,39,118,0};
      m_obs3DArray[1][14]={281,453,42,230,0};
      m_obs3DArray[1][15]={134,500,156,57,0};
      m_obs3DArray[1][16]={3,267,123,275,0};
      m_obs3DArray[1][17]={0,226,549,68,0};
      m_obs3DArray[1][18]={26,749,101,308,0};
      m_obs3DArray[1][19]={258,895,58,43,0};
      m_obs3DArray[1][20]={728,361,44,32,0};
      m_obs3DArray[1][21]={773,313,50,28,0};
      // Tile 2 obstacles **********************************
      m_obs3DArray[2][0]={322,989,178,57,0};
      m_obs3DArray[2][1]={352,961,183,64,0};
      m_obs3DArray[2][2]={417,867,325,114,0};
      m_obs3DArray[2][3]={639,831,186,80,0};
      m_obs3DArray[2][4]={675,768,278,136,0};
      m_obs3DArray[2][5]={704,742,262,72,0};
      m_obs3DArray[2][6]={801,696,179,117,0};
      m_obs3DArray[2][7]={734,572,225,49,0};
      m_obs3DArray[2][8]={765,619,236,80,0};
      m_obs3DArray[2][9]={704,479,293,99,0};
      m_obs3DArray[2][10]={675,382,316,100,0};
      m_obs3DArray[2][11]={641,309,389,76,0};
      m_obs3DArray[2][12]={609,225,431,86,0};
      m_obs3DArray[2][13]={582,214,89,48,0};
      m_obs3DArray[2][14]={352,199,284,61,0};
      m_obs3DArray[2][15]={-264,258,264,65,0};
      m_obs3DArray[2][16]={284,288,358,131,0};
      m_obs3DArray[2][17]={361,242,269,72,0};
      m_obs3DArray[2][18]={372,415,80,67,0};
      m_obs3DArray[2][19]={282,413,94,72,0};
      m_obs3DArray[2][20]={479,441,74,77,0};
      m_obs3DArray[2][21]={288,1022,34,35,0};
      m_obs3DArray[2][22]={2,185,371,109,0};
      // Tile 3 obstacles **********************************
      m_obs3DArray[3][0]={297,256,90,140,0};
      m_obs3DArray[3][1]={291,445,95,35,0};
      m_obs3DArray[3][2]={353,477,100,0};
      m_obs3DArray[3][3]={345,539,41,161,0};
      m_obs3DArray[3][4]={383,672,64,102,0};
      m_obs3DArray[3][5]={291,480,270,0};
      m_obs3DArray[3][6]={57,640,243,90,0};
      m_obs3DArray[3][7]={25,202,67,517,0};
      m_obs3DArray[3][8]={40,227,282,95,0};
      m_obs3DArray[3][9]={158,313,64,38,0};
      m_obs3DArray[3][10]={75,515,114,24,0};
      m_obs3DArray[3][11]={232,514,60,27,0};
      m_obs3DArray[3][12]={309,771,77,132,0};
      m_obs3DArray[3][13]={890,668,77,111,0};
      m_obs3DArray[3][14]={319,889,35,167,0};
      m_obs3DArray[3][15]={995,503,42,553,0};
      m_obs3DArray[3][16]={929,352,100,126,0};
      m_obs3DArray[3][17]={961,475,64,34,0};
      m_obs3DArray[3][18]={931,245,106,61,0};
      m_obs3DArray[3][19]={961,291,57,90,0};
      m_obs3DArray[3][20]={926,163,86,98,0};
      m_obs3DArray[3][21]={897,134,59,55,0};
      m_obs3DArray[3][22]={863,41,83,117,0};
      m_obs3DArray[3][23]={883,2,116,49,0};
      m_obs3DArray[3][24]={331,1,56,265,0};
      // Tile 4 obstacles **********************************
      m_obs3DArray[4][0]={128,222,29,33,0};
      m_obs3DArray[4][1]={225,-131,125,131,0};
      m_obs3DArray[4][2]={256,763,291,69,0};
      m_obs3DArray[4][3]={342,732,143,33,0};
      m_obs3DArray[4][4]={477,591,71,82,0};
      m_obs3DArray[4][5]={669,720,68,87,0};
      m_obs3DArray[4][6]={790,502,78,82,0};
      m_obs3DArray[4][7]={699,404,72,81,0};
      m_obs3DArray[4][8]={469,434,80,89,0};
      m_obs3DArray[4][9]={186,372,136,211,0};
      m_obs3DArray[4][10]={443,215,72,83,0};
      m_obs3DArray[4][11]={505,89,77,83,0};
      m_obs3DArray[4][12]={887,151,79,79,0};
      m_obs3DArray[4][13]={989,594,67,145,0};
      m_obs3DArray[4][14]={1028,575,29,194,0};
      m_obs3DArray[4][15]={896,992,62,63,0};
      m_obs3DArray[4][16]={52,380,78,675,0};
      m_obs3DArray[4][17]={65,189,65,267,0};
      m_obs3DArray[4][18]={100,148,91,75,0};
      m_obs3DArray[4][19]={63,1,68,149,0};
      m_obs3DArray[4][20]={126,128,25,24,0};
      m_obs3DArray[4][21]={251,4,73,28,0};
      // Tile 5 obstacles **********************************
      m_obs3DArray[5][0]={814,979,202,46,0};
      m_obs3DArray[5][1]={767,768,143,237,0};
      m_obs3DArray[5][2]={802,526,139,339,0};
      m_obs3DArray[5][3]={439,446,509,79,0};
      m_obs3DArray[5][4]={98,95,454,416,0};
      m_obs3DArray[5][5]={161,510,320,37,0};
      m_obs3DArray[5][6]={129,68,327,44,0};
      m_obs3DArray[5][7]={192,38,288,72,0};
      m_obs3DArray[5][8]={225,5,240,56,0};
      m_obs3DArray[5][9]={575,796,131,196,0};
      m_obs3DArray[5][10]={638,542,130,201,0};
      m_obs3DArray[5][11]={537,577,45,139,0};
      m_obs3DArray[5][12]={478,701,36,77,0};
      m_obs3DArray[5][13]={448,632,34,78,0};
      m_obs3DArray[5][14]={353,694,32,91,0};
      m_obs3DArray[5][15]={314,604,40,81,0};
      m_obs3DArray[5][16]={384,577,30,70,0};
      m_obs3DArray[5][17]={478,536,43,80,0};
      m_obs3DArray[5][18]={126,762,66,72,0};
      m_obs3DArray[5][19]={768,992,68,65,0};
      m_obs3DArray[5][20]={962,1021,58,35,0};
      m_obs3DArray[5][21]={2,573,128,197,0};
      m_obs3DArray[5][22]={286,1,147,9,0};
      m_obs3DArray[5][23]={225,1,82,11,0};
      // Tile 6 obstacles **********************************
      m_obs3DArray[6][0]={865,767,31,64,0};
      m_obs3DArray[6][1]={201,480,279,441,0};
      m_obs3DArray[6][2]={408,861,269,116,0};
      m_obs3DArray[6][3]={639,799,130,225,0};
      m_obs3DArray[6][4]={750,958,219,79,0};
      m_obs3DArray[6][5]={895,68,64,92,0};
      m_obs3DArray[6][6]={609,480,30,61,0};
      m_obs3DArray[6][7]={574,569,39,39,0};
      m_obs3DArray[6][8]={543,608,34,68,0};
      m_obs3DArray[6][9]={578,672,30,67,0};
      m_obs3DArray[6][10]={609,733,31,69,0};
      m_obs3DArray[6][11]={667,763,44,44,0};
      m_obs3DArray[6][12]={732,763,33,40,0};
      m_obs3DArray[6][13]={791,729,45,73,0};
      m_obs3DArray[6][14]={831,696,31,43,0};
      m_obs3DArray[6][15]={860,630,46,48,0};
      m_obs3DArray[6][16]={824,536,50,77,0};
      m_obs3DArray[6][17]={797,503,36,52,0};
      m_obs3DArray[6][18]={269,1,84,490,0};
      m_obs3DArray[6][19]={928,866,129,100,0};
      m_obs3DArray[6][20]={895,742,162,124,0};
      m_obs3DArray[6][21]={930,256,125,192,0};
      m_obs3DArray[6][22]={960,424,95,53,0};
      m_obs3DArray[6][23]={989,462,66,45,0};
      m_obs3DArray[6][24]={1023,482,33,61,0};
      m_obs3DArray[6][25]={963,218,93,44,0};
      m_obs3DArray[6][26]={992,1,63,218,0};
      // Tile 7 obstacles **********************************
      m_obs3DArray[7][0]={-160,733,321,125,0};
      m_obs3DArray[7][1]={62,701,227,33,0};
      m_obs3DArray[7][2]={93,669,225,31,0};
      m_obs3DArray[7][3]={128,636,190,33,0};
      m_obs3DArray[7][4]={191,574,127,63,0};
      m_obs3DArray[7][5]={222,543,66,32,0};
      m_obs3DArray[7][6]={159,603,32,34,0};
      m_obs3DArray[7][7]={158,734,98,33,0};
      m_obs3DArray[7][8]={161,766,35,64,0};
      m_obs3DArray[7][9]={193,768,31,31,0};
      m_obs3DArray[7][10]={159,866,130,184,0};
      m_obs3DArray[7][11]={273,1024,213,35,0};
      m_obs3DArray[7][12]={448,931,248,109,0};
      m_obs3DArray[7][13]={673,871,194,145,0};
      m_obs3DArray[7][14]={864,867,127,164,0};
      m_obs3DArray[7][15]={896,799,94,133,0};
      m_obs3DArray[7][16]={637,606,197,132,0};
      m_obs3DArray[7][17]={993,859,64,133,0};
      m_obs3DArray[7][18]={510,92,110,197,0};
      m_obs3DArray[7][19]={610,128,294,166,0};
      m_obs3DArray[7][20]={26,2,102,445,0};
      m_obs3DArray[7][21]={104,99,436,127,0};
      m_obs3DArray[7][22]={15,422,83,56,0};
      m_obs3DArray[7][23]={17,470,49,40,0};
      m_obs3DArray[7][24]={2,497,31,50,0};
      m_obs3DArray[7][25]={890,161,167,133,0};
      // Tile 8 obstacles **********************************
      m_obs3DArray[8][0]={66,888,133,35,0};
      m_obs3DArray[8][1]={65,800,259,33,0};
      m_obs3DArray[8][2]={191,816,170,242,0};
      m_obs3DArray[8][3]={288,735,129,293,0};
      m_obs3DArray[8][4]={410,889,38,166,0};
      m_obs3DArray[8][5]={578,804,157,124,0};
      m_obs3DArray[8][6]={700,926,36,65,0};
      m_obs3DArray[8][7]={546,897,31,94,0};
      m_obs3DArray[8][8]={739,675,152,158,0};
      m_obs3DArray[8][9]={864,830,113,228,0};
      m_obs3DArray[8][10]={800,905,102,152,0};
      m_obs3DArray[8][11]={769,255,222,544,0};
      m_obs3DArray[8][12]={898,195,123,120,0};
      m_obs3DArray[8][13]={958,119,82,147,0};
      m_obs3DArray[8][14]={898,27,126,103,0};
      m_obs3DArray[8][15]={802,96,102,31,0};
      m_obs3DArray[8][16]={802,127,33,72,0};
      m_obs3DArray[8][17]={-63,859,64,133,0};
      m_obs3DArray[8][18]={90,94,201,71,0};
      m_obs3DArray[8][19]={478,505,141,199,0};
      m_obs3DArray[8][20]={3,963,63,50,0};
      m_obs3DArray[8][21]={54,984,158,48,0};
      m_obs3DArray[8][22]={2,156,288,135,0};
      m_obs3DArray[8][23]={776,4,58,33,0};
      m_obs3DArray[8][24]={958,5,86,33,0};
   }

   for(i=0,i<m_numObs[m_currTile],i++)
   {
      m_obs[i] = ObstacleFactory::createObstacle
         (
          m_obs3DArray[m_currTile][i][0],
          m_obs3DArray[m_currTile][i][1],
          m_obs3DArray[m_currTile][i][2],
          m_obs3DArray[m_currTile][i][3],
          m_obs3DArray[m_currTile][i][4]
         );

   }

}

//***********************************************************//

MapHandler::updateTile(int x)
{
   //deletes obstacles from previous tile
   for(i=0,i<m_numObs[m_currTile],i++)
   {
      delete m_obs[i];
   }


   //sets current tile number to the new tile number
   m_currTile = x;


   //uses the factory to construct new obstacles in the tile
   for(i=0,i<m_numObs[m_currTile],i++)
   {
      m_obs[i] = ObstacleFactory::createObstacle
         (
          m_obs3DArray[m_currTile][i][0],
          m_obs3DArray[m_currTile][i][1],
          m_obs3DArray[m_currTile][i][2],
          m_obs3DArray[m_currTile][i][3],
          m_obs3DArray[m_currTile][i][4]
         );
   }
}


//***********************************************************//

MapHandler::~MapHandler()
{
   // De-Allocate memory to prevent memory leak
   for (int i = 0; i < NUMTILES; ++i) {
      for (int j = 0; j < m_numObs[NUMTILES]; ++j)
         delete [] obsData[i][j];

      delete [] obsData[i];
   }
   delete [] obsData;
}
