#include "F_Star.h"
#include"ResourcesManager.h"


F_Star::F_Star()
{
}


F_Star::~F_Star()
{
}

void F_Star::Load()
{
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Wood_1);
}

void F_Star::Update(float gameTime)
{

}
