//Editor: Keenan Longair
//Last update: 12:40PM March 17th, 2016.
//Pupose: The Jukebox.h and .cpp files provide basic .wav sounds to begin
//played. Use the PlaySound function with the filename as the input to 
//play a sound.
//Version: 0.5

#ifndef Jukebox_H_
#define Jukebox_H_

//Libraries required:
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_audio.h>

class Jukebox {
	
	private: 
		
		//MixAudio sets up the audio to allow playback.
		static void MixAudio(void *unused, Uint8 *stream, int len);
   
	public:
   
		//The init function to set up the audio. CALL THIS ONLY ONCE!
		static bool init();
		//Play a sound passing the filename in as the parameter.
		static void PlaySound(const char *file);
		static void PlayBackground();//This plays the background song.
		
		//Extra goals, functions for the future::
		//static void PlayItemPickUp();//Plays the sound made when picking up an item.
		//static void PlayAttack();//Plays the sound made when attacking.
		//static void PlayHealthPotionSound();//Plays the health potion use sound.
		//static void PlayStepSound();//Plays the sound of a step in the game.
		//static void PlayBossTheme();//Plays the Boss theme song.
		//static void PlayHeartPickUp();//Plays the sound made when picking up a heart.
		//static void PlayZAttack();//Plays the attack sound made by Zombies.
	 
};

#endif /* Jukebox_H_ */
