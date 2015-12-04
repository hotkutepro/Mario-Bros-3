#include "Brick.h"
#include"FrkShareControl.h"

Brick::Brick()
{
}

Brick::Brick(D3DXVECTOR2 pos, D3DXVECTOR2 speed) :Object(pos,speed)
{

}

Brick::Brick(typeObject _t) : Object(_t)
{

}


Brick::~Brick()
{
}

void Brick::Load()
{
	FrkTexture* tBrick;
	tBrick=	_LocalContent->LoadTexture("brick.png");
	m_hBrick = new FrkSprite(tBrick, 1, 1);
	SetPosition(230, 200);
	m_hBox = new Box(GetPosition().x,GetPosition().y,m_hBrick->_Width,m_hBrick->_Height);
}

void Brick::Render()
{
	m_hBrick->Render(GetPosition());
}

void Brick::Update(float x,float y)
{
	if (x==-1)
	{
		SetPosition(GetPosition().x+10, GetPosition().y);
	}
	if (x == 1)
	{
		SetPosition(GetPosition().x - 10, GetPosition().y);
	}
	if (y == -1)
	{
		SetPosition(GetPosition().x, GetPosition().y + 10);
	}
	if (y == 1)
	{
		SetPosition(GetPosition().x, GetPosition().y - 10);
	}
	m_hBox = new Box(GetPosition().x, GetPosition().y, m_hBrick->_Width, m_hBrick->_Height);
}

Box* Brick::getBox()
{
	return m_hBox;
}
