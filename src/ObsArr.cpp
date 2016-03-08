#include "../hdr/ObsArr.h"

ObsArr::ObsArr(string file)
{
	ifstream f;
	f.open(file,std::ifstream::in);
	
	//Reads in number of tiles
	f >> m_numTiles;
	
	//creates a starter array to get the number of obstacles in each tile
	
	m_numObs = new int[m_numTiles];
	
	for(int i=0;i<m_numTiles;i++){
      f>> m_numObs[i];
	}
	
	//reads in the number of attributes of each obstacle
	
	f >> m_numAttributes;
	
	
	//Creates the 3D array of the correct size needed
	
	m_array = new int**[m_numTiles];
	for(int k=0;k<m_numTiles;k++){

      m_array[k] = new int*[m_numObs[k]];

      for(int j=0;j<m_numObs[k];j++){
         m_array[k][j] = new int[m_numAttributes];
      }
	}
	
	// Reads in the data into the array
	
	for(int k=0;k<m_numTiles;k++){
      for(int j=0;j<m_numObs[k];j++){
         for(int i=0;i<m_numAttributes;i++){

            f >> m_array[k][j][i];
         }
      }
	}
	
	
	
}

ObsArr::~ObsArr()
{
	for(int k=0;k<m_numTiles;k++){
      for(int j=0;j<m_numObs[k];j++){
        delete [] m_array[k][j];
      }
      delete [] m_array[k];
	}
	delete [] m_array;
	
	delete [] m_numObs;
}
