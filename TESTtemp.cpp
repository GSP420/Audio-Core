// GSP 420 - Game Engine Design
//        Audio Core
//           by:
// Erick Garcia
// Zachary Gauld
// Christopher Cone
// ?
// ?

#include "AudioCore.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void main ()
{
	Sound :: Initialize ();
	Sound :: Load ("Music.mp3");
	Sound :: Play (false);

	// m_sound_effect = new SoundEffect ("Your Filename"); ((Trying to get this to work))

	bool quit = false;

	cout << "TEST. Press Q to quit.\n" << endl;

	while (!quit)
	{
		if (GetAsyncKeyState ('Q'))
		{
			quit = true;
		}
	}
}