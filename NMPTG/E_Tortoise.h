#pragma once
#include"Object.h"
class E_Tortoise:public Object
{
	FrkSprite* E_TortoiseshellGreenLeft;
	FrkSprite* E_TortoiseshellGreenRight;
	FrkSprite* E_TortoiseGreenLeft;
	FrkSprite* E_TortoiseGreenRight;

public:
	void Load();
	void Update(float gameTime);
	E_Tortoise();
	~E_Tortoise();
};

