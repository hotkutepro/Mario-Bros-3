#pragma once
#include "State.h"
#include "SuperHero.h"
#include "FrkCamera.h"
#include "QNode.h"
#include "Map.h"
class State_4 :
	public State
{
	SuperHero* hero;
	QNode* qnode;
	State* state_2;
	FrkCamera* camera;
	Map* map1;
	SuperHero* s_hero;
	Collision* collision;
public:
	void Load();
	void Update(float gameTime);
	void Render();

	State_4(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM);
	~State_4();
};

