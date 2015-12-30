#include "E_Tortoise.h"
#include"ResourcesManager.h"
#include"Collision.h"


E_Tortoise::E_Tortoise()
{
}


E_Tortoise::~E_Tortoise()
{
}

void E_Tortoise::Load()
{	
	E_TortoiseGreenLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseGreenLeft);
	E_TortoiseGreenRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseGreenRight);
	E_TortoiseshellGreenLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenLeft);
	E_TortoiseshellGreenRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenRight);
	E_TortoiseshellGreenLeftReverse = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenLeftReverse);
	E_TortoiseshellGreenRightReverse = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenRightReverse);
	setCurrentSprite(E_TortoiseGreenLeft);	
	Object::Load();
	type = TYPEOBJECT::tortoise;
	m_hDirect = DIRECT::left;
	m_hSpeed.x = -vx; 
	m_hSpeed.y = -2;
	m_hState = ON_SPACE;	
	IsControl = false;
	status = 0;
}

void E_Tortoise::Update(float gameTime)
{	
	
	Object::Update(gameTime);	
	if (IsControl)
		SetControl();
	else
		MoveObject();	
	SetSprite();
	Collision_Shell_Object();
	
}

void E_Tortoise::Die()
{	
	life = false;
}

void E_Tortoise::Collision_Up()
{	
	_LocalHero->m_hSpeed.y = 5;	
	if (status == 0)
		m_hSpeed.x = 0;
	if (status == 1||status==2)
	{
		m_hSpeed.x = 0;		
		if (m_hSpeed.x == 0)
		{
			if (_LocalHero->m_hDirect == DIRECT::left)
				m_hSpeed.x = -vx_run;
			else
				m_hSpeed.x = vx_run;
		}
		else
			m_hSpeed.x = 0;
		return;
	}
	status++;
	SetSprite();
}

void E_Tortoise::Collision_Down()
{

}

void E_Tortoise::Collision_Left()
{
	if (m_hSpeed.x!=0){
		_LocalHero->IsAttacked();
	}
	else
	if (_LocalHero->ready&&status == 1 || status == 2)
	{
		IsControl = true;
	}
	else
	if (status == 1||status==2)
	{				
		m_hSpeed.x = vx_run;		
	}
}

void E_Tortoise::Collision_Right()
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

void E_Tortoise::SetSprite()
{
	if (status == 0)
	{
		if (m_hSpeed.x<0)
			setCurrentSprite(E_TortoiseGreenLeft);
		else
			setCurrentSprite(E_TortoiseGreenRight);
	}
	if (status == 1)
	{
		if (m_hSpeed.x<0)
			setCurrentSprite(E_TortoiseshellGreenLeft);
		else
			setCurrentSprite(E_TortoiseshellGreenRight);
	}
	if (status == 2)
	{
		if (m_hSpeed.x<0)
			setCurrentSprite(E_TortoiseshellGreenLeftReverse);
		else
			setCurrentSprite(E_TortoiseshellGreenRightReverse);
	}
}

void E_Tortoise::IsAttacked()
{
	status = 2;
	m_hSpeed.x = 0;
	SetSprite();
}

void E_Tortoise::SetControl()
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
			m_hPosition.x = _LocalHero->m_hPosition.x -vx_run +_LocalHero->m_hCurrentSprite->_Width;
		}
	}
}


void E_Tortoise::Collision_Shell_Object()
{
	if (status == 0 || m_hSpeed.x==0)
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
				it_Object->second->Die();
			}

		}
	}
}
