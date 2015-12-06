#pragma once
#include"Object.h"
class Bullet:public Object
{
public:
	void Load();
	void Update(float gameTime);
	Bullet();
	~Bullet();
};

