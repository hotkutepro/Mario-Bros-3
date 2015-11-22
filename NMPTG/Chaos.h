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
class Chaos : public FrkGame
{
protected:		
	Brick* br;
	SweptAABB* sw;
	Box* bound1, bound2;
	Hero* hero;
	FrkCamera* camera;
	FrkGraphic* graphic;	
	Map* map;
	QNode* qNode;
public:	
	Chaos(HINSTANCE hInst, int hW, int hH, char* hName);
	~Chaos();


	void Load();

	void Render();
	
	void Update(float gameTime);
	
	
};

