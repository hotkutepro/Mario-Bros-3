#include "E_Tarnooki_Fly.h"
#include "ResourcesManager.h"


E_Tarnooki_Fly::E_Tarnooki_Fly()
{
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
}

void E_Tarnooki_Fly::Update(float gameTime)
{

}
