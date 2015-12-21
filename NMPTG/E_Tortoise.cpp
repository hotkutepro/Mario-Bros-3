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
	E_TortoiseshellGreenLeftReverse = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenLeftReverse);
	E_TortoiseshellGreenRightReverse = ResourcesManager::GetInstance()->GetSprite(SpriteID::E_TortoiseshellGreenRightReverse);
	setCurrentSprite(E_TortoiseGreenLeft);	
	Object::Load();
	type = TYPEOBJECT::tortoise;
	m_hDirect = DIRECT::left;
	m_hSpeed.x = 1; m_hSpeed.y = -0.5;
}

void E_Tortoise::Update(float gameTime)
{	
	Object::Update(gameTime);
	Move();
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
		life = 0;
	}

}

void E_Tortoise::Collision_Up()
{
	status++;
}

void E_Tortoise::Collision_Down()
{

}

void E_Tortoise::Collision_Left()
{

}

void E_Tortoise::Collision_Right()
{

}

void E_Tortoise::SetSprite()
{
	
}
