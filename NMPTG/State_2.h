#pragma once
#include "State.h"
#include "State_2.h"
#include "FrkCamera.h"
#include "Map.h"
#include"Hero.h"
#include"F_Leaf.h"
class State;
class State_1;
class State_2 : public State
{
private:
	QNode* qnode;
	FrkTexture* wall;
	State* state_1;
	FrkCamera* camera;
	Map* map1;
	Hero *hero;
	F_Leaf* leaf;
public:
	State_2(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM);
	~State_2();
	void Load();
	void Update(float gameTime);
	void Render();
};

