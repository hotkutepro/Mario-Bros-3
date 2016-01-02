#pragma once
#include"Object.h"
#define vx 1
#define vx_run 4
#define vy -2
class E_Tortoise:public Object
{
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
	void Die();	
	void Collision_Shell_Object();
	void Collision_Up();
	void Collision_Down();
	void Collision_Left();
	void Collision_Right();
	void SetSprite();	
	void SetControl();//xu ly khi bi mario cam
	E_Tortoise();
	~E_Tortoise();
};

