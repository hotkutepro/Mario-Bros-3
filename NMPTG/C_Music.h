#pragma once
#include "Object.h"
class C_Music:public Object
{
public:
	void Load();
	void Update(float gameTime);
	void IsAttacked();
	void Die();
	void WatchUp();
	void Reset();
	C_Music();
	~C_Music();
};

