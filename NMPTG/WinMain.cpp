#include <Windows.h>

#include "Chaos.h"

int WINAPI WinMain(HINSTANCE h, HINSTANCE p, LPTSTR a, int c)
{

	MSG msg;
	FrkGame* game = new Chaos(h, 800, 480, "animals");
	if (!game->InitWindow())
	{
		MessageBox(NULL, "Can't init game", "Error", MB_OK);
		return 0;
	}
	game->InitDX();
	game->InitLocal();
	game->Load();
	game->Run();
	return 0;
}