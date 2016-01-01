#include "Infomation.h"
#include "FrkTexture.h"
#include "FrkShareControl.h"
#include "FrkCamera.h"
#include "SuperHero.h"

 
Infomation::Infomation()
{
}

Infomation::Infomation(float _time, int _score, int _coin, int _life, int _state)
{
	I_Time = _time;
	I_Score = _score;
	I_Coin = _coin;
	I_Life = _life;
	I_State = _state;
	pos.x = FrkCamera::m_hVpx;
	pos.y = FrkCamera::m_hVpy;
}


Infomation::~Infomation()
{
}

void Infomation::Load()
{
	FrkTexture* tHub = _LocalContent->LoadTexture("resources\\hub\\hub.png");
	FrkTexture* tHub1 = _LocalContent->LoadTexture("resources\\hub\\hub1.png");
	FrkTexture* tHub2 = _LocalContent->LoadTexture("resources\\hub\\hub2.png");
	FrkTexture* tHub3 = _LocalContent->LoadTexture("resources\\hub\\hub3.png");
	FrkTexture* tHub4 = _LocalContent->LoadTexture("resources\\hub\\hub4.png");
	FrkTexture* tHub5 = _LocalContent->LoadTexture("resources\\hub\\hub5.png");
	FrkTexture* tHub6 = _LocalContent->LoadTexture("resources\\hub\\hub6.png");
	FrkTexture* tHub7 = _LocalContent->LoadTexture("resources\\hub\\hub7.png");
	sHub = new FrkSprite(tHub, 1, 1);
	sHub1 = new FrkSprite(tHub1, 1, 1);
	sHub2 = new FrkSprite(tHub2, 1, 1);
	sHub3 = new FrkSprite(tHub3, 1, 1);
	sHub4 = new FrkSprite(tHub4, 1, 1);
	sHub5 = new FrkSprite(tHub5, 1, 1);
	sHub6 = new FrkSprite(tHub6, 1, 1);
	sHub7 = new FrkSprite(tHub7, 1, 1);
	spriteRender = sHub;
	x = _hero_MAXSPEED - _hero_SPEED;

}

void Infomation::Update(float speedMario)
{
	if (n < 30)
	{
		n++;
	}
	else
	{
		I_Time--;
		n = 0;
	}
	sState = std::to_string(I_State);
	cState = new char[sState.length() + 1];
	strcpy(cState, sState.c_str());

	sLife = std::to_string(I_Life);
	cLife = new char[sLife.length() + 1];
	strcpy(cLife, sLife.c_str());

	sTime = std::to_string(I_Time);
	cTime = new char[sTime.length() + 1];
	strcpy(cTime, sTime.c_str());

	sScore = std::to_string(I_Score);
	cScore = new char[sScore.length() + 1];
	strcpy(cScore, sScore.c_str());

	sCoin= std::to_string(I_Coin);
	cCoin = new char[sCoin.length() + 1];
	strcpy(cCoin, sCoin.c_str());

	pos.x = FrkCamera::m_hVpx/1;
	pos.y = FrkCamera::m_hVpy/1-200;
	
	if (abs(speedMario) <= _hero_SPEED)
	{
		spriteRender = sHub;
	}
	if (abs(speedMario) > _hero_SPEED && abs(speedMario) <= 3 + 1 * x / 6)
	{
		spriteRender = sHub1;
	}
	if (abs(speedMario) > _hero_SPEED + 1 * x / 6 && abs(speedMario) <= _hero_SPEED + 2 * x / 6)
	{
		spriteRender = sHub2;
	}
	if (abs(speedMario) > _hero_SPEED + 2 * x / 6 && abs(speedMario) <= _hero_SPEED + 3 * x / 6)
	{
		spriteRender = sHub3;
	}
	if (abs(speedMario) > _hero_SPEED + 3 * x / 6 && abs(speedMario) <= _hero_SPEED + 4 * x / 6)
	{
		spriteRender = sHub4;
	}
	if (abs(speedMario) > _hero_SPEED + 4 * x / 6 && abs(speedMario) <= _hero_SPEED + 5 * x / 6)
	{
		spriteRender = sHub5;
	}
	if (abs(speedMario) > _hero_SPEED + 5 * x / 6 && abs(speedMario) <= _hero_SPEED + 6 * x / 6)
	{
		if (n % 3 != 0)
			spriteRender = sHub6;
		else
			spriteRender = sHub7;
	}
}

void Infomation::Render()
{
	D3DXVECTOR2 iVector =  D3DXVECTOR2(180, 100);
	spriteRender->Render2(iVector);
	_LocalGraphic->nsDraw(cLife, D3DXVECTOR2(iVector.y - 37, iVector.x + 5), D3DCOLOR_XRGB(0, 0, 0));
	_LocalGraphic->nsDraw(cScore, D3DXVECTOR2(iVector.y + 10, iVector.x + 5), D3DCOLOR_XRGB(0, 0, 0));
	_LocalGraphic->nsDraw(cTime, D3DXVECTOR2(iVector.y +64, iVector.x + 5), D3DCOLOR_XRGB(0, 0, 0));
	_LocalGraphic->nsDraw(cCoin, D3DXVECTOR2(iVector.y + 69, iVector.x -3), D3DCOLOR_XRGB(0, 0, 0));
	_LocalGraphic->nsDraw(cState, D3DXVECTOR2(iVector.y -33, iVector.x - 3), D3DCOLOR_XRGB(0, 0, 0));

}
Infomation* Infomation::Instance = NULL;
Infomation* Infomation::GetInstance()
{
	if (Instance == NULL)
	{
		Instance = new Infomation(300, 0, 0, 4, 1);
	}
	return Instance;
}
