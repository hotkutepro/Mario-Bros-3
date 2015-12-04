#include <Windows.h>

#include "ResourcesManager.h"
#include "State.h"
#include "State_1.h"
#include "State_2.h"

int WINAPI WinMain(HINSTANCE h, HINSTANCE p, LPTSTR a, int c)
{
	
	//StateManager* SM = new StateManager();
	//State* game = new Chaos(h, 800, 480, "animals",SM);
	////if (!game->InitWindow())
	////{
	////	MessageBox(NULL, "Can't init game", "Error", MB_OK);
	////	return 0;
	////}

	////game->InitDX();
	////game->InitLocal();
	//SM->Add(game);
	//game->Init();
	//ResourcesManager::GetInstance()->Init();
	//game->Load();
	//game->Run();
	
	StateManager* SM = new StateManager();
	
	State* state = new State_2(h, 800, 480, "demo", SM);
	SM->Add(state);
	
	state->Init();
	ResourcesManager::GetInstance()->Init();
	ResourcesManager::GetInstance()->LoadSprite("sprite1.txt");	
	state->Load();
	state->Run();
	return 0;
}