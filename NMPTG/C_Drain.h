#pragma once
#include"Object.h"
class C_Drain:public Object
{
public:
	void Load();	
	void Update(float gameTime);
	C_Drain();
	~C_Drain();
};

