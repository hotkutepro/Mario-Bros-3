#include "E_Tortoise.h"
#include"ResourcesManager.h"


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
	m_hSpeed.x = -1; m_hSpeed.y = -2;
	m_hState = ON_SPACE;
	IsRun = false;
	status = 0;
}

void E_Tortoise::Update(float gameTime)
{	
	Object::Update(gameTime);
	UpdateDirect();
	MoveObject();
}

void E_Tortoise::Tortoise_Shell()
{
	setCurrentSprite(E_TortoiseshellGreenLeft);
}

void E_Tortoise::Die()
{	


}

void E_Tortoise::Collision_Up()
{	
	_LocalHero->m_hSpeed.y = 5;	
	if (status == 0)
		m_hSpeed.x = 0;
	if (status == 1)
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

void E_Tortoise::Collision_Down()
{

}

void E_Tortoise::Collision_Left()
{
	if (status == 0){
		_LocalHero->IsAttacked();
	}
	if (status == 1)
	{
		m_hSpeed.x = 0;
		IsRun = true;
		m_hSpeed.x = 3;		
	}
}

void E_Tortoise::Collision_Right()
{
	if (status == 0)
	{
		_LocalHero->IsAttacked();
	}
	if (status == 1)
	{
		m_hSpeed.x = 0;
		IsRun = true;
		m_hSpeed.x = -3;
		return;
	}
}

void E_Tortoise::SetSprite()
{
	if (status == 0)
	{
		if (m_hDirect == DIRECT::left)
			setCurrentSprite(E_TortoiseGreenLeft);
		else
			setCurrentSprite(E_TortoiseGreenRight);
	}
	if (status == 1)
	{
		if (m_hDirect == DIRECT::left)
			setCurrentSprite(E_TortoiseshellGreenLeft);
		else
			setCurrentSprite(E_TortoiseshellGreenRight);
	}
	if (status == 2)
	{
		if (m_hDirect == DIRECT::left)
			setCurrentSprite(E_TortoiseshellGreenLeftReverse);
		else
			setCurrentSprite(E_TortoiseshellGreenRightReverse);
	}
}
void E_Tortoise::UpdateDirect()
{
	if (m_hSpeed.x > 0)
		m_hDirect = DIRECT::right;
	else if (m_hSpeed.x < 0)
		m_hDirect = DIRECT::left;
}

void E_Tortoise::IsAttacked()
{
	status = 2;
	m_hSpeed.x = 0;
	SetSprite();
}
