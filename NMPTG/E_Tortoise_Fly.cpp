#include "E_Tortoise_Fly.h"
#include"ResourcesManager.h"
#include "Collision.h"

E_Tortoise_Fly::E_Tortoise_Fly()
{
}


E_Tortoise_Fly::~E_Tortoise_Fly()
{
}

void E_Tortoise_Fly::Load()
{	
	E_FlyTortoiseGreenLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_FlyTortoiseGreenLeft);
	E_FlyTortoiseGreenRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_FlyTortoiseGreenRight);
	E_TortoiseGreenLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseGreenLeft);
	E_TortoiseGreenRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseGreenRight);
	E_TortoiseshellGreenLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenLeft);
	E_TortoiseshellGreenRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenRight);
	E_TortoiseshellGreenLeftReverse = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenLeftReverse);
	E_TortoiseshellGreenRightReverse = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenRightReverse);
	setCurrentSprite(E_FlyTortoiseGreenLeft);
	Object::Load();
	status = 0;
	type = TYPEOBJECT::tortoise_fly;	
	m_hState = ON_SPACE;
	m_hSpeed.x = 2; m_hSpeed.y = -2;
	IsControl = false;
}

void E_Tortoise_Fly::Update(float gameTime)
{	
	Object::Update(gameTime);	
	if (IsControl)
		SetControl();
	else
		MoveObject();
	Collision_Shell_Object();
	CollistionWithObject();
	SetSprite();
	DelayNext(3);
}

void E_Tortoise_Fly::Collision_Up()
{
	_LocalHero->m_hSpeed.y = 5;
	if (status == 1)
		m_hSpeed.x = 0;
	if (status == 2||status==3)
	{				
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
}

void E_Tortoise_Fly::Collision_Down()
{
	if (status == 0){
		_LocalHero->IsAttacked();
	}
}

void E_Tortoise_Fly::Collision_Left()
{
	if (m_hSpeed.x != 0){
		_LocalHero->IsAttacked();
	}
	else if (status >1 && _LocalHero->ready)
		IsControl = true;
	else if (status >1)
	{				
		m_hSpeed.x = 3;
	}	
	SetSprite();
}

void E_Tortoise_Fly::Collision_Right()
{
	if (m_hSpeed.x != 0){
		_LocalHero->IsAttacked();
	}
	else if (status >= 2 && _LocalHero->ready)
		IsControl = true;
	else if (status >=2)
	{
		m_hSpeed.x = 0;		
		m_hSpeed.x = -3;		
	}	
	SetSprite();
}
void E_Tortoise_Fly::SetSprite()
{	
	if (status == 0)
	{
		if (m_hSpeed.x<0)
			setCurrentSprite(E_FlyTortoiseGreenLeft);
		else
			setCurrentSprite(E_FlyTortoiseGreenRight);
	}
	else if (status == 1)
	{
		if (m_hSpeed.x<0)
			setCurrentSprite(E_TortoiseGreenLeft);
		else
			setCurrentSprite(E_TortoiseGreenRight);
	}
	else if (status == 2){
		if (m_hSpeed.x<0)
			setCurrentSprite(E_TortoiseshellGreenLeft);
		else
			setCurrentSprite(E_TortoiseshellGreenRight);
	}
	else{
		if (m_hSpeed.x<0)
			setCurrentSprite(E_TortoiseshellGreenLeftReverse);
		else
			setCurrentSprite(E_TortoiseshellGreenRightReverse);
	}
}

void E_Tortoise_Fly::IsAttacked()
{
	status = 3;
	m_hSpeed.x = 0;
	SetSprite();
}
void E_Tortoise_Fly::CollistionWithObject()
{
	if (status != 0)
		return;
	vector<Object*> result;
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = QNode::s_IdObjectInViewPort.begin(); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);
		if (it_Object->second->id != id && (it_Object->second->type == tortoise_fly || it_Object->second->type == tortoise))
		{
			float nx, ny;
			float time = Collision::sweptAABBCheck(GetBoxWithObject(it_Object->second), it_Object->second->GetBox(), nx, ny);
			if (time != 1&&it_Object->second->status==0)
			{
				m_hSpeed.x = -m_hSpeed.x;
				it_Object->second->m_hSpeed.x = -it_Object->second->m_hSpeed.x;
			}

		}
	}
}

void E_Tortoise_Fly::Die()
{
	life = false;
}

void E_Tortoise_Fly::Collision_Shell_Object()
{
	if (status == 0 ||status==1|| m_hSpeed.x == 0)
		return;
	vector<Object*> result;
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = QNode::s_IdObjectInViewPort.begin(); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);
		if (it_Object->second->id != id && (it_Object->second->type == tortoise_fly || it_Object->second->type == tortoise))
		{
			float nx, ny;
			float time = Collision::sweptAABBCheck(GetBoxWithObject(it_Object->second), it_Object->second->GetBox(), nx, ny);
			if (time != 1)
			{
				//m_hSpeed.x = -m_hSpeed.x;
				it_Object->second->Die();
			}

		}
	}
}

void E_Tortoise_Fly::SetControl()
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

