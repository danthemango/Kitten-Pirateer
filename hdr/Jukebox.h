//Editor: Keenan Longair
//Last update:  5:30PM March 23rd, 2016.
//Pupose: The Jukebox.h and .cpp files provide basic .wav sounds to begin
//played. Use the PlaySound function with the filename as the input to 
//play a sound.
//Version: 0.6

#ifndef Jukebox_H_
#define Jukebox_H_

//Libraries required:
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_audio.h>

//DrJ Encapsulation
//Jukebox is a good example of encapsulation because only the relevant info
//is displayed to the interface users while how it is done is hidden.
//Definition: Prevents the data from unwanted access by binding of code and 
//data in a single unit called object. Implementation is hidden from the 
//outside world. Only method signature is outward-facing and is accessible 
//from outside. This is called object interface. This can be thought of as a 
//black box kind of device. Inside the black box is the mechanical code and 
//the data. We can’t see how the black box does its job but we can access 
//the output through its interface. Thus the implementation is encapsulated 
//within this black box which is considered an object.

class Jukebox {
	
	private: 
		
		//MixAudio sets up the audio to allow playback.
		static void MixAudio(void *unused, Uint8 *stream, int len);
   
	public:
   
		//The init function to set up the audio. CALL THIS ONLY ONCE!
		static bool init();
		//Play a sound passing the filename in as the parameter.
		static void PlaySound(const char *file);//This function handles prototype
		//sounds. A specific sound function is created for each sound after it is
		//tested.
		static void PlayBackground();//This plays the background song.
		static void PlayItemPickUp();//Plays the sound made when picking up an item.
		static void PlayAttack();//Plays the sound made when attacking.
		static void PlayHealthPotionSound();//Plays the health potion use sound.
		static void PlayStepSound();//Plays the sound of a step in the game.
		static void PlayBossTheme();//Plays the Boss theme song.
		static void PlayHeartPickUp();//Plays the sound made when picking up a heart.
		static void PlayZAttack();//Plays the attack sound made by Zombies.
	 
};

#endif /* Jukebox_H_ */
