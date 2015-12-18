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
	m_hObjectGround = NULL;
	m_hSpeed.x = 0;
	m_hSpeed.y = 0;

	m_hBox = new Box();
	//m_hBoundBox = new Box();
	
	if (type == land || type == box || type == drain)// drain chua biet load sao
	{
		//m_hBoundBox->_size.x = m_hSize.x + 25;
		//m_hBoundBox->_size.y = m_hSize.y + 25;
		m_hBox->_position.x = m_hPosition.x;
		m_hBox->_position.y = m_hPosition.y + m_hSize.y-1;

		m_hBox->_size.x = m_hSize.x;
		m_hBox->_size.y = 1;
	}
	else
	{
		m_hBox->_position.x = m_hPosition.x;
		m_hBox->_position.y = m_hPosition.y;
		m_hSize.x = getCurrentSprite()->_Width;//can cap nhat trong mario
		m_hSize.y = getCurrentSprite()->_Height;
		//m_hBoundBox->_size.x = getCurrentSprite()->_Width + 25;
		//m_hBoundBox->_size.y = getCurrentSprite()->_Height + 25;
		m_hBox->_size.x = getCurrentSprite()->_Width;
		m_hBox->_size.y = getCurrentSprite()->_Height;
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
	m_hBox->_position.y += m_hBox->_v.y*remainingtime;
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
	src.top = 0;
	src.right = src.left + 16;
	src.bottom = src.top + 16;
	RECT a;
	a.left = m_hBox->_position.x;
	a.top = m_hBox->_position.y;
	a.right = a.left + m_hBox->_size.x;
	a.bottom = a.top + m_hBox->_size.y;
	_LocalGraphic->tDrawTexture(_LocalContent->LoadTexture("abc.png"), src, a, D3DXVECTOR2(m_hBox->_size.x / 2, m_hBox->_size.y / 2), D3DCOLOR_XRGB(255, 255, 255), 0);
}
Box* Object::GetBoundBox()
{
	Box* m_hBoundBox =new Box();
	m_hBoundBox->_position.x = m_hPosition.x-12.5;
	m_hBoundBox->_position.y = m_hPosition.y+12.5;
	m_hBoundBox->_size.x = m_hBox->_size.x + 25;
	m_hBoundBox->_size.y = m_hBox->_size.y + 25;
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
	RECT a = GetBoundBox()->getRect();
	_LocalGraphic->tDrawTexture(_LocalContent->LoadTexture("abc.png"), src, a, D3DXVECTOR2(8, 8), D3DCOLOR_XRGB(255, 255, 255), 0);
}

Box* Object::GetBox_CGround()
{
	Box* x = new Box();
	x->_position.x = m_hPosition.x;
	x->_position.y = m_hPosition.y;
	x->_size = m_hBox->_size;
	x->_size.y += 5;
	return x;
}

list<Object*> Object::GetStaticObject_vx()
{

	list<Object*> listobject;
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = QNode::s_IdObjectInViewPort.begin(); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);
		if (it_Object->second->type == land || it_Object->second->type == question_block)
		{
			listobject.push_back(it_Object->second);
		}
		if (it_Object->second->life==true&&it_Object->second->type==brick)
			listobject.push_back(it_Object->second);
	}
	return listobject;

}

list<Object*> Object::GetDynamicObject()
{
	list<Object*> listobject;
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = QNode::s_IdObjectInViewPort.begin(); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);
		if (it_Object->second->life==false)
			continue;
		if (it_Object->second->type == tarnooki || it_Object->second->type == tarnooki_fly || it_Object->second->type == tortoise ||
			it_Object->second->type == tortoise_fly || it_Object->second->type == tortoise_red|| it_Object->second->type == tree||
			it_Object->second->type == tree_red || it_Object->second->type == tree_red_shoot|| it_Object->second->type == tree_shoot)			
		{
			listobject.push_back(it_Object->second);
		}
	}
	return listobject;
}

list<Object*> Object::GetFoodObject()
{
	list<Object*> listobject;
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = QNode::s_IdObjectInViewPort.begin(); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);
		if (it_Object->second->life == false)
			continue;
		if (it_Object->second->type == coin || it_Object->second->type == p|| it_Object->second->type == brick)
		{
			listobject.push_back(it_Object->second);
		}
	}
	return listobject;
}

list<Object*> Object::GetStaticObject()
{
	list<Object*> listobject;
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = QNode::s_IdObjectInViewPort.begin(); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);
		if (it_Object->second->type == land || it_Object->second->type == question_block || it_Object->second->type == box)
		{
			listobject.push_back(it_Object->second);
		}
		if (it_Object->second->type==brick && it_Object->second->life==true)
			listobject.push_back(it_Object->second);
	}
	return listobject;
}

list<Object*> Object::GetStaticObjectCanCollision()
{
	list<Object*> result;

	return result;
}
