#pragma once
#include "State.h"
class State;
class State_2 :	public State
{
private:
	FrkTexture* wall;
	State* state_1;
public:
	State_2(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM);
	~State_2();
	void Load();
	void Update(float gameTime);
	void Render();
};

