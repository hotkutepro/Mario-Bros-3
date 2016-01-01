#pragma once
#include"Object.h"
#include"FrkSprite.h"
#include"Box.h"
class C_Brick:public Object
{
private:
	FrkSprite* brick;
	FrkSprite* Coin;	
	int n;//sau bao lau se tro lai binh thuong
public:	
	void Load();	
	void Update(float gameTime);	
	void IsAttacked();
	void Die();
	void WatchUp();
	void Reset();	
	C_Brick();
	~C_Brick();
};

