// GSP 420 - Game Engine Design
//        Audio Core
//           by:
// Erick Garcia
// Zachary Gauld
// Christopher Cone
// Jordan Swanson
// ?



//Include
#include "fmod.hpp"
#include "fmod_errors.h"
#pragma comment(lib, "fmodex_vc.lib") //specify additional linkers
#include <string>

//Define
#define AudioCore SoundSystem::Instance() //creates pointer to the class

//Class SoundSystem
class SoundSystem
{
public:

	//class
	static SoundSystem* Instance(); //instance declaration of the manager class
	~SoundSystem();					//deconstructor to deallocate memory to the SoundSystem class

	//variables
	FMOD::System* mSystem;			//pointer variable for the FMOD memory system, used for finding & correcting errors (Used in FMOD error check)
	FMOD_SPEAKERMODE mSpeakerMode;	//used to store the speaker type (Used in FMOD error check)
	FMOD_CAPS mCaps;				//used to determine the capabilities of a card / output device (Used in FMOD error check)
	unsigned int mVersion;			//used to compare FMOD versions (Used in FMOD error check)
	int mNumDrivers;				//used to return the number of available drivers (Used in FMOD error check)
	char mName[256];				//used to store the driver's name (Used in FMOD error check)
	float MusicLevel;				//used for setting the music level
	float SoundLevel;				//used for setting the sound level

	//functions
	void LoadMusic(std::string sPath, FMOD::Sound **sound);	  //create the music
	void LoadSound(std::string sPath, FMOD::Sound **sound);   //create the sound
	void SetMusicVolume(FMOD::Channel **channel, float vol);  //set the music volume
	void SetSoundVolume(FMOD::Channel **channel, float vol);  //set the sound volume
	void Play(FMOD::Sound **sound, FMOD::Channel **channel);  //play the sound / music
	void Stop(FMOD::Sound **sound, FMOD::Channel **channel);  //stop the sound / music
	void Pause(FMOD::Sound **sound, FMOD::Channel **channel); //pause the sound / music

private:
	SoundSystem();
};
