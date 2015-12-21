#pragma once
#include"Object.h"
class E_Tarnooki_Fly:public Object
{
private:
	FrkSprite* E_MushroomRed;
	FrkSprite* E_MushroomRedDeath;
	FrkSprite* E_FlyMushroom;
	int t;
public:
	void Load();
	void Update(float gameTime);
	void Collision_Up();
	void Collision_Down();
	void Collision_Left();
	void Collision_Right();
	void SetSprite();
	E_Tarnooki_Fly();
	~E_Tarnooki_Fly();
};

