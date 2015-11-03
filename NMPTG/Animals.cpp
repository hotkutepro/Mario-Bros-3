#include "Animals.h"
#include "FrkShareControl.h"

Animals::Animals()
{
	m_hSpeed = 4;
}


Animals::~Animals()
{
}

void Animals::Load()
{
	FrkTexture* tLeft;
	tLeft = _LocalContent->LoadTexture("marioleft.png");
	FrkTexture* tRight;
	tRight = _LocalContent->LoadTexture("marioright.png");
	m_hMarioRight = new FrkSprite(tRight, 32, 16,2,2);
	m_hMarioLeft = new FrkSprite(tLeft, 64, 16, 4, 4);
	m_hRenderMario = m_hMarioRight;
	
}

void Animals::Render()
{
	m_hRenderMario->Render(m_hPosition);
}
float delay = 0;
void Animals::Update(float gameTime)
{
	
	//delay += gameTime / 10;
   	if (m_hPosition.y > 300) m_hPosition.y -= 5;//mario_vy -= FALLDOWN_VELOCITY_DECREASE;
	else if (m_hPosition.y<200)
	{
		m_hPosition.y = 200;
		//mario_vy = 0;
	}
	/*if (delay > gameTime)
	{
		m_hRenderMario->Next();
		delay = 0;
	}

	m_hPosition.x+=m_hSpeed;
	if (m_hPosition.x> 200)
	{
		m_hRenderMario = m_hMarioLeft;
		m_hSpeed = -m_hSpeed;
	}
	else if (m_hPosition.x < 50)
	{
		m_hRenderMario = m_hMarioRight;
		m_hSpeed = -m_hSpeed;
	}*/
	m_hRenderMario->Next();
		
}

void Animals::SetSite(int x, int y)
{
	m_hPosition.x = x;
	m_hPosition.y = y;
	m_hPosition.x = x;
	m_hPosition.y = y;
}

D3DXVECTOR2 Animals::getPosition()
{
	return m_hPosition;
}
