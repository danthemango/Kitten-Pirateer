/*************************************************************
 * Jukebox - a simple class to play WAV files
 * g++ Jukebox.cpp `sdl-config --cflags --libs`  -lSDL_mixer
 * ./sounds/_.wav
 *************************************************************/
//Editor: Keenan Longair
//Last update:  5:30PM March 23rd, 2016.
//Purpose: Handles the work for playing a .wav file.
//Version: 0.5

//Libraries required:
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <mba/msgno.h>
#include <SDL/SDL.h>
#include <SDL/SDL_audio.h>

//Files required:
#include "../hdr/Jukebox.h"
#include "../hdr/config.h"

struct sample {
	
    Uint8 *data;
    Uint32 dpos;
    Uint32 dlen;

} sounds[NUM_SOUNDS];

void Jukebox::MixAudio(void *unused, Uint8 *stream, int len)
{
	int i;
	Uint32 amount;
	
	for (i = 0; i < NUM_SOUNDS; i++) {
		
		amount = (sounds[i].dlen-sounds[i].dpos);
		
		if (amount > (Uint32)len) {
			
			amount = len;
			
		}
		
		SDL_MixAudio(stream, &sounds[i].data[sounds[i].dpos], amount, SDL_MIX_MAXVOLUME);
		sounds[i].dpos += amount;
		
	}
	
	(void)unused;
	
}

void Jukebox::PlaySound(const char *file)
//Function to play the sound passed in a as a parameter.
{
	int index;
	SDL_AudioSpec wave;
	Uint8 *data;
	Uint32 dlen;
	SDL_AudioCVT cvt;

	/* Look for an empty (or finished) sound slot */
	for ( index=0; index<NUM_SOUNDS; ++index ) {
		
		if ( sounds[index].dpos == sounds[index].dlen ) {
			
			break;
			
		}
		
	}
	
	if ( index == NUM_SOUNDS ) {
	
		return;
	
	}

	/* Load the sound file and convert it to 16-bit stereo at 22kHz */
	if ( SDL_LoadWAV(file, &wave, &data, &dlen) == NULL ) {
		
		fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
		return;
		
	}
	
	SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, wave.freq, AUDIO_S16, 2, 22050);
    cvt.buf = (Uint8*)malloc(dlen*cvt.len_mult);
	memcpy(cvt.buf, data, dlen);
	cvt.len = dlen;
	SDL_ConvertAudio(&cvt);
	SDL_FreeWAV(data);

	/* Put the sound data in the slot (it starts playing immediately) */
	if (sounds[index].data) {
		
		free(sounds[index].data);
		
	}
	
	SDL_LockAudio();
	sounds[index].data = cvt.buf;
	sounds[index].dlen = cvt.len_cvt;
	sounds[index].dpos = 0;
	SDL_UnlockAudio();
	
}

void Jukebox::PlayBackground()
//Function to play the background theme song specifically.
{
	
	const char *file = THEME_SONG;
	int index;
	SDL_AudioSpec wave;
	Uint8 *data;
	Uint32 dlen;
	SDL_AudioCVT cvt;

	/* Look for an empty (or finished) sound slot */
	for ( index=0; index<NUM_SOUNDS; ++index ) {
		
		if ( sounds[index].dpos == sounds[index].dlen ) {
			
			break;
			
		}
		
	}
	if ( index == NUM_SOUNDS ) {
		
		return;

	}
	
	/* Load the sound file and convert it to 16-bit stereo at 22kHz */
	if ( SDL_LoadWAV(file, &wave, &data, &dlen) == NULL ) {
		
		fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
		return;
		
	}
	
	SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, wave.freq, AUDIO_S16, 2, 22050);
    cvt.buf = (Uint8*)malloc(dlen*cvt.len_mult);
	memcpy(cvt.buf, data, dlen);
	cvt.len = dlen;
	SDL_ConvertAudio(&cvt);
	SDL_FreeWAV(data);

	/* Put the sound data in the slot (it starts playing immediately) */
	if (sounds[index].data) {
		
		free(sounds[index].data);
		
	}
	
	SDL_LockAudio();
	sounds[index].data = cvt.buf;
	sounds[index].dlen = cvt.len_cvt;
	sounds[index].dpos = 0;
	SDL_UnlockAudio();
	
}


void Jukebox::PlayItemPickUp()
//Function to play the background theme song specifically.
{
	
	const char *file = ITEM_PICKUP_SOUND;
	int index;
	SDL_AudioSpec wave;
	Uint8 *data;
	Uint32 dlen;
	SDL_AudioCVT cvt;

	//Look for an empty (or finished) sound slot
	for ( index=0; index<NUM_SOUNDS; ++index ) {
		
		if ( sounds[index].dpos == sounds[index].dlen ) {
			
			break;
			
		}
		
	}
	if ( index == NUM_SOUNDS ) {
		
		return;

	}
	
	// Load the sound file and convert it to 16-bit stereo at 22kHz
	if ( SDL_LoadWAV(file, &wave, &data, &dlen) == NULL ) {
		
		fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
		return;
		
	}
	
	SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, wave.freq, AUDIO_S16, 2, 22050);
    cvt.buf = (Uint8*)malloc(dlen*cvt.len_mult);
	memcpy(cvt.buf, data, dlen);
	cvt.len = dlen;
	SDL_ConvertAudio(&cvt);
	SDL_FreeWAV(data);

	// Put the sound data in the slot (it starts playing immediately)
	if (sounds[index].data) {
		
		free(sounds[index].data);
		
	}
	
	SDL_LockAudio();
	sounds[index].data = cvt.buf;
	sounds[index].dlen = cvt.len_cvt;
	sounds[index].dpos = 0;
	SDL_UnlockAudio();
	
}


void Jukebox::PlayHealthPotionSound()
//Function to play the background theme song specifically.
{
	
	const char *file = HEALTH_POTION_SOUND;
	int index;
	SDL_AudioSpec wave;
	Uint8 *data;
	Uint32 dlen;
	SDL_AudioCVT cvt;

	//Look for an empty (or finished) sound slot
	for ( index=0; index<NUM_SOUNDS; ++index ) {
		
		if ( sounds[index].dpos == sounds[index].dlen ) {
			
			break;
			
		}
		
	}
	if ( index == NUM_SOUNDS ) {
		
		return;

	}
	
	// Load the sound file and convert it to 16-bit stereo at 22kHz
	if ( SDL_LoadWAV(file, &wave, &data, &dlen) == NULL ) {
		
		fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
		return;
		
	}
	
	SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, wave.freq, AUDIO_S16, 2, 22050);
    cvt.buf = (Uint8*)malloc(dlen*cvt.len_mult);
	memcpy(cvt.buf, data, dlen);
	cvt.len = dlen;
	SDL_ConvertAudio(&cvt);
	SDL_FreeWAV(data);

	// Put the sound data in the slot (it starts playing immediately)
	if (sounds[index].data) {
		
		free(sounds[index].data);
		
	}
	
	SDL_LockAudio();
	sounds[index].data = cvt.buf;
	sounds[index].dlen = cvt.len_cvt;
	sounds[index].dpos = 0;
	SDL_UnlockAudio();
	
}


void Jukebox::PlayStepSound()
//Function to play the background theme song specifically.
{
	
	const char *file = STEP_SOUND;
	int index;
	SDL_AudioSpec wave;
	Uint8 *data;
	Uint32 dlen;
	SDL_AudioCVT cvt;

	//Look for an empty (or finished) sound slot
	for ( index=0; index<NUM_SOUNDS; ++index ) {
		
		if ( sounds[index].dpos == sounds[index].dlen ) {
			
			break;
			
		}
		
	}
	if ( index == NUM_SOUNDS ) {
		
		return;

	}
	
	// Load the sound file and convert it to 16-bit stereo at 22kHz
	if ( SDL_LoadWAV(file, &wave, &data, &dlen) == NULL ) {
		
		fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
		return;
		
	}
	
	SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, wave.freq, AUDIO_S16, 2, 22050);
    cvt.buf = (Uint8*)malloc(dlen*cvt.len_mult);
	memcpy(cvt.buf, data, dlen);
	cvt.len = dlen;
	SDL_ConvertAudio(&cvt);
	SDL_FreeWAV(data);

	// Put the sound data in the slot (it starts playing immediately)
	if (sounds[index].data) {
		
		free(sounds[index].data);
		
	}
	
	SDL_LockAudio();
	sounds[index].data = cvt.buf;
	sounds[index].dlen = cvt.len_cvt;
	sounds[index].dpos = 0;
	SDL_UnlockAudio();
	
}


void Jukebox::PlayBossTheme()
//Function to play the background theme song specifically.
{
	
	const char *file = BOSS_THEME;
	int index;
	SDL_AudioSpec wave;
	Uint8 *data;
	Uint32 dlen;
	SDL_AudioCVT cvt;

	//Look for an empty (or finished) sound slot
	for ( index=0; index<NUM_SOUNDS; ++index ) {
		
		if ( sounds[index].dpos == sounds[index].dlen ) {
			
			break;
			
		}
		
	}
	if ( index == NUM_SOUNDS ) {
		
		return;

	}
	
	// Load the sound file and convert it to 16-bit stereo at 22kHz
	if ( SDL_LoadWAV(file, &wave, &data, &dlen) == NULL ) {
		
		fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
		return;
		
	}
	
	SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, wave.freq, AUDIO_S16, 2, 22050);
    cvt.buf = (Uint8*)malloc(dlen*cvt.len_mult);
	memcpy(cvt.buf, data, dlen);
	cvt.len = dlen;
	SDL_ConvertAudio(&cvt);
	SDL_FreeWAV(data);

	// Put the sound data in the slot (it starts playing immediately)
	if (sounds[index].data) {
		
		free(sounds[index].data);
		
	}
	
	SDL_LockAudio();
	sounds[index].data = cvt.buf;
	sounds[index].dlen = cvt.len_cvt;
	sounds[index].dpos = 0;
	SDL_UnlockAudio();
	
}


void Jukebox::PlayHeartPickUp()
//Function to play the background theme song specifically.
{
	
	const char *file = HEART_PICKUP_SOUND;
	int index;
	SDL_AudioSpec wave;
	Uint8 *data;
	Uint32 dlen;
	SDL_AudioCVT cvt;

	//Look for an empty (or finished) sound slot
	for ( index=0; index<NUM_SOUNDS; ++index ) {
		
		if ( sounds[index].dpos == sounds[index].dlen ) {
			
			break;
			
		}
		
	}
	if ( index == NUM_SOUNDS ) {
		
		return;

	}
	
	// Load the sound file and convert it to 16-bit stereo at 22kHz
	if ( SDL_LoadWAV(file, &wave, &data, &dlen) == NULL ) {
		
		fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
		return;
		
	}
	
	SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, wave.freq, AUDIO_S16, 2, 22050);
    cvt.buf = (Uint8*)malloc(dlen*cvt.len_mult);
	memcpy(cvt.buf, data, dlen);
	cvt.len = dlen;
	SDL_ConvertAudio(&cvt);
	SDL_FreeWAV(data);

	// Put the sound data in the slot (it starts playing immediately)
	if (sounds[index].data) {
		
		free(sounds[index].data);
		
	}
	
	SDL_LockAudio();
	sounds[index].data = cvt.buf;
	sounds[index].dlen = cvt.len_cvt;
	sounds[index].dpos = 0;
	SDL_UnlockAudio();
	
}


void Jukebox::PlayAttack()
//Function to play the background theme song specifically.
{
	
	const char *file = ATTACK_SOUND;
	int index;
	SDL_AudioSpec wave;
	Uint8 *data;
	Uint32 dlen;
	SDL_AudioCVT cvt;

	//Look for an empty (or finished) sound slot
	for ( index=0; index<NUM_SOUNDS; ++index ) {
		
		if ( sounds[index].dpos == sounds[index].dlen ) {
			
			break;
			
		}
		
	}
	if ( index == NUM_SOUNDS ) {
		
		return;

	}
	
	// Load the sound file and convert it to 16-bit stereo at 22kHz
	if ( SDL_LoadWAV(file, &wave, &data, &dlen) == NULL ) {
		
		fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
		return;
		
	}
	
	SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, wave.freq, AUDIO_S16, 2, 22050);
    cvt.buf = (Uint8*)malloc(dlen*cvt.len_mult);
	memcpy(cvt.buf, data, dlen);
	cvt.len = dlen;
	SDL_ConvertAudio(&cvt);
	SDL_FreeWAV(data);

	// Put the sound data in the slot (it starts playing immediately)
	if (sounds[index].data) {
		
		free(sounds[index].data);
		
	}
	
	SDL_LockAudio();
	sounds[index].data = cvt.buf;
	sounds[index].dlen = cvt.len_cvt;
	sounds[index].dpos = 0;
	SDL_UnlockAudio();
	
}


void Jukebox::PlayZAttack()
//Function to play the background theme song specifically.
{
	
	const char *file = Z_ATTACK_SOUND;
	int index;
	SDL_AudioSpec wave;
	Uint8 *data;
	Uint32 dlen;
	SDL_AudioCVT cvt;

	//Look for an empty (or finished) sound slot
	for ( index=0; index<NUM_SOUNDS; ++index ) {
		
		if ( sounds[index].dpos == sounds[index].dlen ) {
			
			break;
			
		}
		
	}
	if ( index == NUM_SOUNDS ) {
		
		return;

	}
	
	// Load the sound file and convert it to 16-bit stereo at 22kHz
	if ( SDL_LoadWAV(file, &wave, &data, &dlen) == NULL ) {
		
		fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
		return;
		
	}
	
	SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, wave.freq, AUDIO_S16, 2, 22050);
    cvt.buf = (Uint8*)malloc(dlen*cvt.len_mult);
	memcpy(cvt.buf, data, dlen);
	cvt.len = dlen;
	SDL_ConvertAudio(&cvt);
	SDL_FreeWAV(data);

	// Put the sound data in the slot (it starts playing immediately)
	if (sounds[index].data) {
		
		free(sounds[index].data);
		
	}
	
	SDL_LockAudio();
	sounds[index].data = cvt.buf;
	sounds[index].dlen = cvt.len_cvt;
	sounds[index].dpos = 0;
	SDL_UnlockAudio();
	
}

bool Jukebox::init()
{
    SDL_AudioSpec fmt;
	/* Set 16-bit stereo audio at 22Khz */
	fmt.freq = 22050;
	fmt.format = AUDIO_S16;
	fmt.channels = 2;
	fmt.samples = 512;        /* A good value for games */
	fmt.callback = Jukebox::MixAudio;
	fmt.userdata = NULL;
	
	/* Open the audio device. */
	if (SDL_OpenAudio(&fmt, NULL) < 0) {
		
        printf("Unable to open audio: %s\n", SDL_GetError());
        return false;
		//MMSG("Unable to open audio: %s\n", SDL_GetError());
		//return EXIT_FAILURE;
		
	}
	
    /* Start playing sound! */
	SDL_PauseAudio(0);
    return true;
}