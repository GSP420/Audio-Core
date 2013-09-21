// GSP 420 - Game Engine Design
// Audio Core - Main
// by:
// Erick Garcia
// Zachary Gauld
// Christopher Cone
// Jordan Swanson
// Darion Wallace

#include "AudioCore.h"

bool Sound :: s_enabled = true;
char *Sound :: s_current_sound;

FMOD_RESULT Sound :: s_result;
FMOD_SYSTEM *Sound :: s_fmod_system;
FMOD_SOUND *Sound :: s_sound;
FMOD_CHANNEL *Sound :: s_channel;

void Sound :: Initialize ()
{
	s_result = FMOD_System_Create (&s_fmod_system);
	assert (s_result == FMOD_OK);
	s_result = FMOD_System_Init (s_fmod_system, 1, FMOD_INIT_NORMAL, 0);
	assert (s_result == FMOD_OK);
	FMOD_Channel_SetVolume (s_channel, 0.0f);
}

void Sound :: Update ()
{
	FMOD_System_Update (s_fmod_system);
}

void Sound :: SetVolume (float vol) 
{
	if (s_enabled && vol >= 0.0f && vol <= 1.0f) 
	{
		FMOD_Channel_SetVolume (s_channel, vol);
    }
}

void Sound :: Load (const char * filename) 
{
	s_current_sound = (char *) filename;

    if (s_enabled) 
	{
		s_result = FMOD_Sound_Release (s_sound);
        s_result = FMOD_System_CreateStream (s_fmod_system, s_current_sound, FMOD_SOFTWARE, 0, &s_sound);
		assert (s_result == FMOD_OK);
	}
}

void Sound :: Unload (void) 
{
	s_result = FMOD_Sound_Release (s_sound);
	assert (s_result == FMOD_OK);
}

void Sound :: Play (bool pause = false)
{
	if (true == s_enabled) 
	{
		s_result = FMOD_System_PlaySound (s_fmod_system, FMOD_CHANNEL_FREE, s_sound, pause, &s_channel);
		assert (s_result == FMOD_OK);
        FMOD_Channel_SetMode (s_channel, FMOD_LOOP_NORMAL);
    }
}

bool Sound :: GetSoundState () 
{
    return s_enabled;
}

char* Sound :: GetCurrentSound ()
{
	return s_current_sound;
}

void Sound :: SetPause (bool pause) 
{
	FMOD_Channel_SetPaused (s_channel, pause);
}

void Sound :: SetSound (bool s) 
{
    s_enabled = s;
}

void Sound :: ToggleSound (void) 
{
	s_enabled = !s_enabled;
    if (s_enabled == true) 
	{
		Load (s_current_sound); 
		Play (s_enabled); 
	}

    if (s_enabled == false) 
	{
		Unload ();
	}
}

void Sound :: TogglePause (void) 
{
	FMOD_BOOL p;
    FMOD_Channel_GetPaused (s_channel, &p);
    FMOD_Channel_SetPaused (s_channel, !p);
}

SoundEffect :: SoundEffect (char* filename)
{
	b_enabled = true;
	m_sound_name = filename;
	m_result = FMOD_System_CreateSound (Sound::GetSystem(), m_sound_name, FMOD_SOFTWARE, 0, &m_sound);
	assert(m_result == FMOD_OK);
}

void SoundEffect :: Play ()
{
	m_result = FMOD_System_PlaySound (Sound :: GetSystem (), FMOD_CHANNEL_FREE, m_sound, false, 0);
	assert(m_result == FMOD_OK);
}

FMOD_SYSTEM* Sound :: GetSystem ()
{
 return s_fmod_system;
}