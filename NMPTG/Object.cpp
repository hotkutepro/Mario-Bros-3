#include "Object.h"
#include"Box.h"
#include "Collision.h"
#include "QNode.h"

Object::Object()
{
}

Object::Object(D3DXVECTOR2 pos, D3DXVECTOR2 speed)
{
	m_hPosition = pos;
	m_hSpeed = speed;

}

Object::Object(int _id, D3DXVECTOR2 pos, TYPEOBJECT _type)
{
	id = _id;
	m_hPosition = pos;
	type = _type;
}

Object::Object(TYPEOBJECT _type)
{
	type = _type;
}


Object::~Object()
{
}

void Object::Render()
{
	if (m_hCurrentSprite != NULL&&m_hPosition != NULL&&life)
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
	m_hBox = new Box();
	m_hBox->_size.x = getCurrentSprite()->_Width;
	m_hBox->_size.y = getCurrentSprite()->_Height;
	m_hBoundBox = new Box();
	m_hBoundBox->_size.x = getCurrentSprite()->_Width + 25;
	m_hBoundBox->_size.y = getCurrentSprite()->_Height + 25;
	if (type == land || type == box){
		m_hBox->_size.x = m_hSize.x;
		m_hBox->_size.y = m_hSize.y;
	}
}
void Object::Update(float gameTime)
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


void Object::Die()
{
	life = false;
}

void Object::FallDown(float remainingtime)
{
	m_hBox->_position.y+= m_hBox->_v.y*remainingtime;
	m_hBox->_v.y += GRAVITY;
}

void Object::RenderDebug()
{
	RECT src;
	src.left = 0;
	src.right = src.left + 16;
	src.top = 0;
	src.bottom = src.top + 16;
	RECT a;
	a = m_hBox->getRect();
	_LocalGraphic->tDrawTexture(_LocalContent->LoadTexture("brick.png"), src, a, D3DXVECTOR2(8, 8), D3DCOLOR_XRGB(255, 255, 255), 0);
}

Box* Object::GetBox()
{
	m_hBox->_position.x = m_hPosition.x;
	m_hBox->_position.y = m_hPosition.y;
	m_hBox->_v.x = m_hSpeed.x;
	m_hBox->_v.y = m_hSpeed.y;
	return m_hBox;
}

void Object::RenderBoxDebug()
{
	RECT src;
	src.left = 0;
	src.right = src.left + 16;
	src.top = 0;
	src.bottom = src.top + 16;
	RECT a=m_hBox->getRect();	
	_LocalGraphic->tDrawTexture(_LocalContent->LoadTexture("abc.png"), src, a, D3DXVECTOR2(8, 8), D3DCOLOR_XRGB(255, 255, 255), 0);
}

list<Object*> Object::GetStaticObject()
{
	list<Object*> listobject;
	sId::iterator id_Objects;	
	mapObject::iterator it_Object;		
	for (id_Objects = QNode::s_IdObjectInViewPort.begin(); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);
		if (it_Object->second->type == land || it_Object->second->type == box || it_Object->second->type == brick)
		{
			listobject.push_back(it_Object->second);
		}
	}
	return listobject;
}

Box* Object::GetBoundBox()
{
	m_hBoundBox->_position.x = m_hPosition.x;
	m_hBoundBox->_position.y = m_hPosition.y;
	m_hBoundBox->_v.x = m_hSpeed.x;
	m_hBoundBox->_v.y = m_hSpeed.y;
	return m_hBoundBox;
}

void Object::RenderBoundBox()
{
	RECT src;
	src.left = 0;
	src.right = src.left + 16;
	src.top = 0;
	src.bottom = src.top + 16;
	RECT a = m_hBoundBox->getRect();
	_LocalGraphic->tDrawTexture(_LocalContent->LoadTexture("abc.png"), src, a, D3DXVECTOR2(8, 8), D3DCOLOR_XRGB(255, 255, 255), 0);
}
