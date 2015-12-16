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
	m_hSpeed.x = 0.02; m_hSpeed.y = -0.002;
	E_FlyTortoiseGreenLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_FlyTortoiseGreenLeft);
	E_FlyTortoiseGreenRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_FlyTortoiseGreenRight);
	E_TortoiseGreenLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseGreenLeft);
	E_TortoiseGreenRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseGreenRight);
	E_TortoiseshellGreenLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenLeft);
	E_TortoiseshellGreenRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenRight);
	setCurrentSprite(E_FlyTortoiseGreenRight);
	Object::Load();
	type = TYPEOBJECT::tortoise_fly;
}

void E_Tortoise_Fly::Update(float gameTime)
{	
	Object::Update(gameTime);
	//m_hPosition.y -= 0.2*gameTime;
}
