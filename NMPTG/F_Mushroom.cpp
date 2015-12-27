#include "F_Mushroom.h"
#include "ResourcesManager.h"



void F_Mushroom::Load()
{
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::One_up);
	Object::Load();
	type = TYPEOBJECT::oneup;
}

void F_Mushroom::Update(float gameTime)
{
	Object::Update(gameTime);
	if (life)
		MoveObject();
}

F_Mushroom::F_Mushroom()
{

}

F_Mushroom::~F_Mushroom()
{

}

void F_Mushroom::Die()
{	
	life = false;
	_LocalHero->Collision_1up();
}

void F_Mushroom::WatchUp()
{
	life = true;
	if (_LocalHero->m_hDirect == DIRECT::left)
		m_hSpeed.x = -2;
	else
	{
		m_hSpeed.x = 2;
	}
	m_hSpeed.y = -3;
	m_hState = ON_SPACE;
}
