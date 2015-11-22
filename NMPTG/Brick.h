#pragma once
#include"Object.h"
#include"FrkSprite.h"
#include"Box.h"
class Brick:Object
{
public:
	Box* m_hBox;
	FrkSprite* m_hBrick;		
	void Load();
	void Render();
	void Update(float x, float y);
	Box* getBox();
	Brick(D3DXVECTOR2 pos, D3DXVECTOR2 speed);
	Brick(typeObject _t);
	Brick();
	~Brick();
};

