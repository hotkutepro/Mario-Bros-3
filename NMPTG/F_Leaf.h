#pragma once
#include"Object.h"
#include"FrkSprite.h"
class F_Leaf:public Object
{	
	FrkSprite* F_MushroomPower;
	FrkSprite* Leaf;
public:
	
	void Load();	
	void Update(float gameTime);	
	void WatchUp();
	void Die();
	F_Leaf();
	~F_Leaf();
};

