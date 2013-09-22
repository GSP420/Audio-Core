// GSP 420 - Game Engine Design
// Audio Core - Sound Test
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
	//SoundEffect* Attack_Sound;

	Jump_Sound = new SoundEffect ("Jump.wav");
	//Attack_Sound = new SoundEffect ("Attack.wav");

	bool quit = false;

	cout << "TEST. Press Q to quit.\n" << endl;
	cout << "TEST. Press Spacebar to hear the jump sound.\n" <<endl;
	cout << "TEST. Press P to pause the music.\n" <<endl;

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
			Sound :: TogglePause();
		}
	}
}