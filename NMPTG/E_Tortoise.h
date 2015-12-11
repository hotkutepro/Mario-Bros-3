#pragma once
#include"Object.h"
class E_Tortoise:public Object
{
	FrkSprite* E_TortoiseshellGreenLeft;
	FrkSprite* E_TortoiseshellGreenRight;
	FrkSprite* E_TortoiseGreenLeft;
	FrkSprite* E_TortoiseGreenRight;
	int v = 2;
public:
	void Load();
	void Update(float gameTime);
	void Tortoise_Shell();
	void Die();
	E_Tortoise();
	~E_Tortoise();
};

