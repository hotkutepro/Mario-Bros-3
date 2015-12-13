#pragma once
#include "State.h"
#include "State_2.h"
#include "FrkCamera.h"
#include "Map.h"
#include"Hero.h"

class State;
class State_2;
class State_1 : public State
{
private:
	QNode* qnode;
	FrkTexture* wall;
	State* state_2;
	FrkCamera* camera;
	Map* map1;	
	Hero *hero;
	
public:
	State_1(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM);
	~State_1();
	void Load();
	void Update(float gameTime);
	void Render();
	D3DXVECTOR2 getSpeed();
};

