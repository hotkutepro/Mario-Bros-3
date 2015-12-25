#pragma once
#include"Object.h"
class E_Plant_Red :public Object
{
public:
	void Load();
	void Update(float gameTime);
	void IsAttacked();
	E_Plant_Red();
	~E_Plant_Red();
};

