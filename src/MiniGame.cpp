//Edited by: Keenan Longair.
//Last update: 10:30AM March 20th, 2016.
//Purpose: Contains the implementation of the multi-inheritance class called Minigame.
//Version: 0.1
//**************************************************************************************

//Required Libraries:
#include <cstdio>
#include <stdlib.h>
#include <GL/glut.h>/*glut.h includes gl.h and glu.h*/
#include <math.h>
#include <time.h>
#include <GL/freeglut.h>

//Required Files:
#include "../hdr/config.h"
#include "../hdr/MiniGame.h"
#include "../hdr/Game.h"
#include "../hdr/ImageLoader.h"

//By inheriting from Game and ImageLoader, MiniGame is able to load and create its own
//instance within the game so that the user may, in the future, be able to play small 
//ingame puzzle games. By inheriting from ImageLoader, MiniGame is able to directly 
//load its own textures as needed with any changes that are required. By inheriting 
//from Game, MiniGame can create its own instance and use the control functions already
//define in game with modifications to create specific controls for the MiniGame's.
//This alllows MiniGame the ability to load up its own textures while having custom 
//settings for controls and the game loop. The implementation has not been created 
//but this would be used as future DLC.