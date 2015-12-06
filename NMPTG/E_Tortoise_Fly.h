#pragma once
#include"Object.h"
class E_Tortoise_Fly :public Object
{

	FrkSprite* E_FlyTortoiseGreenLeft;
	FrkSprite* E_FlyTortoiseGreenRight;
	FrkSprite* E_TortoiseshellGreenLeft;
	FrkSprite* E_TortoiseshellGreenRight;
	FrkSprite* E_TortoiseGreenLeft;
	FrkSprite* E_TortoiseGreenRight;
public:
	void Load();	
	void Update(float gameTime);
	E_Tortoise_Fly();
	~E_Tortoise_Fly();
};

