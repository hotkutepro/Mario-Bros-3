#pragma once
#include"Object.h"
class E_Plant_Red_Gun:public Object
{
private:
	FrkSprite* Tree_red_left_down;
	FrkSprite* Tree_red_left_up;
	FrkSprite* Tree_red_right_down;
	FrkSprite* Tree_red_right_up;
public:
	void Load();
	void Update(float gameTime);
	E_Plant_Red_Gun();
	~E_Plant_Red_Gun();
};

