#pragma once
#include "Object.h"
class F_Coin:public Object
{
	int n = 0;
public:
	void Load();
	void Update(float gameTime);
	void Die();
	void Show();
	F_Coin();
	~F_Coin();
};

