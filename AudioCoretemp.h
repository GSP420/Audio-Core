// GSP 420 - Game Engine Design
//        Audio Core
//           by:
// Erick Garcia
// Zachary Gauld
// Christopher Cone
// ?
// ?

#ifndef AUDIOCORE_H
#define AUDIOCORE_H
#include "fmod.h"
#include "assert.h"

class Sound
{
private:
	static bool s_enabled;
	static char *s_current_sound;

	static FMOD_RESULT s_result;
	static FMOD_SYSTEM *s_fmod_system;
	static FMOD_SOUND *s_sound;
	static FMOD_CHANNEL *s_channel;

public:
	static void Initialize ();
	static void Update ();

	static void SetVolume (float vol);
	static void Load (const char *filename);
	static void Unload ();
	static void Play (bool pause);

	static bool GetSoundState ();
	static char* GetCurrentSound ();

	static void SetPause (bool pause);
	static void SetSound (bool sound);

	static void ToggleSound ();
	static void TogglePause ();

	static FMOD_SYSTEM* GetSystem ();
};

class SoundEffect
{
private:
	bool b_enabled;
	char* m_sound_name;
	FMOD_SOUND* m_sound;
	FMOD_RESULT m_result;

public:
	SoundEffect (char* filename);
	void Play ();
};

#endif