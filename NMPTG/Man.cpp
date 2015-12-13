#include "Man.h"
#include"ResourcesManager.h"

Man::Man()
{
}


Man::~Man()
{
}

void Man::Load()
{
	
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioLeft);
	m_hPosition.x = m_hPosition.y = 300;
	Object::Load();
}

void Man::Update(float gametime)
{
	Object::Update(gametime);	
}
