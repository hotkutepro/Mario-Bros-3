#pragma once
#include"Object.h"
#include "FrkSprite.h"
#include"Box.h"
#include"ResourcesManager.h"
#define _hero_GROUND_Y 287
#define _hero_LIMITTIME 0.0075//0.0075
#define _hero_GRAVITY 9//9
#define _hero_JUMP 36//36
#define _hero_MAXJUM 45//45
#define _hero_MAXSPEED 5//5
#define _hero_SPEED 2//2
#define _hero_ACCELERATION 0.7//0.7~0.8
class Hero:public Object
{
private:
#pragma region Hero Sprite
	FrkSprite* Strike;
	FrkSprite* BigMarioDriftToLeft;
	FrkSprite* BigMarioDriftToRight;
	FrkSprite* BigMarioFallLeft;
	FrkSprite* BigMarioFallRight;
	FrkSprite* BigMarioHugLeft;
	FrkSprite* BigMarioHugRight;
	FrkSprite* BigMarioJumpLeft;
	FrkSprite* BigMarioJumpRight;
	FrkSprite* BigMarioKickLeft;
	FrkSprite* BigMarioKickRight;
	FrkSprite* BigMarioLeft;
	FrkSprite* BigMarioRight;
	FrkSprite* BigMarioRunLeft;
	FrkSprite* BigMarioRunRight;
	FrkSprite* BigMarioSitLeft;
	FrkSprite* BigMarioSitRight;
	FrkSprite* BigMarioSuperJumpLeft;
	FrkSprite* BigMarioSuperJumpRight;
	FrkSprite* BrosBaleLeft;
	FrkSprite* BrosBaleRight;
	FrkSprite* BrosDriftToLeft;
	FrkSprite* BrosDriftToRight;
	FrkSprite* BrosFallLeft;
	FrkSprite* BrosFallRight;
	FrkSprite* BrosFlyLeft;
	FrkSprite* BrosFlyRight;
	FrkSprite* BrosHugLeft;
	FrkSprite* BrosHugRight;
	FrkSprite* BrosJumpLeft;
	FrkSprite* BrosJumpRight;
	FrkSprite* BrosKickLeft;
	FrkSprite* BrosKickRight;
	FrkSprite* BrosLeft;
	FrkSprite* BrosRight;
	FrkSprite* BrosRunLeft;
	FrkSprite* BrosRunRight;
	FrkSprite* BrosSitLeft;
	FrkSprite* BrosSitRight;
	FrkSprite* MarioDeath;
	FrkSprite* MarioDriftToLeft;
	FrkSprite* MarioDriftToRight;
	FrkSprite* MarioHugLeft;
	FrkSprite* MarioHugRight;
	FrkSprite* MarioJumpLeft;
	FrkSprite* MarioJumpRight;
	FrkSprite* MarioKickLeft;
	FrkSprite* MarioKickRight;
	FrkSprite* MarioLeft;
	FrkSprite* MarioRight;
	FrkSprite* MarioRunLeft;
	FrkSprite* MarioRunRight;
	FrkSprite* MarioSuperJumpLeft;
	FrkSprite* MarioSuperJumpRight;

#pragma endregion
	bool isMove;
	bool isJump;
	bool direction;
	bool isRun;
	bool isControlUp;
	float delay_next;
	int status;
	

public:
	
	string f_str;
	string f_str1;
	string f_str2;
	string f_str3;
	char* a; 
	char* b;
	char* c;
	char* d;
	void Load();
	void Render();
	void Update(float gameTime);
	void GoLeft(float gameTime);
	void GoRight(float gameTime);
	void RunLeft(float gameTime);
	void RunRight(float gameTime);
	void Inertia(float gameTime);
	void InertiaRun(float gameTime);
	void Jump(float gameTime);
	void JumpKeyUp(float gameTime);
	void Fall(float gameTime);
	void Squat(float gameTime);
	void Run();
	D3DXVECTOR2 getSpeed();
	Hero();
	Hero(D3DXVECTOR2 pos, D3DXVECTOR2 speed);
	~Hero();
};

