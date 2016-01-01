#include <Windows.h>

#include "ResourcesManager.h"
#include "State.h"
#include "State_4.h"
#include"State_5.h"

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
	
	
	
	State* state = new State_4(h, 320, 240, "demo", StateManager::GetInstance());

	StateManager::GetInstance()->Add(state);
	
	state->Init();
	Infomation::GetInstance()->Load();
	ResourcesManager::GetInstance()->Init();
	ResourcesManager::GetInstance()->LoadSprite("sprite1.txt");	
	state->Load();
	state->Run();
	return 0;
}