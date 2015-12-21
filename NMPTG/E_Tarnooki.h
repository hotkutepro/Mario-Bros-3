#pragma once
#include"Object.h"
class E_Tarnooki:public Object
{
	FrkSprite* E_Mushroom;
	FrkSprite* E_MushroomDeath;
	int t;
public:
	void Load();
	void Update(float gameTime);
	void Collision_Up();
	void Collision_Down();
	void Collision_Left();
	void Collision_Right();
	void Die();
	void SetSprite();	
	E_Tarnooki();
	~E_Tarnooki();
};

