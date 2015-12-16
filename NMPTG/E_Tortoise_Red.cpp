#include "E_Tortoise_Red.h"
#include"ResourcesManager.h"


E_Tortoise_Red::E_Tortoise_Red()
{
}


E_Tortoise_Red::~E_Tortoise_Red()
{
}

void E_Tortoise_Red::Load()
{
	E_TortoiseRedRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseRedRight);
	E_TurtoiseRedLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TurtoiseRedLeft);
	E_TortoiseshellRedLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellRedLeft);
	E_TortoiseshellRedRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellRedRight);
	setCurrentSprite(E_TortoiseRedRight);
	Object::Load();
	type = TYPEOBJECT::tortoise_red;
}

void E_Tortoise_Red::Update(float gameTime)
{
	Object::Update(gameTime);
}
