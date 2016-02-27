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

// default sprite size
#define SPRITE_SIZE_X 30
#define SPRITE_SIZE_Y 30

#define START_TILE 3

// number of tiles in the map
#define NUM_TILES_X 3
#define NUM_TILES_Y 3

// size of the screen
#define SCREEN_SIZE_X 800//Width
#define SCREEN_SIZE_Y 1000//Height

//default player start position
#define PLAYER_START_X 500
#define PLAYER_START_Y 500

// maximum number of zombies on a single screen-tile
#define MAXZOMBIES 20
// path to the zombie configuration file
#define ZOMBIE_CONFIG_PATH "../config/Zombies"

//Margine size
//TODO set up the correct margine size.
#define MARGIN 4
//Max number of Objects.
//TODO determine if this is needed when the handlers are in control
//of how many obects there are.
#define MAX_OBJECTS 50

#endif
