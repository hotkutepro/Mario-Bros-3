#pragma once
#include "FrkGame.h"
#include "Collision.h"
#include "StateManager.h"


class State : public FrkGame
{
protected:
	StateManager* stateManager;
	
	
public:
	enum SceneID
	{
		One, Two, Three
	};

	
	State(HINSTANCE hInstance, int width, int height, char* wName, StateManager* SM);
	State(FrkGame* gamestate);
	~State();
	void Init();
	void Run();
	virtual void Load();
	virtual void Render();
	virtual void Update(float gameTime);
	virtual void ChangeState(State* state);
	virtual void ResetState();
};

