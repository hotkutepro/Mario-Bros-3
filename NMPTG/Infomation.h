#pragma once
#include "FrkSprite.h"
#include <d3dx9math.h>
class Infomation 
{
public:
	FrkSprite* sHub;
	FrkSprite* sHub1;
	FrkSprite* sHub2;
	FrkSprite* sHub3;
	FrkSprite* sHub4;
	FrkSprite* sHub5;
	FrkSprite* sHub6;
	FrkSprite* sHub7;
	FrkSprite* spriteRender;	
	D3DXVECTOR2 pos;
	//
	char* cTime;
	string sTime;
	//
	char* cScore;
	string sScore;
	//
	char* cCoin;
	string sCoin;
	//
	char* cLife;
	string sLife;
	//
	char* cState;
	string sState;

	int x;
	
	int n = 0;
	int I_Time ;
	int I_Score;
	int I_Coin;
	int I_Life;
	int I_State;
	Infomation(float _time, int _score, int _coin, int _life, int _state);
	static Infomation* Instance;
	static Infomation* GetInstance();
	void Load();
	void Update(float speedMario);
	void Render();
	Infomation();
	~Infomation();
};

