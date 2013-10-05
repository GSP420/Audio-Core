// GSP 420 - Game Engine Design
// Audio Core - Audio Test
// by:
// Erick Garcia
// Zachary Gauld
// Christopher Cone
// Jordan Swanson
// Darion Wallace

#include "AudioCore.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void main ()
{
	//AudioCore - Object Declarations
	Sound *AudioCore = new Sound();  //instance class object
	SoundEffect *Jump_Sound;

	AudioCore->Startup(); //FMOD initiation
	
	//Background Music
	AudioCore->Load("Music.mp3");
	AudioCore->Play("Music.mp3");
	AudioCore->Play(false);

	//Sound Effects
	Jump_Sound = new SoundEffect ("Jump.wav");


	bool quit = false;

	cout << "TEST. Press Q to quit.\n" << endl;
	cout << "TEST. Press Spacebar to hear the jump sound.\n" <<endl;
	cout << "TEST. Press P to pause or un-pause the music.\n" <<endl;
	cout << "TEST. Press Z to decrease the volume of the music.\n" << endl;
	cout << "TEST. Press X to increase the volume of the music.\n" << endl;

	float volume= 1.00f;

	while (!quit)
	{

		if (GetAsyncKeyState ('Q'))
		{
			quit = true;
		}
		if (GetAsyncKeyState (VK_SPACE))
		{
			Jump_Sound->Play();
		}
		if (GetAsyncKeyState ('P'))
		{
			AudioCore->TogglePause();
		}
		if (GetAsyncKeyState ('X'))
		{
			volume += 0.10f;
			AudioCore->SetVolume(volume);

		}
		if (GetAsyncKeyState ('Z'))
		{
			volume -= 0.10f;
			AudioCore->SetVolume(volume);

		}
	}
}