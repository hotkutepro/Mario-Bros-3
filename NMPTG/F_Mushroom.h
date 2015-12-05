#pragma once
#include "Object.h"
#include "FrkSprite.h"
class F_Mushroom:public Object
{
	FrkSprite* E_Mushroom;
public:
	F_Mushroom();
	~F_Mushroom();
	void Load();
	void Update(float gameTime);

};

