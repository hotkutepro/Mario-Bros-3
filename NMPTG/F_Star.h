#pragma once
#include"Object.h"
class F_Star:public Object
{
public:
	void Load();
	void Update(float gameTime);
	void Die();
	F_Star();
	~F_Star();
};

