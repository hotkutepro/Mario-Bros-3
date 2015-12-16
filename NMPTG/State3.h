#pragma once
#include "State.h"
#include "State_2.h"
#include "FrkCamera.h"
#include "Map.h"
#include"Man.h"
#include"C_Brick.h"
#include"Box.h"
#include"SuperHero.h"

class State;
class State_3 : public State
{
private:		
	QNode* qnode;
	State* state_2;
	FrkCamera* camera;
	Map* map1;
	Man *man;	
	SuperHero* s_hero;
	C_Brick* brick;
	float speed, nx, ny;
	Box* b1;
	Box* b2;
public:
	State_3(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM);
	~State_3();
	void Load();
	void Update(float gameTime);
	void Render();	
};

