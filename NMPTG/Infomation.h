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

	int I_Time ;
	int I_Score;
	int I_Coin;
	int I_Life;
	int I_A;
	Infomation(float _time, int _score, int _coin, int _life, int a);
	void Load();
	void Update();
	void Render();
	Infomation();
	~Infomation();
};

