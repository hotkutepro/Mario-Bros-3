#include <Windows.h>

#include "Chaos.h"
#include "ResourcesManager.h"
#include "State.h"
#include "State_1.h"
#include "State_2.h"

int WINAPI WinMain(HINSTANCE h, HINSTANCE p, LPTSTR a, int c)
{
	
	
	/*FrkGame* game = new Chaos(h, 800, 480, "animals");
	if (!game->InitWindow())
	{
		MessageBox(NULL, "Can't init game", "Error", MB_OK);
		return 0;
	}

	game->InitDX();
	game->InitLocal();
	ResourcesManager::GetInstance()->Init();
	game->Load();
	game->Run();*/
	StateManager* SM = new StateManager();
	
	State* state = new State_1(h, 800, 480, "demo", SM);
	SM->Add(state);
	
	state->Init();
	ResourcesManager::GetInstance()->Init();
	state->Load();
	state->Run();
	return 0;
}