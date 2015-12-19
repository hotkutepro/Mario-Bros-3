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
	if (m_hCurrentSprite != NULL&&life)
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
	life_state = 0;
	m_hObjectGround = NULL;
	m_hObjectLeft = NULL;
	m_hObjectRight = NULL;
	m_hSpeed.x = 0;
	m_hSpeed.y = 0;

	m_hBox = new Box();
	//m_hBoundBox = new Box();

	/*if (type == land || type == box || type == drain)// drain chua biet load sao
	{
		//m_hBoundBox->_size.x = m_hSize.x + 25;
		//m_hBoundBox->_size.y = m_hSize.y + 25;
		m_hBox->_position.x = m_hPosition.x;
		m_hBox->_position.y = m_hPosition.y;

		m_hBox->_size.x = m_hSize.x;
		m_hBox->_size.y = m_hSize.y;
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
	}*/

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
	m_hSpeed.x = 0;
}

void Object::FallDown(float remainingtime)
{
	if (m_hState == ON_GROUND)
		return;
	vector<Object*> Objects_Static = GetStaticObject();
	float time, nx, ny;
	for (int i = 0; i < Objects_Static.size(); i++)
	{
		time = Collision::sweptAABBCheck(GetBox(), Objects_Static.at(i)->GetBox(), nx, ny);
		if (time >= 0 && time < 1)
		{
			if (ny == 1)
			{
				m_hPosition.y += time*m_hSpeed.y;
				m_hObjectGround = Objects_Static.at(i);
				m_hSpeed.y = 0;
				m_hState = ON_GROUND;
			}
		}
	}	
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
	if (type == land || type == box || type == drain)// drain chua biet load sao
	{		
		m_hBox->_position.x = m_hPosition.x;
		m_hBox->_position.y = m_hPosition.y;

		m_hBox->_size.x = m_hSize.x;
		m_hBox->_size.y = m_hSize.y;
	}
	else
	{
		m_hBox->_position.x = m_hPosition.x;
		m_hBox->_position.y = m_hPosition.y;
		m_hSize.x = getCurrentSprite()->_Width;
		m_hSize.y = getCurrentSprite()->_Height;		
		m_hBox->_size.x = getCurrentSprite()->_Width;
		m_hBox->_size.y = getCurrentSprite()->_Height;
		m_hBox->_v = m_hSpeed;
	}
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
	Box* m_hBoundBox = new Box();
	m_hBoundBox->_position.x = m_hPosition.x - 12.5;
	m_hBoundBox->_position.y = m_hPosition.y + 12.5;
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
		if (it_Object->second->life == true && it_Object->second->type == brick)
			listobject.push_back(it_Object->second);
	}
	return listobject;

}

vector<Object*> Object::GetDynamicObject()
{
	vector<Object*> result;
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = QNode::s_IdObjectInViewPort.begin(); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);
		if (it_Object->second->life == false)
			continue;
		if (it_Object->second->type == tortoise || it_Object->second->type == tortoise_red || it_Object->second->type == tortoise_fly ||
			it_Object->second->type == tarnooki || it_Object->second->type == tarnooki_fly || it_Object->second->type == tree ||
			it_Object->second->type == tree_red || it_Object->second->type == tree_red_shoot)
		{
			result.push_back(it_Object->second);
		}
	}

	return result;
}

vector<Object*> Object::GetFoodObject()
{
	vector<Object*> result;
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = QNode::s_IdObjectInViewPort.begin(); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);
		if (it_Object->second->life == false)
			continue;
		if (it_Object->second->type == question_block || it_Object->second->type == coin || it_Object->second->type == leaf ||
			it_Object->second->type == leaf || it_Object->second->type == star || it_Object->second->type == p || it_Object->second->type == brick)
		{
			result.push_back(it_Object->second);
		}
	}

	return result;
}

vector<Object*> Object::GetStaticObject()
{
	vector<Object*> result;
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = QNode::s_IdObjectInViewPort.begin(); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);		
		if (it_Object->second->type == land || it_Object->second->type == question_block || it_Object->second->type == box)
		{
			result.push_back(it_Object->second);
		}
		if (it_Object->second->type == brick && it_Object->second->life == true)
			result.push_back(it_Object->second);
	}

	return result;
}

vector<Object*> Object::GetStaticObjectCanCollision()
{
	vector<Object*> result;
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = QNode::s_IdObjectInViewPort.begin(); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);
		//if (!Collision::checkAABB(GetBoundBox(), it_Object->second->GetBoundBox()))
			//continue;
		if (it_Object->second->type == land || it_Object->second->type == question_block || it_Object->second->type == box)
		{
			result.push_back(it_Object->second);
		}
		if (it_Object->second->type == brick && it_Object->second->life == true)
			result.push_back(it_Object->second);
	}

	return result;
}
void Object::EatFood()
{
	vector<Object*> objects_Food = GetFoodObject();
	float nx, ny, time;
	for (int i = 0; i < objects_Food.size(); i++)
	{
		if (objects_Food.at(i)->type == coin || objects_Food.at(i)->type == leaf || objects_Food.at(i)->type == p || objects_Food.at(i)->type == star)
		{
			if (Collision::checkAABB(GetBox(), objects_Food.at(i)->GetBox()))
				objects_Food.at(i)->life = false;
		}
		if (objects_Food.at(i)->type == question_block)
		{
			time = Collision::sweptAABBCheck(GetBox(), objects_Food.at(i)->GetBox(), nx, ny);
			if (time < 1 && time >= 0 && ny == -1)
			{
				mapObject::iterator it_up;
				it_up = QNode::m_Objects.find(objects_Food.at(i)->id - 178);
				if (objects_Food.at(i)->life_state == 0)
					it_up->second->life = true;
				objects_Food.at(i)->Die();
			}
		}
	}
}
void Object::KillEnemy()
{
	vector<Object*> objects_Enemy = GetDynamicObject();
	float nx, ny, time;
	for (int i = 0; i < objects_Enemy.size(); i++)
	{
		time = Collision::sweptAABBCheck(GetBox(), objects_Enemy.at(i)->GetBox(), nx, ny);
		if (time < 1 && time >= 0)
		{
			if (nx == 1)
			{

			}
			if (ny == 1)
			{

			}
			if (ny == 1)
			{
				objects_Enemy.at(i)->Die();
			}
			if (ny == -1)
			{

			}
		}
	}
}
void Object::Move()
{
	vector<Object*> object_static_can_collision = GetStaticObjectCanCollision();
	float time, nx, ny;
	switch (m_hState)
	{
	case ON_FLY:
		break;
	case FALL_DOWN:
		break;
	case ON_SPACE:
		object_static_can_collision = GetStaticObjectCanCollision();
		m_hObjectLeft = NULL;
		m_hObjectRight = NULL;
		for (int i = 0; i < object_static_can_collision.size(); i++)
		{
			time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->GetBox(), nx, ny);
			if (time < 1 && time >= 0){
				if (nx == 1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = 0;
					m_hObjectLeft = object_static_can_collision.at(i);
				}
				if (nx == -1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = 0;
					m_hObjectRight = object_static_can_collision.at(i);
				}
				if (ny == 1)
				{
					m_hPosition.y += time*m_hSpeed.y;/////////
					m_hSpeed.y = 0;
					m_hState = ON_GROUND;
					m_hBox->_position.x = 0;
					m_hObjectGround = object_static_can_collision.at(i);///////
				}
				if (ny == -1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.y += time*m_hSpeed.y;
					m_hSpeed.y = 0;
				}
			}
		}

		if (m_hObjectLeft == NULL || m_hObjectRight == NULL)
			m_hPosition.x += m_hSpeed.x;
		break;
	case ON_GROUND:

		object_static_can_collision = GetStaticObjectCanCollision();
		m_hObjectLeft = NULL;
		m_hObjectRight = NULL;
		for (int i = 0; i < object_static_can_collision.size(); i++)
		{
			time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->GetBox(), nx, ny);
			if (time < 1 && time >= 0){
				if (nx == 1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = 0;
					m_hObjectLeft = object_static_can_collision.at(i);
				}
				if (nx == -1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = 0;
					m_hObjectRight = object_static_can_collision.at(i);
				}
				if (ny == 1)
				{
					m_hPosition.y += time*m_hSpeed.y;/////////
					m_hSpeed.y = 0;
					m_hState = ON_GROUND;
					m_hBox->_position.x = 0;
					m_hObjectGround = object_static_can_collision.at(i);///////
				}
				if (ny == -1)
				{

				}
			}
		}
		/*if (m_hObjectLeft != NULL)
			if (!Collision::checkAABB(GetBox_CLeft(), m_hObjectLeft->GetBox()))
			m_hObjectLeft = NULL;
			if (m_hObjectRight != NULL)
			if (!Collision::checkAABB(GetBox_CRight(), m_hObjectRight->GetBox()))
			m_hObjectRight = NULL;
			if (m_hObjectLeft == NULL&&m_hSpeed.x>0 ||m_hObjectRight == NULL&&m_hSpeed<0)
			{
			m_hPosition.x += m_hSpeed.x;
			}*/
		if (m_hObjectLeft == NULL || m_hObjectRight == NULL)
			m_hPosition.x += m_hSpeed.x;
		break;

	}
}

Box* Object::GetBox_CLeft()
{
	Box* x = new Box();
	x->_position.x = m_hPosition.x - 1;
	x->_position.y = m_hPosition.y;
	x->_size = m_hBox->_size;
	return x;
}

Box* Object::GetBox_CRight()
{
	Box* x = new Box();
	x->_position.x = m_hPosition.x + 1;
	x->_position.y = m_hPosition.y;
	x->_size = m_hBox->_size;
	return x;
}

void Object::MoveObject()
{
	vector<Object*> object_static_can_collision = GetStaticObjectCanCollision();
	float time, nx, ny;
	switch (m_hState)
	{
	case ON_FLY:
		break;
	case FALL_DOWN:
		break;
	case ON_SPACE:
		object_static_can_collision = GetStaticObjectCanCollision();
		m_hObjectLeft = NULL;
		m_hObjectRight = NULL;
		for (int i = 0; i < object_static_can_collision.size(); i++)
		{
			time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->m_hBox, nx, ny);
			if (time < 1 && time >= 0){
				if (nx == 1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = 0;
					m_hObjectLeft = object_static_can_collision.at(i);
				}
				if (nx == -1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = 0;
					m_hObjectRight = object_static_can_collision.at(i);
				}
				if (ny == 1)
				{
					m_hPosition.y += time*m_hSpeed.y;/////////
					m_hSpeed.y = 0;
					m_hState = ON_GROUND;
					m_hBox->_position.x = 0;
					m_hObjectGround = object_static_can_collision.at(i);///////
				}
				if (ny == -1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.y += time*m_hSpeed.y;
					m_hSpeed.y = 0;
				}
			}
		}

		if (m_hObjectLeft == NULL || m_hObjectRight == NULL)
			m_hPosition.x += m_hSpeed.x;
		break;
	case ON_GROUND:

		object_static_can_collision = GetStaticObjectCanCollision();
		m_hObjectLeft = NULL;
		m_hObjectRight = NULL;
		for (int i = 0; i < object_static_can_collision.size(); i++)
		{
			time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->m_hBox, nx, ny);
			if (time < 1 && time >= 0){
				if (nx == 1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = -m_hSpeed.x;
					m_hObjectLeft = object_static_can_collision.at(i);
				}
				if (nx == -1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = -m_hSpeed.x;
					m_hObjectRight = object_static_can_collision.at(i);
				}
				if (ny == 1)
				{
					m_hPosition.y += time*m_hSpeed.y;/////////
					m_hSpeed.y = 0;
					m_hState = ON_GROUND;
					m_hBox->_position.x = 0;
					m_hObjectGround = object_static_can_collision.at(i);///////
				}
				if (ny == -1)
				{

				}
			}
		}		
		if (m_hObjectLeft == NULL || m_hObjectRight == NULL)
			m_hPosition.x += m_hSpeed.x;
		break;

	}
}

int Object::isOnGround()
{
	if (m_hObjectGround != NULL)
	{
		if (Collision::checkAABB(GetBox_CGround(), m_hObjectGround->GetBox()))
		{
			return 1;
		}
		else
			return 0;
	}
	return -1;
}




