#include "E_Tarnooki.h"
#include"ResourcesManager.h"



E_Tarnooki::E_Tarnooki()
{
}


E_Tarnooki::~E_Tarnooki()
{
}

void E_Tarnooki::Load()
{	
	E_Mushroom = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_Mushroom);
	E_MushroomDeath = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_MushroomDeath);
	setCurrentSprite(E_Mushroom);
	Object::Load();
	m_hState = ON_SPACE;
	m_hSpeed.x = 1;
	m_hSpeed.y = -2;
	type = TYPEOBJECT::tarnooki;
}

void E_Tarnooki::Update(float gameTime)
{
	if (!life)
		return;
	Object::Update(gameTime);
	Move();
	//m_hPosition.y -= 0.2*gameTime;
}

void E_Tarnooki::Die()
{
	Object::Die();
	setCurrentSprite(E_MushroomDeath);
}
