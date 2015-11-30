#pragma once
#include "FrkGame.h"
#include "FrkGraphic.h"
#include "FrkSound.h"
#include "Map.h"
#include"FrkCamera.h"
#include "Box.h"
#include "SweptAABB.h"
#include "Hero.h"
#include"Brick.h"
#include "State_1.h"
#include "E_Mushroom.h"
#include "QNode.h"
class Chaos : public State
{
protected:
	QNode* qNode;	
	SweptAABB* sw;
	Box* bound1, bound2;
	Hero* hero;
	FrkCamera* camera;
	FrkGraphic* graphic;	
	Map* map;	
public:	
	Chaos(HINSTANCE hInst, int hW, int hH, char* hName,StateManager* sm);
	~Chaos();


	void Load();

	void Render();
	
	void Update(float gameTime);
	
	
};

