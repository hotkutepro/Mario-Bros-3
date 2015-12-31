#include "Infomation.h"
#include "FrkTexture.h"
#include "FrkShareControl.h"
#include "FrkCamera.h"

 
Infomation::Infomation()
{
}

Infomation::Infomation(float _time, int _score, int _coin, int _life, int a)
{
	I_Time = _time;
	I_Score = _score;
	I_Coin = _coin;
	I_Life = _life;
	I_A = a;
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
	spriteRender = sHub6;
}

void Infomation::Update()
{
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
}

void Infomation::Render()
{
	D3DXVECTOR2 iVector =  D3DXVECTOR2(180, 100);
	spriteRender->Render2(iVector);
	_LocalGraphic->nsDraw(cLife, D3DXVECTOR2(iVector.y - 37, iVector.x + 5), D3DCOLOR_XRGB(0, 0, 0));
	_LocalGraphic->nsDraw(cScore, D3DXVECTOR2(iVector.y + 29, iVector.x + 5), D3DCOLOR_XRGB(0, 0, 0));
	_LocalGraphic->nsDraw(cTime, D3DXVECTOR2(iVector.y +69, iVector.x + 5), D3DCOLOR_XRGB(0, 0, 0));
	_LocalGraphic->nsDraw(cCoin, D3DXVECTOR2(iVector.y + 69, iVector.x -3), D3DCOLOR_XRGB(0, 0, 0));

}
