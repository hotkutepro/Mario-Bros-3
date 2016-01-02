#pragma once
#include "Object.h"
class F_Coin:public Object
{
	FrkSprite* brick;
	FrkSprite* Coin;
	int n = 0;
public:
	void Load();
	void Update(float gameTime);
	void Die();
	void Show();
	void WatchUp();
	void Reset();
	F_Coin();
	~F_Coin();
};

