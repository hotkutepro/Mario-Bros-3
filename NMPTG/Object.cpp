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
}
void Object::Update(float gameTime)
{
	if (m_hPosition.y < 0)
	{
		Object* tmp = QNode::m_Objects_Dynamic.find(id)->second;
		m_hPosition.y = tmp->m_hPosition.y;
		m_hPosition.x = tmp->m_hPosition.x;
		status = tmp->status;
		m_hState = tmp->m_hState;
		m_hDirect = tmp->m_hDirect;		
		m_hSpeed = tmp->m_hSpeed;
		SetSprite();		
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


void Object::Die()
{
	life = false; 
	m_hSpeed.x = 0;
}

void Object::FallDown(float remainingtime,float Vy)
{	
	m_hPosition.y += m_hSpeed.y*remainingtime;
	if (Vy != 0)
	{
		m_hSpeed.y = Vy;
	}
	else
	{
		m_hSpeed.y += GRAVITY;
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
	_LocalGraphic->tDrawTexture(_LocalContent->LoadTexture("brick.png"), src, a, D3DXVECTOR2(m_hBox->getCenter()), D3DCOLOR_XRGB(255, 255, 255), 0);
}

Box* Object::GetBox()
{	
	if (type == land || type == box || type == drain ||type==uprise)// drain chua biet load sao
	{		
		m_hBox->_position.x = m_hPosition.x;
		m_hBox->_position.y = m_hPosition.y;

		m_hBox->_size.x = m_hSize.x;
		m_hBox->_size.y = m_hSize.y;
	}
	else if (type == mario)
	{

	}
	else
	{
		m_hBox->_position.x = m_hPosition.x;
		m_hBox->_position.y = m_hPosition.y;

		m_hBox->_size.x = m_hCurrentSprite->_Width;
		m_hBox->_size.y = m_hCurrentSprite->_Height;
		m_hBox->_v.x = m_hSpeed.x;
		m_hBox->_v.y = m_hSpeed.y;
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
	RECT a = m_hBox->getRect();
	_LocalGraphic->tDrawTexture(_LocalContent->LoadTexture("abc.png"), src, a, D3DXVECTOR2(m_hBox->getCenter()), D3DCOLOR_XRGB(255, 255, 255), 0);
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
		if (it_Object->second->type == land || it_Object->second->type == question_block || it_Object->second->type == box||it_Object->second->type==uprise)
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
			{			
				objects_Food.at(i)->life = false;
			}
				
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
		if (Collision::checkAABB(_LocalHero->GetBoxAttack(), objects_Enemy.at(i)->GetBox()))
		{
			objects_Enemy.at(i)->IsAttacked();
		}
		time = Collision::sweptAABBCheck(GetBox(), objects_Enemy.at(i)->GetBox(), nx, ny);
		if (time < 1 && time >= 0)
		{
		
			if (nx == 1)
			{
				
				objects_Enemy.at(i)->Collision_Right();
			}		
			if (nx == -1)
			{
				objects_Enemy.at(i)->Collision_Left();
			}
			if (ny == 1)
			{
				objects_Enemy.at(i)->Collision_Up();
			}
			if (ny == -1)
			{
				objects_Enemy.at(i)->Collision_Down();
			}
		}
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
	case ON_SPACE:
		object_static_can_collision = GetStaticObject();
		m_hObjectLeft = NULL;
		m_hObjectRight = NULL;
		for (int i = 0; i < object_static_can_collision.size(); i++)
		{
			time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->GetBox(), nx, ny);
			if (time < 1){
				//time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->GetBox(), nx, ny);
				if (nx == 1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = -m_hSpeed.x;
					m_hObjectLeft = object_static_can_collision.at(i);
					SetSprite();
				}
				if (nx == -1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = -m_hSpeed.x;
					m_hObjectRight = object_static_can_collision.at(i);
					SetSprite();
				}
				if (ny == 1 )
				{
					if (status==0&&(type == tarnooki_fly || type == tortoise_fly)){
						FallDown(time, 0);
						m_hSpeed.y = 5;
						return;
					}
					FallDown(time, 0);/////////
					m_hSpeed.y = 0;
					m_hState = ON_GROUND;
					m_hObjectGround = object_static_can_collision.at(i);///////
					//return;
				}
				if ( ny == -1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.y += time*m_hSpeed.y;
					m_hSpeed.y = 0;
				}
			}
		}
		FallDown(1, 0);
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
			if (time < 1 && time >= 0 && object_static_can_collision.at(i)->type != box){
				
				if (nx == 1 && object_static_can_collision.at(i)->type != box)
				{

					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = -m_hSpeed.x;
					m_hObjectLeft = object_static_can_collision.at(i);
					SetSprite();
				}
				if (nx == -1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = -m_hSpeed.x;
					m_hObjectRight = object_static_can_collision.at(i);
 					SetSprite();
				}
			}
		}
		if (this->m_hObjectGround != NULL)
		{
			if (!Collision::checkAABB(this->GetBox_CGround(), this->m_hObjectGround->m_hBox))
			{
				m_hState = ON_SPACE;
			}
		}
		if (m_hObjectLeft == NULL && m_hObjectRight == NULL)
			m_hPosition.x += m_hSpeed.x;
		break;

	}
}

//int Object::isOnGround()
//{
//	if (m_hObjectGround != NULL)
//	{
//		if (Collision::checkAABB(GetBox_CGround(), m_hObjectGround->GetBox()))
//		{
//			return 1;
//		}
//		else
//			return 0;
//	}
//	return -1;
//}

int Object::getDirectWithHero(Object* hero)
{
	if (m_hPosition.y < hero->m_hPosition.y)
	{
		if (m_hPosition.x < hero->m_hPosition.x)
			return 3;
		else
		{
			return 2;
		}
	}
	if (m_hPosition.x < hero->m_hPosition.x)
		return 4;
	return 1;
}

void Object::WatchUp()
{
	life = true;
}

void Object::DelayNext(float frame)
{
	delayNext++;
	if (delayNext >= frame)
	{
		getCurrentSprite()->Next();
		delayNext = 0;
	}
}



void Object::Collision_Up()
{

}

void Object::Collision_Down()
{

}

void Object::Collision_Left()
{

}

void Object::Collision_Right()
{

}

vector<Object*> Object::GetListTortoise()
{
	vector<Object*> result;
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = QNode::s_IdObjectInViewPort.find(id); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);
		if (!it_Object->second->life)
			continue;
		if (it_Object->second->type == tortoise||it_Object->second->type==tortoise_fly)
		{
			result.push_back(it_Object->second);
		}		
	}

	return result;
}
 
void Object::IsAttacked()
{
	life = false;
}

Box* Object::GetBoxTop()
{
	return new Box;
}

Box* Object::GetBoxAttack()
{	
	return new Box;
}

Box* Object::GetBox_CGround()
{
	return new Box;
}

void Object::SetSprite()
{

}

void Object::ResetObject()
{

}




