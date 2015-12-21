#pragma once
#include"Object.h"
class E_Tortoise_Red:public Object
{
	FrkSprite* E_TortoiseRedRight;
	FrkSprite* E_TortoiseshellRedLeft;
	FrkSprite* E_TortoiseshellRedRight;
	FrkSprite* E_TurtoiseRedLeft;
	FrkSprite* E_TortoiseshellRedLeftReverse;
	FrkSprite* E_TortoiseshellRedRightReverse;
public:
	void Load();
	void Update(float gameTime);
	Box* GetBox_CLeft();
	Box* GetBox_CRight();
	void Collision_Up();
	void Collision_Down();
	void Collision_Left();
	void Collision_Right();
	void SetSprite();
	E_Tortoise_Red();
	~E_Tortoise_Red();
};

