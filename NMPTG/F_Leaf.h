#pragma once
#include"Object.h"
#include"FrkSprite.h"
class F_Leaf:public Object
{
public:
	FrkSprite* Leaf;
	void Load();
	void Render();
	void Update(float gameTime);	
	F_Leaf();
	~F_Leaf();
};

