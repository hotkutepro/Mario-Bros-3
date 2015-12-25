#pragma once
#include"Object.h"
#include "Infomation.h"
#define _hero_JUMP 9.7f//10
#define _hero_MAXJUM 11//45
#define _hero_MAXSPEED 5//5
#define _hero_SPEED 3//2
#define _hero_ACCELERATION 0.5f//.2f
#define _hero_RUN_ACCELERATION 0.048f//
//dung cho box binh thuong
#define _hero_BOX_WIDTH 9
#define  _hero_BOX_ADJUST_POS_RIGHT 4
#define  _hero_BOX_ADJUST_POS_LEFT 3
//dung cho box top
#define  _hero_BOX_TOP_WIDTH 1
#define  _hero_BOX_TOP_HEIGHT 3
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
	Infomation* infomation;
	string f_str;
	char* a;
	string f_str1;
	char* a1;

	//xu ly phim khi keyup
	bool isUp = false;
	bool isDown = false;
	bool isLeft = false;
	bool isRight = false;

	//dang nhay
	bool isJump = false;	

	//dang chay
	bool isRun = false;

	//dang ngoi
	bool isSquat = false;	

	//dang bay
	bool isFly = false;

	//ba le
	bool attack = false;
	//thoi gian ba le
	float timeAttack = 0;

	// chuan bi cam rua
	bool ready = false;

	//thoi gian delay khi dat max speed
	float delayMaxSpeed;
	//bien delay khi die
	float delayDie;
	void Load();
	void Update(float gametime);
	void GoLeft(float gameTime);
	void GoRight(float gameTime);
	void RunLeft(float gameTime);
	void RunRight(float gameTime);
	void Inertia(float gameTime);
	void InertiaRun(float gameTime);
	void Jump(float vJump);
	void SuperJump();
	void JumpKeyUp(float gameTime);	
	void Squat(float gameTime);
	void BrosFly(float gameTime);
	void BrosFall(float gameTime);
	void Attack();
	void IsAttacked();
	Box* GetBoxWithObject(Object* object);
	Box* GetBox();
	Box* GetBoxTop();
	Box* GetBoxAttack();
	Box* GetBox_CGround();//va de xet va cham voi mat dat
	//void RenderBoxDebug();
	void RenderV();	
	void RenderBoxBottom();
	void RenderBoxAttack();
	void RendeBoxTop();
	void Collision_Coin();
	void Collision_Leaf();
	void Collision_Mushroom();
	void Collision_1up();
	
	virtual void Move();
	SuperHero();
	~SuperHero();
};

