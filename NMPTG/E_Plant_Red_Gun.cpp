#include "E_Plant_Red_Gun.h"
#include"ResourcesManager.h"


E_Plant_Red_Gun::E_Plant_Red_Gun()
{
}


E_Plant_Red_Gun::~E_Plant_Red_Gun()
{
}

void E_Plant_Red_Gun::Load()
{
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Wood_1);
}

void E_Plant_Red_Gun::Update(float gameTime)
{

}
