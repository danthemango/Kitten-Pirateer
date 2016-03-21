//Edited by: Keenan Longair.
//Last update: 10:30AM March 20th, 2016.
//Purpose: Prototyping of the MiniGame class.
//Version: 0.1
//**************************************************************************************

#ifndef MINIGAME_H_
#define MINIGAME_H_

//Required Libraries:
#include <stdlib.h>
#include <GL/glut/h>
#include <SOIL/SOIL.h>

//Required Files:
#include "../hdr/config.h"
#include "../hdr/Game.h"
#include "../hdr/ImageLoader.h"

//MiniGame class definition:
class MiniGame {

	private:
	
		MiniGame() { };
		MiniGame(MiniGame const&);
		void operation=(MiniGame const&);
	
	public:

		static MiniGame& getInstance()
		{
			
			static MiniGame instance;
			return instance;
			
		};
		
		void keyUp(unsigned char key, int x, int y);
		void key(unsigned char key, int x, int y);
		void keyOperations();
		void run();
		void idle();
		void timer(int id);
		void update();
		void init();
		int LoadImage(char *filename);
		GLuint LoadTexture(const char *filename);
		
};

#endif