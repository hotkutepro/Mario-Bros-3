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
	_uprise = new Object();
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
		if (type ==tortoise||type==tortoise_red||type==tortoise_fly)
		{
			int i = id;
			Object* tmp = QNode::m_Objects_Dynamic.find(id)->second;

			m_hPosition.y = tmp->m_hPosition.y;
			m_hPosition.x = tmp->m_hPosition.x;
			status = 0;
			m_hState = tmp->m_hState;			
			m_hSpeed = tmp->m_hSpeed;
			SetSprite();
		}
		else
		{
			life = false;
		}
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

}

void Object::FallDown(float remainingtime, float Vy)
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
	Box* b = GetBox();
	RECT src;
	src.left = 0;
	src.right = src.left + 16;
	src.top = 0;
	src.bottom = src.top + 16;
	RECT a;
	a = m_hBox->getRect();
	_LocalGraphic->tDrawTexture(_LocalContent->LoadTexture("brick.png"), src, b->getRect(), D3DXVECTOR2(b->getCenter()), D3DCOLOR_XRGB(255, 255, 255), 0);
}

Box* Object::GetBox()
{
	if (type == land || type == box || type == drain || type == uprise||type==block)// drain chua biet load sao
	{
		m_hBox->_position.x = m_hPosition.x;
		m_hBox->_position.y = m_hPosition.y;

		m_hBox->_size.x = m_hSize.x;
		m_hBox->_size.y = m_hSize.y;
		m_hBox->_v.x = m_hBox->_v.y = 0;
	}
	else if (type == tortoise || type == tortoise_red || type == tortoise_fly)
	{
		m_hBox->_position.x = m_hPosition.x+3.5f;
		m_hBox->_position.y = m_hPosition.y;

		m_hBox->_size.x = m_hCurrentSprite->_Width-5;
		m_hBox->_size.y = m_hCurrentSprite->_Height-12;
		m_hBox->_v.x = m_hSpeed.x;
		m_hBox->_v.y = m_hSpeed.y;
	}
	else if (type==tarnooki_fly)
	{
		if (status == 0)
		{
			m_hBox->_position.x = m_hPosition.x;
			m_hBox->_position.y = m_hPosition.y;

			m_hBox->_size.x = m_hCurrentSprite->_Width;
			m_hBox->_size.y = m_hCurrentSprite->_Height - 13;
			m_hBox->_v.x = m_hSpeed.x;
			m_hBox->_v.y = m_hSpeed.y;
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
			it_Object->second->type == leaf || it_Object->second->type == star || it_Object->second->type == p || it_Object->second->type == brick || it_Object->second->type == oneup
			|| it_Object->second->type == brick)
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
		if (it_Object->second->type == block||it_Object->second->type == music || it_Object->second->type == land || it_Object->second->type == question_block || it_Object->second->type == box || it_Object->second->type == uprise)
		{
			result.push_back(it_Object->second);
		}
		if (it_Object->second->type == brick && it_Object->second->life == true && it_Object->second->status==0)
			result.push_back(it_Object->second);
		if (it_Object->second->type == coin && it_Object->second->life == true && it_Object->second->status == 1)
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
		
		if ((objects_Food.at(i)->type == coin&&objects_Food.at(i)->status == 0) || objects_Food.at(i)->type == leaf || objects_Food.at(i)->type == p || objects_Food.at(i)->type == star || objects_Food.at(i)->type == oneup || (objects_Food.at(i)->type == brick&&objects_Food.at(i)->status == 1))
		{
			if (Collision::checkAABB(GetBox(), objects_Food.at(i)->GetBox()))
			{
					objects_Food.at(i)->Die();
			}

		}
		if (objects_Food.at(i)->type == question_block || objects_Food.at(i)->type == brick || objects_Food.at(i)->type == coin&&objects_Food.at(i)->status == 1)
		{
			if (Collision::checkAABB(_LocalHero->GetBoxAttack(), objects_Food.at(i)->GetBox()))
			{
				objects_Food.at(i)->IsAttacked();
			}
		}
		if (objects_Food.at(i)->type == question_block)
		{
			time = Collision::sweptAABBCheck(GetBoxTop(), objects_Food.at(i)->GetBox(), nx, ny);
			if (time < 1 && time >= 0 && ny == -1)
			{
				mapObject::iterator it_up;
				it_up = QNode::m_Objects.find(objects_Food.at(i)->id - 178);
				if (objects_Food.at(i)->life_state == 0)
					objects_Food.at(i)->Die();

			}
		}
		if (objects_Food.at(i)->type == brick)
		{
			time = Collision::sweptAABBCheck(GetBoxTop(), objects_Food.at(i)->GetBox(), nx, ny);
			if (time < 1 && time >= 0 && ny == -1)
			{			
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
		Box* boxHero = GetBox();

		Box* boxObject = objects_Enemy.at(i)->GetBox();

		boxHero->_v.x -= boxObject->_v.x;
		if (objects_Enemy.at(i)->type == tarnooki_fly || objects_Enemy.at(i)->type == tortoise_fly)
		{
			boxHero->_v.y -= boxObject->_v.y;
		}		
		boxObject->_v.x = 0;
		boxObject->_v.y = 0;
		
		time = Collision::sweptAABBCheck(boxHero, boxObject, nx, ny);		
		
		if (time < 1 )
		{
			_LocalHero->RenderBoxCollision(objects_Enemy.at(i));
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
		}/*else
		{
			if (Collision::checkAABB(boxHero, boxObject))
			{
				time = Collision::sweptAABBCheck(boxHero, boxObject, nx, ny);
			}
		}*/
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
	x->_position.x = m_hPosition.x + 13;
	x->_position.y = m_hPosition.y;
	x->_size = m_hBox->_size;
	return x;
}

void Object::MoveObject()
{
	vector<Object*> object_static_can_collision = GetStaticObject();
	float time, nx, ny,ratio;
	switch (m_hState)
	{
	case ON_UPRISE:
		ratio = _uprise->m_hVector.y / _uprise->m_hVector.x;
		m_hSpeed.y = (m_hSpeed.x*ratio);		
		if ((!Collision::checkAABB(GetBox(), _uprise->GetBox())))
		{
			m_hState = ON_SPACE;			
			_uprise = NULL;			
			return;
		}
		for (int i = 0; i < object_static_can_collision.size(); i++)
		{
			time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->GetBox(), nx, ny);
			if (time < 1)
			{
				if (object_static_can_collision.at(i)->type == land)
				{
					if (nx !=0)
					{
						m_hPosition.x += m_hSpeed.x;												
						m_hSpeed.x = -m_hSpeed.x;
					}			
					if (ny==1)
					{
 						m_hObjectGround = object_static_can_collision.at(i);
						m_hState = ON_GROUND;
						return;
					}
					if (ny==-1)
					{
						m_hSpeed.x = -m_hSpeed.x;
					}
				}
				if (object_static_can_collision.at(i)->type == uprise&&_uprise->id != object_static_can_collision.at(i)->id)
				{					
					_uprise = object_static_can_collision.at(i);
				}
			}
		}		
			m_hPosition.x += m_hSpeed.x;						
			m_hPosition.y += m_hSpeed.y;

		return;
		break;
	case ON_SPACE:
		object_static_can_collision = GetStaticObject();
		m_hObjectLeft = NULL;
		m_hObjectRight = NULL;
		for (int i = 0; i < object_static_can_collision.size(); i++)
		{
			time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->GetBox(), nx, ny);
			if (time < 1)
			{
				if (object_static_can_collision.at(i)->type == uprise)
				{
					if (ny != 0)
						m_hPosition.y -= 2;
					m_hState = ON_UPRISE;
					_uprise = object_static_can_collision.at(i);
					return;
				}
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
				if (ny == 1)
				{
					if (status == 0 && (type == tarnooki_fly || type == tortoise_fly)){
						FallDown(time, 0);
						m_hSpeed.y = 6.5;
						return;
					}
					FallDown(time, 0);/////////
					m_hSpeed.y = 0;
					m_hState = ON_GROUND;
					m_hObjectGround = object_static_can_collision.at(i);///////
					//return;
				}
				if (ny == -1 && object_static_can_collision.at(i)->type != box)
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

		object_static_can_collision = GetStaticObject();
		m_hObjectLeft = NULL;
		m_hObjectRight = NULL;
		for (int i = 0; i < object_static_can_collision.size(); i++)
		{			
			time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->GetBox(), nx, ny);
			if (time < 1 && time >= 0 && object_static_can_collision.at(i)->type != box)
			{
				if (object_static_can_collision.at(i)->type == uprise)
				{
					m_hState = ON_UPRISE;					
					_uprise = object_static_can_collision.at(i);
					m_hPosition.x += m_hSpeed.x;
					if (nx==1)
					{
						m_hPosition.x += 1;
					}
					if (nx == -1)
					{
						m_hPosition.x -= 1;
					}
					return;
				}
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


void Object::IsAttacked()
{
	
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

Box* Object::GetBoxWithObject(Object* object)
{
	Box* x = new Box();
	x->_position.y = m_hPosition.y;
	x->_position.x = m_hPosition.x;
	x->_size.y = getCurrentSprite()->_Height;
	x->_size.x = getCurrentSprite()->_Width;
	x->_v.x = m_hSpeed.x - object->m_hSpeed.x;
	x->_v.y = m_hSpeed.y - object->m_hSpeed.y;
	return x;
}

void Object::Collision_Leaf()
{

}

void Object::Collision_Coin()
{

}

void Object::Collision_Mushroom()
{

}

void Object::Collision_1up()
{

}

void Object::RenderBoxCollision(Object* object)
{

}

void Object::RenderAffection()
{

}

void Object::RenderBoxShadow()
{
	RECT src;
	src.left = 0;
	src.right = src.left + 16;
	src.top = 0;
	src.bottom = src.top + 16;
	RECT a;	
	a = m_hBox_Shadow->getRect();		
	_LocalGraphic->tDrawTexture(_LocalContent->LoadTexture("brick.png"), src, a, D3DXVECTOR2(m_hBox_Shadow->getCenter()), D3DCOLOR_XRGB(0, 0, 255), 0);
}




