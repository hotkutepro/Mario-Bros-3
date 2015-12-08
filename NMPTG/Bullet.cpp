#include "Bullet.h"
#include"ResourcesManager.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::Update(float gameTime)
{
	Object::Update(gameTime);
}

void Bullet::Load()
{	
	m_hCurrentSprite =ResourcesManager::GetInstance()->GetSprite(SpriteID::Bull);
	Object::Load();
}
