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
	Sound :: Initialize ();

	//Background Music
	Sound :: Load ("Music.mp3");
	Sound :: Play ("Music.mp3");
	Sound :: Play (false);

	//Sound Effects
	SoundEffect* Jump_Sound;

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
			Sound::TogglePause();
		}
		if (GetAsyncKeyState ('X'))
		{
			volume += 0.10f;
			Sound :: SetVolume (volume);

		}
		if (GetAsyncKeyState ('Z'))
		{
			volume -= 0.10f;
			Sound :: SetVolume (volume);

		}
	}
}