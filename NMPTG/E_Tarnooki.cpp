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
	status = 0;
	t = 0;
	m_hDirect = DIRECT::left;
	type = TYPEOBJECT::tarnooki;
}

void E_Tarnooki::Update(float gameTime)
{
	
	if (t == 10)
		life = false;
	if (t != 0){
		t++;
		return;
	}
	Object::Update(gameTime);
	Move();
	//m_hPosition.y -= 0.2*gameTime;
}

void E_Tarnooki::Die()
{
	//Object::Die();
	//setCurrentSprite(E_MushroomDeath);
}

void E_Tarnooki::Collision_Up()
{
	if (t != 0)
		return;
	t++;
	_LocalHero->m_hSpeed.y = 3;
	status++;
	SetSprite();	
}

void E_Tarnooki::Collision_Down()
{

}

void E_Tarnooki::Collision_Left()
{

}

void E_Tarnooki::Collision_Right()
{

}

void E_Tarnooki::SetSprite()
{
	if (status == 0)
		setCurrentSprite(E_Mushroom);
	else
		setCurrentSprite(E_MushroomDeath);
}
