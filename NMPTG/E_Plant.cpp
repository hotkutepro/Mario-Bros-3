#include "E_Plant.h"
#include "ResourcesManager.h"

E_Plant::E_Plant()
{
}


E_Plant::~E_Plant()
{
}

void E_Plant::Load()
{	
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree);
	Object::Load();
	type = TYPEOBJECT::tree;
}

void E_Plant::Update(float gameTime)
{
	Object::Update(gameTime);
}
