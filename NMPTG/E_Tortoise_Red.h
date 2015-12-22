#pragma once
#include"Object.h"
class E_Tortoise_Red:public Object
{
private:
	FrkSprite* E_TortoiseRedRight;
	FrkSprite* E_TortoiseshellRedLeft;
	FrkSprite* E_TortoiseshellRedRight;
	FrkSprite* E_TurtoiseRedLeft;
	FrkSprite* E_TortoiseshellRedLeftReverse;
	FrkSprite* E_TortoiseshellRedRightReverse;
	bool IsRun;
public:
	void Load();
	void Update(float gameTime);
	void UpdateDirect();
	Box* GetBox_CLeft();
	Box* GetBox_CRight();
	void Collision_Up();
	void Collision_Down();
	void Collision_Left();
	void Collision_Right();
	void SetSprite();
	void SetMove();
	E_Tortoise_Red();
	~E_Tortoise_Red();
};

