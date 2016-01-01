#include "E_Tortoise_Red.h"
#include"ResourcesManager.h"
#include "Collision.h"


E_Tortoise_Red::E_Tortoise_Red()
{
}


E_Tortoise_Red::~E_Tortoise_Red()
{
}

void E_Tortoise_Red::Load()
{
	E_TortoiseRedRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseRedRight);
	E_TurtoiseRedLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TurtoiseRedLeft);
	E_TortoiseshellRedLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellRedLeft);
	E_TortoiseshellRedRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellRedRight);
	E_TortoiseshellRedLeftReverse = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellRedLeftReverse);
	E_TortoiseshellRedRightReverse = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellRedRightReverse);
	setCurrentSprite(E_TortoiseRedRight);
	Object::Load();
	type = TYPEOBJECT::tortoise_red;	
	m_hState = ON_SPACE;
	m_hSpeed.x = -vx;
	m_hSpeed.y = -2;
	status = 0;
	IsControl = false;
}

void E_Tortoise_Red::Update(float gameTime)
{
	
	SetSprite();
	SetMove();
	Object::Update(gameTime);
	if (IsControl)
		SetControl();
	else
		MoveObject();
	Collision_Shell_Object();
	DelayNext(5);
}
void E_Tortoise_Red::Collision_Up()
{
	_LocalHero->m_hSpeed.y = 5;
	if (status == 0)
		m_hSpeed.x = 0;
	if (status == 1)
	{
		m_hSpeed.x = 0;		
		if (m_hSpeed.x == 0)
		{
			if (_LocalHero->m_hDirect == DIRECT::left)
				m_hSpeed.x = -3;
			else
				m_hSpeed.x = 3;
		}
		else
			m_hSpeed.x = 0;
		return;
	}
	status++;
	SetSprite();
}

Box* E_Tortoise_Red::GetBox_CLeft()
{
	Box* x = new Box();
	x->_position.x = m_hPosition.x;
	x->_position.y = m_hPosition.y;
	x->_size.x = GetBox()->_size.x / 2;
	x->_size.y = GetBox()->_size.y + 2;
	return x;
}

Box* E_Tortoise_Red::GetBox_CRight()
{
	Box* x = new Box();
	x->_position.x = m_hPosition.x + GetBox()->_size.x / 2;
	x->_position.y = m_hPosition.y;
	x->_size.x = GetBox()->_size.x / 2;
	x->_size.y = GetBox()->_size.y + 2;
	return x;
}

void E_Tortoise_Red::SetSprite()
{
	if (!life)
		return;
	if (status == 0)
	{
		if (m_hSpeed.x<0)
			setCurrentSprite(E_TurtoiseRedLeft);
		else
			setCurrentSprite(E_TortoiseRedRight);
	}
	else if (status == 1)
	{
		if (m_hSpeed.x<0)
			setCurrentSprite(E_TortoiseshellRedLeft);
		else
			setCurrentSprite(E_TortoiseshellRedRight);
	}
	else if (status == 2)
	{
		if (m_hSpeed.x<0)
			setCurrentSprite(E_TortoiseshellRedLeftReverse);
		else
			setCurrentSprite(E_TortoiseshellRedRightReverse);

	}
}


void E_Tortoise_Red::Collision_Down()
{

}

void E_Tortoise_Red::Collision_Left()
{		
	if (m_hSpeed.x!=0){
		_LocalHero->IsAttacked();
	}
	else
	if (_LocalHero->ready&&status >0)
	{
		IsControl = true;
	}
	else
	if (status >0)
	{		
		m_hSpeed.x = vx_run;
	}
}

void E_Tortoise_Red::Collision_Right()
{
	if (m_hSpeed.x!=0)
	{
		_LocalHero->IsAttacked();
	}
	else
	if (_LocalHero->ready&&status >0)
	{
		IsControl = true;
	}
	else if (status >0)
	{		
		m_hSpeed.x = -vx_run;
	}
}

void E_Tortoise_Red::SetMove()
{
	if (status!=0)
		return;
	if (m_hSpeed.x>0)
	{

		if (m_hObjectGround != NULL)
			if (!Collision::checkAABB(GetBox_CRight(), m_hObjectGround->GetBox()))
				m_hSpeed.x = -m_hSpeed.x;
	}
	else
	{
		if (m_hObjectGround != NULL)
			if (!Collision::checkAABB(GetBox_CLeft(), m_hObjectGround->GetBox()))
				m_hSpeed.x = -m_hSpeed.x;
	}
}


void E_Tortoise_Red::IsAttacked()
{
	status = 2;
	m_hSpeed.x = 0;
	SetSprite();

}

void E_Tortoise_Red::Collision_Shell_Object()
{
	if (status == 0 )
		return;
	vector<Object*> result;
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = QNode::s_IdObjectInViewPort.begin(); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);
		if (it_Object->second->id != id && (it_Object->second->type == tarnooki || it_Object->second->type == question_block || it_Object->second->type == tree_red_shoot || it_Object->second->type == brick))
		{
			float nx, ny;
			float time = Collision::sweptAABBCheck(GetBoxWithObject(it_Object->second), it_Object->second->GetBox(), nx, ny);
			if (time != 1&&nx!=0)
			{				
				it_Object->second->Die();
				m_hSpeed.x = -m_hSpeed.x;
				if (it_Object->second->type == tree_red_shoot)
				{
					Die();					
				}
			}

		}
	}
}

void E_Tortoise_Red::SetControl()
{
	if (IsControl)
	{
		if (!_LocalHero->ready)
		{			
			if (_LocalHero->m_hDirect == DIRECT::left)
				m_hSpeed.x = -vx_run;
			else
				m_hSpeed.x = vx_run;
			IsControl = false;
		}
		m_hPosition.y = _LocalHero->m_hPosition.y;
		if (_LocalHero->m_hDirect == DIRECT::left)
		{
			m_hPosition.x = _LocalHero->m_hPosition.x + -15;
		}
		else
		{
			m_hPosition.x = _LocalHero->m_hPosition.x - vx_run + _LocalHero->m_hCurrentSprite->_Width;
		}
	}
}

void E_Tortoise_Red::Die()
{
	life = false;
}
