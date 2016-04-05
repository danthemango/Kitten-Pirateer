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

//Debug message variable. True = display debug messages in terminal. False = do not display debug
//messages in terminal.
#define DEBUG false

// default sprite size
#define SPRITE_SIZE_X 30
#define SPRITE_SIZE_Y 30

#define START_TILE 3

// number of tiles in the map
#define NUM_TILES 9
#define NUM_TILES_X 3
#define NUM_TILES_Y 3

//player movement speed
#define PLAYER_SPEED 1.0

//Size of the screen
#define SCREEN_SIZE_X 1054//Width
#define SCREEN_SIZE_Y 1054//Height

//default player start position
#define PLAYER_START_X 186
#define PLAYER_START_Y 454

//default sprite size
#define SPRITE_SIZE_X 30 //width
#define SPRITE SIZE_Y 30 //height

//default Player Health
#define MAX_PLAYER_HEALTH 100

// maximum number of zombies on a single screen-tile
#define MAXZOMBIES 20
/// number of zombies in each tile
#define NUM_ZOMBIES 5

// path to the zombie configuration file
#define ZOMBIE_CONFIG_PATH "../config/Zombies"

//Margine size
//TODO set up the correct margine size.
#define MARGINE 5
#define HUD_WIDTH 200

//Max number of Objects.
//TODO determine if this is needed when the handlers are in control
//of how many obects there are.
#define MAX_OBJECTS 50

//Starting tile:
//Set this to the starting tile required.
#define START_TILE 3

//Sound files:
#define NUM_SOUNDS 10//This defines how many sounds the jukebox class will have.
#define THEME_SONG "./sounds/Song.wav"
#define ITEM_PICKUP_SOUND "./sounds/ItemPickUp.wav"
#define Z_ATTACK_SOUND "./sounds/ZombieAttack2.wav"
#define ATTACK_SOUND "./sounds/Sword2.wav"
#define HEART_PICKUP_SOUND "./sounds/HeartPickUp.wav"
#define HEALTH_POTION_SOUND "./sounds/HealthPotionUse.wav"
#define BOSS_THEME "./sounds/BossMusic.wav"
#define STEP_SOUND "./sounds/Step.wav"

//Menu textures:
//If we need to change the menu image names we can easily change them here
//without going into the Menu.cpp or Menu.h files.
#define MAIN_MENU "./imgs/menus/mainmenu.png"
#define PAUSE_MENU "./imgs/menus/pausemenu.png"
#define WIN_SCREEN "./imgs/menus/winscreen.png"
#define LOSE_SCREEN "./imgs/menus/losescreen.png"
#define QUIT_SCREEN "./imgs/menus/quitconfirmation.png"
#define ESCAPE_SCREEN "./imgs/menus/escapemenu.png"
#define RESTART_SCREEN "./imgs/menus/restartconfirmation.png"
//#define OBJECTIVE_SCREEN ""//Possibility to have a screen to display the objective.

#endif
