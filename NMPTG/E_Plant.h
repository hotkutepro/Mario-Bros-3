#pragma once
#include "Object.h"
class E_Plant:public Object
{
public:
	void Load();
	void Update(float gameTime);
	E_Plant();
	~E_Plant();
};

