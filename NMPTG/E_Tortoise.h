#pragma once
#include"Object.h"
class E_Tortoise:public Object
{
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
	void Tortoise_Shell();
	void Die();
	void Collision_Up();
	void Collision_Down();
	void Collision_Left();
	void Collision_Right();
	void SetSprite();
	void UpdateDirect();
	E_Tortoise();
	~E_Tortoise();
};

