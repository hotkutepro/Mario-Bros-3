#include "F_Coin.h"
#include"ResourcesManager.h"
#include "FrkShareControl.h"

F_Coin::F_Coin()
{
}


F_Coin::~F_Coin()
{
}

void F_Coin::Load()
{	
	m_hCurrentSprite= ResourcesManager::GetInstance()->GetSprite(SpriteID::Coin);
	Object::Load();
	type = TYPEOBJECT::coin;
}

void F_Coin::Update(float gameTime)
{
	if (connect == true && life == true)
		Show();
}

void F_Coin::Die()
{
	life = false;
	_LocalHero->Collision_Coin();
}

void F_Coin::Show()
{	
	n++;
	m_hSpeed.y += 1.5;
	m_hPosition.y += m_hSpeed.y;
	if (n >= 4)
	{
		life = false;
		_LocalHero->Collision_Coin();
		m_hCurrentSprite = NULL;
	}
}
