#include "F_Star.h"
#include"ResourcesManager.h"


F_Star::F_Star()
{
}


F_Star::~F_Star()
{
}

void F_Star::Load()
{	
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Endgame);
	Object::Load();
	type = TYPEOBJECT::star;
}

void F_Star::Update(float gameTime)
{
	Object::Update(gameTime);
}

void F_Star::Die()
{
	life = false;
}
