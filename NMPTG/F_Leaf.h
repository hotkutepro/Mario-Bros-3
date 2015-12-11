#pragma once
#include"Object.h"
#include"FrkSprite.h"
class F_Leaf:public Object
{	
public:
	
	void Load();	
	void Update(float gameTime);	
	void Die();
	F_Leaf();
	~F_Leaf();
};

