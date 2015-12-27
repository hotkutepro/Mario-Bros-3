#pragma once
#include"Object.h"
class C_Question_Block:public Object
{
	FrkSprite* brick;
	FrkSprite* Coin;
	FrkSprite* CoinBox;
	FrkSprite* CoinBoxNull;
public:
	void Load();	
	void Update(float gameTime);
	void Die();
	void IsAttacked();
	C_Question_Block();
	~C_Question_Block();
};

