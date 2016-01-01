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
	m_hPosition.x += m_hSpeed.x;
	m_hPosition.y += m_hSpeed.y;
	DelayNext(3);
}

void Bullet::Load()
{	
	m_hCurrentSprite =ResourcesManager::GetInstance()->GetSprite(SpriteID::Bull);
	Object::Load();
}
