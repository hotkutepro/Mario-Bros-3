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
	m_hDirect = DIRECT::left;
	m_hState = ON_SPACE;
	m_hSpeed.x = -1;
	m_hSpeed.y = -2;
	status = 0;
	IsRun = false;
}

void E_Tortoise_Red::Update(float gameTime)
{

	UpdateDirect();
	SetSprite();
	SetMove();
	Object::Update(gameTime);
	MoveObject();

}
void E_Tortoise_Red::Collision_Up()
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
		if (m_hDirect == DIRECT::left)
			setCurrentSprite(E_TurtoiseRedLeft);
		else
			setCurrentSprite(E_TortoiseRedRight);
	}
	else if (status == 1)
	{
		if (m_hDirect == DIRECT::left)
			setCurrentSprite(E_TortoiseshellRedLeft);
		else
			setCurrentSprite(E_TortoiseshellRedRight);
	}
	else if (status == 2)
	{
		if (m_hDirect == DIRECT::left)
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
	if (status == 1)
	{
		m_hSpeed.x = 0;
		IsRun = true;		
			m_hSpeed.x = 3;		

		return;
	}
}

void E_Tortoise_Red::Collision_Right()
{
	if (status == 1)
	{
		m_hSpeed.x = 0;
		IsRun = true;		
		m_hSpeed.x = -3;
		return;
	}
}

void E_Tortoise_Red::SetMove()
{
	if (IsRun)
		return;
	if (m_hDirect == DIRECT::right)
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

void E_Tortoise_Red::UpdateDirect()
{
	if (m_hSpeed.x > 0)
		m_hDirect = DIRECT::right;
	else if (m_hSpeed.x < 0)
		m_hDirect = DIRECT::left;
}
