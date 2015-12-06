#pragma once
#include "Object.h"
#include "FrkSprite.h"
class F_Mushroom:public Object
{
public:
	F_Mushroom();
	~F_Mushroom();
	void Load();
	void Update(float gameTime);

};

