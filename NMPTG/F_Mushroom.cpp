#include "F_Mushroom.h"
#include "ResourcesManager.h"



void F_Mushroom::Load()
{
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::F_MushroomPower);
}

void F_Mushroom::Update(float gameTime)
{

}

F_Mushroom::F_Mushroom()
{

}

F_Mushroom::~F_Mushroom()
{

}
