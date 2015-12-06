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

Object::Object(int _id,D3DXVECTOR2 pos, typeObject _type)
{
	id = _id;
	m_hPosition = pos;
	type = _type;
}

Object::Object(typeObject _type)
{
	type = _type;
}


Object::~Object()
{
}

void Object::Render()
{
	if (m_hCurrentSprite!=NULL&&m_hPosition!=NULL)
		m_hCurrentSprite->Render(m_hPosition);
}


void Object::Update(float gameTime)
{

}

void Object::SetPosition(int x, int y)
{
	m_hPosition = D3DXVECTOR2(x, y);
}

D3DXVECTOR2 Object::GetPosition()
{
	return m_hPosition;
}

void Object::Load()
{

}
void Object::setCurrentSprite(FrkSprite* s)
{
	m_hCurrentSprite = s;
}

FrkSprite* Object::getCurrentSprite()
{
	return m_hCurrentSprite;
}
