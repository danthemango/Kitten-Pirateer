//Editor: Keenan Longair
//Last Update:Jan23, 2016 @2:30pm.
//Pupose: The Jukebox.h and .cpp files provide basic .wav sounds to begin
//played. Use the PlaySound function with the filename as the input to 
//play a sound.
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
     //The init function to set up the audio. Call this once.
     static bool init();
     //Play a sound passing the filename in as the parameter.
     static void PlaySound(const char *file);
};

#endif /* Jukebox_H_ */
