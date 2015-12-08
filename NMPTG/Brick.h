#pragma once
#include"Object.h"
#include"FrkSprite.h"
#include"Box.h"
class Brick:public Object
{
private:
	FrkSprite* brick;
	FrkSprite* CoinBoxNull;
public:
	Box* m_hBox;	
	void Load();	
	void Update(float gameTime);	
	Brick(D3DXVECTOR2 pos, D3DXVECTOR2 speed);
	Brick(typeObject _t);
	Brick();
	~Brick();
};

