// **********************************************
// Filename:   ZombieHandler.h
// Author:     Daniel Guenther
// Date:       2016-02-25
// Class:      CSCI 331
// Project:    Kitty Pirateer
// 
// Purpose: 
//    To set defaults shared in the project
// ************************************************
#ifndef CONFIG_H
#define CONFIG_H

// number of tiles in the map
#define NUM_TILES_X 3
#define NUM_TILES_Y 3
// size of the screen
//TODO please enter the correct number
#define SCREEN_SIZE_X 200
#define SCREEN_SIZE_Y 200 

//default sprite size
#define SPRITE_SIZE_X 30 //width
#define SPRITE SIZE_Y 30 //height

//default player start position
#define PLAYER_START_X 500
#define PLAYER_START_y 500

// maximum number of zombies on a single screen-tile
#define MAXZOMBIES 20
// path to the zombie configuration file
#define ZOMBIE_CONFIG_PATH "../config/Zombies"

#endif
