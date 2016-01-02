#pragma once
#include "Object.h"
class C_Land:public Object
{
public:
	void Load();	
	void Update(float gameTime);
	void Render();
	C_Land();
	~C_Land();
};

