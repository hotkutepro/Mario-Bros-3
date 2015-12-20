#include "E_Tortoise.h"
#include"ResourcesManager.h"


E_Tortoise::E_Tortoise()
{
}


E_Tortoise::~E_Tortoise()
{
}

void E_Tortoise::Load()
{	
	E_TortoiseGreenLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseGreenLeft);
	E_TortoiseGreenRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseGreenRight);
	E_TortoiseshellGreenLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenLeft);
	E_TortoiseshellGreenRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenRight);
	setCurrentSprite(E_TortoiseGreenLeft);	
	Object::Load();
	type = TYPEOBJECT::tortoise;
	m_hDirect = DIRECT::right;
	m_hSpeed.x = 0.02; m_hSpeed.y = -0.02;
}

void E_Tortoise::Update(float gameTime)
{	
	Object::Update(gameTime);
}

void E_Tortoise::Tortoise_Shell()
{
	setCurrentSprite(E_TortoiseshellGreenLeft);
}

void E_Tortoise::Die()
{
	if (v == 2)
	{
		setCurrentSprite(E_TortoiseshellGreenLeft);
		v--;
		//m_hSpeed.x = m_hSpeed.y = 0;
		life = 0;
	}

}
