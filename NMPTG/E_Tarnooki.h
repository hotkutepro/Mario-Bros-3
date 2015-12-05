#pragma once
#include"Object.h"
class E_Tarnooki:public Object
{
	FrkSprite* E_Mushroom;
	FrkSprite* E_MushroomDeath;
public:
	void Load();
	void Update(float gameTime);
	E_Tarnooki();
	~E_Tarnooki();
};

