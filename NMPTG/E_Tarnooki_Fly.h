#pragma once
#include"Object.h"
class E_Tarnooki_Fly:public Object
{
	FrkSprite* E_MushroomRed;
	FrkSprite* E_MushroomRedDeath;
	FrkSprite* E_FlyMushroom;
public:
	void Load();
	void Update(float gameTime);
	E_Tarnooki_Fly();
	~E_Tarnooki_Fly();
};

