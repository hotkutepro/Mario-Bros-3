#pragma once
#include"Object.h"
#include"FrkSprite.h"
#include"Box.h"
class C_Brick:public Object
{
private:
	FrkSprite* brick;
	FrkSprite* Coin;	
public:
	Box* m_hBox;	
	void Load();	
	void Update(float gameTime);	
	void IsAttacked();
	C_Brick(D3DXVECTOR2 pos, D3DXVECTOR2 speed);
	C_Brick(TYPEOBJECT _t);
	C_Brick();
	~C_Brick();
};

