#include "E_Tortoise_Fly.h"
#include"ResourcesManager.h"

E_Tortoise_Fly::E_Tortoise_Fly()
{
}


E_Tortoise_Fly::~E_Tortoise_Fly()
{
}

void E_Tortoise_Fly::Load()
{
	m_hSpeed.x = 0.02; m_hSpeed.y = -0.002;
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
	m_hDirect = DIRECT::left;
	m_hState = ON_SPACE;
	m_hSpeed.x = -1; m_hSpeed.y = -2;
	IsRun = false;
}

void E_Tortoise_Fly::Update(float gameTime)
{	
	Object::Update(gameTime);
	//UpdateDirect();
	MoveObject();
}

void E_Tortoise_Fly::Collision_Up()
{
	_LocalHero->m_hSpeed.y = 5;
	if (status == 1)
		m_hSpeed.x = 0;
	if (status == 2)
	{
		m_hSpeed.x = 0;
		IsRun = !IsRun;
		if (IsRun)
		{
			if (m_hDirect == DIRECT::left)
				m_hSpeed.x = -3;
			else
				m_hSpeed.x = 3;
		}

		return;
	}
	status++;
	SetSprite();
}

void E_Tortoise_Fly::Collision_Down()
{

}

void E_Tortoise_Fly::Collision_Left()
{
	if (status == 2)
	{
		m_hSpeed.x = 0;
		IsRun = true;
		m_hSpeed.x = 3;
	}
	SetSprite();
}

void E_Tortoise_Fly::Collision_Right()
{
	if (status == 2)
	{
		m_hSpeed.x = 0;
		IsRun = true;
		m_hSpeed.x = -3;		
	}
	SetSprite();
}
void E_Tortoise_Fly::SetSprite()
{
	UpdateDirect();
	if (status == 0)
	{
		if (m_hDirect == DIRECT::left)
			setCurrentSprite(E_FlyTortoiseGreenLeft);
		else
			setCurrentSprite(E_FlyTortoiseGreenRight);
	}
	else if (status == 1)
	{
		if (m_hDirect == DIRECT::left)
			setCurrentSprite(E_TortoiseGreenLeft);
		else
			setCurrentSprite(E_TortoiseGreenRight);
	}
	else if (status == 2){
		if (m_hDirect == DIRECT::right)
			setCurrentSprite(E_TortoiseshellGreenLeft);
		else
			setCurrentSprite(E_TortoiseshellGreenRight);
	}
	else{
		if (m_hDirect == DIRECT::left)
			setCurrentSprite(E_TortoiseshellGreenLeftReverse);
		else
			setCurrentSprite(E_TortoiseshellGreenRightReverse);
	}
}
void E_Tortoise_Fly::UpdateDirect()
{
	if (m_hSpeed.x > 0)
		m_hDirect = DIRECT::right;
	else if (m_hSpeed.x < 0)
		m_hDirect = DIRECT::left;
}

void E_Tortoise_Fly::IsAttacked()
{

}
