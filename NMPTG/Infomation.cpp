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
	FrkTexture* tHub = _LocalContent->LoadTexture("resources\\Cut\\hub.png");
	FrkTexture* tHub1 = _LocalContent->LoadTexture("resources\\Cut\\hub1.png");
	FrkTexture* tHub2 = _LocalContent->LoadTexture("resources\\Cut\\hub2.png");
	FrkTexture* tHub3 = _LocalContent->LoadTexture("resources\\Cut\\hub3.png");
	FrkTexture* tHub4 = _LocalContent->LoadTexture("resources\\Cut\\hub4.png");
	FrkTexture* tHub5 = _LocalContent->LoadTexture("resources\\Cut\\hub5.png");
	FrkTexture* tHub6 = _LocalContent->LoadTexture("resources\\Cut\\hub6.png");
	FrkTexture* tHub7 = _LocalContent->LoadTexture("resources\\Cut\\hub7.png");
	sHub = new FrkSprite(tHub, 1, 1);
	sHub1 = new FrkSprite(tHub1, 1, 1);
	sHub2 = new FrkSprite(tHub2, 1, 1);
	sHub3 = new FrkSprite(tHub3, 1, 1);
	sHub4 = new FrkSprite(tHub4, 1, 1);
	sHub5 = new FrkSprite(tHub5, 1, 1);
	sHub6 = new FrkSprite(tHub6, 1, 1);
	sHub7 = new FrkSprite(tHub7, 1, 1);
	spriteRender = sHub;
}

void Infomation::Update()
{
	pos.x = FrkCamera::m_hVpx;
	pos.y = FrkCamera::m_hVpy-100;
}

void Infomation::Render()
{
	spriteRender->Render2(pos);
}
