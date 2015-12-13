#include "Object.h"
#include"Box.h"
#include"Hero.h"

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
	box->position.left = m_hPosition.x;
	box->position.top = m_hPosition.y;
	box->position.right = m_hPosition.x + m_hCurrentSprite->_Width;
	box->position.bottom = m_hPosition.y + m_hCurrentSprite->_Height;
	box->v.x = box->v.y = 0;	
}
void Object::Update(float gameTime)
{
	box->position.top += box->v.y;
	box->position.bottom += box->v.y;
	box->position.left += box->v.x;
	box->position.right += box->v.x;
	m_hPosition.x = box->position.left;
	m_hPosition.y = box->position.top;	
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
	m_hPosition.x=box->position.left;
	m_hPosition.y=box->position.top;
}

void Object::Tortoise_Shell()
{

}

void Object::Die()
{
	life = false;
}
