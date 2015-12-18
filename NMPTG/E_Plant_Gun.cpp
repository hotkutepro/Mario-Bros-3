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
	Tree_left = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_left);
	Tree_right = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_right);
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_left);
	Object::Load();
	type = TYPEOBJECT::tree_shoot;
}

void E_Plant_Gun::Update(float gameTime)
{
	Object::Update(gameTime);
}
