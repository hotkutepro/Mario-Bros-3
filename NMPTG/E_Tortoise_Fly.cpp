#include "E_Tortoise_Fly.h"
#include"ResourcesManager.h"

E_Tortoise_Fly::E_Tortoise_Fly()
{
}


E_Tortoise_Fly::~E_Tortoise_Fly()
{
}

void E_Tortoise_Fly::Load()
{
	E_FlyTortoiseGreenLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_FlyTortoiseGreenLeft);
	E_FlyTortoiseGreenRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_FlyTortoiseGreenRight);
	E_TortoiseGreenLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseGreenLeft);
	E_TortoiseGreenRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseGreenRight);
	E_TortoiseshellGreenLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenLeft);
	E_TortoiseshellGreenRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenRight);
	setCurrentSprite(E_FlyTortoiseGreenRight);
	Object::Load();
}

void E_Tortoise_Fly::Update(float gameTime)
{
	Object::Update(gameTime);
}
