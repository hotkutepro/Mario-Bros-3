#include "E_Plant_Red.h"
#include "ResourcesManager.h"


E_Plant_Red::E_Plant_Red()
{
}


E_Plant_Red::~E_Plant_Red()
{
}

void E_Plant_Red::Load()
{	
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Wood_1);
	Object::Load();
	type = TYPEOBJECT::tree_red;
}

void E_Plant_Red::Update(float gameTime)
{
	Object::Update(gameTime);
}
