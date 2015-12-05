#pragma once
#include "Object.h"
class F_Coin:public Object
{
public:
	void Load();
	void Update(float gameTime);
	F_Coin();
	~F_Coin();
};

