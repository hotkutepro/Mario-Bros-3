#pragma once
#include"Object.h"
class E_Tortoise_Red:public Object
{
	FrkSprite* E_TortoiseRedRight;
	FrkSprite* E_TortoiseshellRedLeft;
	FrkSprite* E_TortoiseshellRedRight;
	FrkSprite* E_TurtoiseRedLeft;
public:
	void Load();
	void Update(float gameTime);
	E_Tortoise_Red();
	~E_Tortoise_Red();
};

