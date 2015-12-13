#pragma once
#include"Object.h"
#include"FrkSprite.h"
#include"Box.h"
class C_Brick:public Object
{
private:
	FrkSprite* brick;
	FrkSprite* CoinBoxNull;
public:
	Box* m_hBox;	
	void Load();	
	void Update(float gameTime);	
	C_Brick(D3DXVECTOR2 pos, D3DXVECTOR2 speed);
	C_Brick(typeObject _t);
	C_Brick();
	~C_Brick();
};

