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
	if (m_hCurrentSprite!=NULL&&m_hPosition!=NULL&&life)
		m_hCurrentSprite->Render(m_hPosition);
}


void Object::Update(float gameTime)
{
	
	box->x = GetPosition().x;
	box->y = GetPosition().y;
	box->vx = m_hSpeed.x;
	box->vy = m_hSpeed.y;
	m_hPosition.x += m_hSpeed.x*gameTime;
	m_hPosition.y += m_hSpeed.y*gameTime;
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
	life = true;
	m_hSpeed.x = 0;
	m_hSpeed.y = 0;
	box = new Box();
	box->x = GetPosition().x;
	box->y = GetPosition().y;
	box->vx = 0;
	box->vy = 0;
	if (m_hCurrentSprite)
	{
		box->w = m_hCurrentSprite->_Width;
		box->h = m_hCurrentSprite->_Height;
	}
	else{
		box->w = box->h = 16;
	}
}
void Object::setCurrentSprite(FrkSprite* s)
{
	m_hCurrentSprite = s;
}

FrkSprite* Object::getCurrentSprite()
{
	return m_hCurrentSprite;
}

void Object::UpdateBox(float gameTime)
{
	box->x = GetPosition().x;
	box->y = GetPosition().y;
}

void Object::Tortoise_Shell()
{

}

void Object::Die()
{
	life = false;
}
