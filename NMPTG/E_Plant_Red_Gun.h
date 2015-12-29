#pragma once
#include"Object.h"
#include"Bullet.h"
class E_Plant_Red_Gun:public Object
{
private:
	FrkSprite* Tree_red_left_down;
	FrkSprite* Tree_red_left_up;
	FrkSprite* Tree_red_right_down;
	FrkSprite* Tree_red_right_up;
	FrkSprite* ZPipe_md;
	D3DXVECTOR2 pos;
	int n ;
	int vx = 3;
	int vy = 1.5;
	Bullet* bullet;
public:
	void Load();
	void Update(float gameTime);
	void Render();
	void shoot();
	void IsAttacked();
	void Collision_Up();
	void Collision_Down();
	void Collision_Left();
	void Collision_Right();
	void SetSprite();
	void Die();
	E_Plant_Red_Gun();
	~E_Plant_Red_Gun();
};

