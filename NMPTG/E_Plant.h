#pragma once
#include "Object.h"
class E_Plant:public Object
{
	FrkSprite* ZPipe_sm;
	FrkSprite* Tree;
	D3DXVECTOR2 pos;
	int n;
public:
	void Load();
	void Update(float gameTime);
	void IsAttacked();
	void Render();
	void Collision_Up();
	void Collision_Down();
	void Collision_Left();
	void Collision_Right();
	E_Plant();
	~E_Plant();
};

