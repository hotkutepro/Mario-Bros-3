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
}

void E_Tarnooki::Update(float gameTime)
{

}
