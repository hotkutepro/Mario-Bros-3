#pragma once
#include"Object.h"
class E_Tortoise_Fly :public Object
{

	FrkSprite* E_FlyTortoiseGreenLeft;
	FrkSprite* E_FlyTortoiseGreenRight;
	FrkSprite* E_TortoiseshellGreenLeft;
	FrkSprite* E_TortoiseshellGreenRight;
	FrkSprite* E_TortoiseGreenLeft;
	FrkSprite* E_TortoiseGreenRight;
	FrkSprite* E_TortoiseshellGreenLeftReverse;
	FrkSprite* E_TortoiseshellGreenRightReverse;
	bool IsRun;
public:
	void Load();	
	void Update(float gameTime);
	void IsAttacked();
	void SetSprite();
	void Collision_Up();
	void Collision_Down();
	void Collision_Left();
	void Collision_Right();	
	void CollistionWithObject();
	void Collision_Shell_Object();
	void Die();
	E_Tortoise_Fly();
	~E_Tortoise_Fly();
};

