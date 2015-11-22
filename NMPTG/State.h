#pragma once
#include "FrkGame.h"
#include "SweptAABB.h"
#include "StateManager.h"


class State : public FrkGame
{
protected:
	StateManager* stateManager;
	int Score;
	int Coin;
	SweptAABB* sAABB;
	
public:
	enum SceneID
	{
		One, Two, Three
	};

	
	State(HINSTANCE hInstance, int width, int height, char* wName, StateManager* SM);
	~State();
	void Init();
	void Run();
	virtual void Load();
	virtual void Render();
	virtual void Update(float gameTime);
	
};

