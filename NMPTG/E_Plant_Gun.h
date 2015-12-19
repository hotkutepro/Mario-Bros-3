#pragma once
#include "Object.h"
class E_Plant_Gun:public Object
{
private:
	FrkSprite* Tree_left;
	FrkSprite* Tree_right;
	FrkSprite* ZPipe_md;
	D3DXVECTOR2 pos;
public:
	void Load();
	void Update(float gameTime);
	void Render();
	E_Plant_Gun();
	~E_Plant_Gun();
};

