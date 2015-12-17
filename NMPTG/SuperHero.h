#pragma once
#include"Object.h"
#define _hero_GRAVITY 9//9
#define _hero_JUMP 36//36
#define _hero_MAXJUM 45//45
#define _hero_MAXSPEED 5//5
#define _hero_SPEED 2//2

#define _max_SPEED_JUMP 5
#define _SPEED_JUMP 0.5f

#define _max_SPEED_RUN 4
#define _SPEED_RUN 0.4f//
#define _tx_frame 0.2
#define _hero_ACCELERATION 0.7
enum Status
{
	MARIO, BIGMARIO, BROS, RUN
};
class SuperHero:public Object
{
private:
#pragma region Sprite
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
public:
	bool isJump;
	int status;
	bool direction;
	bool isRun;
	float level;
	void Load();
	void Update(float gametime);
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
	SuperHero();
	~SuperHero();
};

