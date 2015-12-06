#pragma once
#include "Object.h"
class E_Plant_Gun:public Object
{
public:
	void Load();
	void Update(float gameTime);
	E_Plant_Gun();
	~E_Plant_Gun();
};

