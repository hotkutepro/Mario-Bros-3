#pragma once
#include "Object.h"
#include "FrkSprite.h"
class E_Mushroom:public Object
{
private:
FrkSprite* mushroomSprite;
public:
	E_Mushroom(int x, int y);
	E_Mushroom();
	~E_Mushroom();
	void Load();

	void Render();

	void Update(float gameTime);
};

