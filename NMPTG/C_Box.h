#pragma once
#include"Object.h"
class C_Box:public Object
{
public:
	void Load();
	void Update(float gameTime);
	C_Box();
	~C_Box();
};

