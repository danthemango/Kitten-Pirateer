//Editor: Keenan Longair
//Last update: 12:00PM March 12th, 2016.
//Pupose: The Jukebox.h and .cpp files provide basic .wav sounds to begin
//played. Use the PlaySound function with the filename as the input to 
//play a sound.
//Version: 0.4

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
		static void PlayBackground();
		
		//Extra goals, functions for the future::
		//static void PlayHurt(const char *file);//Plays the sound made when hurt.
		//static void PlayAttack(const char *file);//Plays the sound made when attacking.
		//static void PlayMoan(const char *file);//Plays the sound made by Zombies.
	 
};

#endif /* Jukebox_H_ */
