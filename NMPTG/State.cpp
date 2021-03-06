#include "State.h"



State::State(HINSTANCE hInstance, int width, int height, char* wName,StateManager* SM) :FrkGame(hInstance,width,height,wName,SM)
{
	
}

State::State(FrkGame* gamestate) : FrkGame(gamestate)
{

}



State::~State()
{
}

void State::Load()
{

}

void State::Render()
{

}

void State::Update(float gameTime)
{

}

void State::Run() 
{
	FrkGame::Run();
}

void State::Init()
{
	if (!FrkGame::InitWindow())
	{
		MessageBox(NULL, "Can't init game", "Error", MB_OK);
	}
	FrkGame::InitDX();
	FrkGame::InitLocal();
}

void State::ChangeState(State* state)
{
	//StateManager::GetInstance()->Remove(this);
	StateManager::GetInstance()->Add(state);

}

void State::ResetState()
{
	
}
