#pragma once
#include"Object.h"
#include "FrkSprite.h"
#include"Box.h"
#include"ResourcesManager.h"
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
	float delay_next;
	float max_speed;
	int status;

public:
	void Load();
	void Render();
	void Update(float gameTime);
	void GoLeft(float gameTime);
	void GoRight(float gameTime);
	void Inertia(float gameTime);
	void Jump(float gameTime);
	void Fall(float gameTime);
	void Run();
	D3DXVECTOR2 getSpeed();
	Hero();
	Hero(D3DXVECTOR2 pos, D3DXVECTOR2 speed);
	~Hero();
};

