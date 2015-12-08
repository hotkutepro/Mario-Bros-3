#include "F_Mushroom.h"
#include "ResourcesManager.h"



void F_Mushroom::Load()
{	
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::F_MushroomPower);
	Object::Load();
}

void F_Mushroom::Update(float gameTime)
{
	Object::Update(gameTime);
}

F_Mushroom::F_Mushroom()
{

}

F_Mushroom::~F_Mushroom()
{

}
