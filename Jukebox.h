//Editor: Keenan Longair
//Last Update: 8:30PM February 8th, 2016.
//Pupose: The Jukebox.h and .cpp files provide basic .wav sounds to begin
//played. Use the PlaySound function with the filename as the input to 
//play a sound.
//Version: 0.3

#ifndef Jukebox_H_
#define Jukebox_H_

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_audio.h>

class Jukebox {
	
	private: 
   
		static void mixaudio(void *unused, Uint8 *stream, int len);
   
	public:
   
		//The init function to set up the audio. CALL THIS ONLY ONCE!
		static bool init();
		//Play a sound passing the filename in as the parameter.
		static void PlaySound(const char *file);
		
		//Following functions are extra goals if time allows:
		//static void PlayHurt(const char *file);//Plays the sound made when hurt.
		//static void PlayAttack(const char *file);//Plays the sound made when attacking.
		//static void PlayMoan(const char *file);//Plays the sound made by Zombies.
	 
};

#endif /* Jukebox_H_ */
