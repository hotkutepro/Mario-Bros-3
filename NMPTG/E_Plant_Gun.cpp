#include "E_Plant_Gun.h"
#include"ResourcesManager.h"


E_Plant_Gun::E_Plant_Gun()
{
}


E_Plant_Gun::~E_Plant_Gun()
{
}

void E_Plant_Gun::Load()
{	
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Wood_1);
	Object::Load();
	type = TYPEOBJECT::tree_shoot;
}

void E_Plant_Gun::Update(float gameTime)
{
	Object::Update(gameTime);
}
