#pragma once
#include"Object.h"
class Man:public Object
{
public:
	void Load();
	void Update(float gametime);
	Man();
	~Man();
};

