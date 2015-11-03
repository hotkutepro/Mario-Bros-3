#include "Object.h"


Object::Object()
{
}

Object::Object(D3DXVECTOR2 pos, D3DXVECTOR2 speed)
{
	m_hPosition = pos;
	m_hSpeed = speed;
	m_hAcceleration = 0;
}


Object::~Object()
{
}

void Object::Load(FrkContent*)
{

}

void Object::Render()
{

}


void Object::Update(float gameTime)
{

}

void Object::SetSite(int x, int y)
{
	m_hPosition = D3DXVECTOR2(x, y);
}

D3DXVECTOR2 Object::GetPosition()
{
	return m_hPosition;
}
