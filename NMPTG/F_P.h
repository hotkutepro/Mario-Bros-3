#pragma once
#include"Object.h"
class F_P:public Object
{
private:
	FrkSprite* P;
	FrkSprite* KickP;
public:
	void Load();
	void Update(float gameTime);
	void Die();	
	void WatchUp();
	F_P();
	~F_P();
};

