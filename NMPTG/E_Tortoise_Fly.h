#pragma once
#include"Object.h"
#define vx_run 4
#define vx 1;
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
	bool IsControl;
	int timelife;
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
	void SetControl();
	E_Tortoise_Fly();
	~E_Tortoise_Fly();
};

