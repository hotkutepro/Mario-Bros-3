#include "E_Tarnooki_Fly.h"
#include "ResourcesManager.h"


E_Tarnooki_Fly::E_Tarnooki_Fly()
{
	type = TYPEOBJECT::tarnooki_fly;
}


E_Tarnooki_Fly::~E_Tarnooki_Fly()
{
}

void E_Tarnooki_Fly::Load()
{	
	E_FlyMushroom = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_FlyMushroom);
	E_MushroomRed = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_MushroomRed);
	E_MushroomRedDeath = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_MushroomRedDeath);
	setCurrentSprite(E_FlyMushroom);
	Object::Load();	
	m_hDirect = DIRECT::left;
	m_hState = ON_SPACE;
	m_hSpeed.x = -1; m_hSpeed.y = -2;
	status = 0;
	t = 0;
}

void E_Tarnooki_Fly::Update(float gameTime)
{
	if (t == 10)
		life = false;
	if (status==2)
	{
		t++;
		return;
	}
	Object::Update(gameTime);
	MoveObject();
	DelayNext(3);
}

void E_Tarnooki_Fly::Collision_Up()
{
	if (status == 2)
		return;
	status++;
	_LocalHero->m_hSpeed.y = 5;
	SetSprite();
}

void E_Tarnooki_Fly::Collision_Down()
{
	_LocalHero->IsAttacked();
}

void E_Tarnooki_Fly::Collision_Left()
{
	_LocalHero->IsAttacked();
}

void E_Tarnooki_Fly::Collision_Right()
{
	_LocalHero->IsAttacked();
}

void E_Tarnooki_Fly::SetSprite()
{
	if (status == 0)
	{
		setCurrentSprite(E_FlyMushroom);
	}
	if (status == 1)
	{
		setCurrentSprite(E_MushroomRed);
	}
	if (status == 2)
	{
		setCurrentSprite(E_MushroomRedDeath);
	}
}

void E_Tarnooki_Fly::IsAttacked()
{
	sound = new FrkSound("resources\\sounds\\effect\\smb3_kick.wav");
	sound->Play();
	life = false;
}
