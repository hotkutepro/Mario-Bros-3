#pragma once
#include "State.h"
#include "State_2.h"
#include "FrkCamera.h"
#include "Map.h"
#include "E_Mushroom.h"
#include"Hero.h"
#include"F_Leaf.h"
class State;
class State_2;
class State_1 : public State
{
private:
	FrkTexture* wall;
	State* state_2;
	FrkCamera* camera;
	Map* map1;	
	Hero *hero;
	F_Leaf* leaf;
public:
	State_1(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM);
	~State_1();
	void Load();
	void Update(float gameTime);
	void Render();
};

