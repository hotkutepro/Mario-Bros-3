#include "E_Plant_Red_Gun.h"
#include"ResourcesManager.h"


E_Plant_Red_Gun::E_Plant_Red_Gun()
{
}


E_Plant_Red_Gun::~E_Plant_Red_Gun()
{
}

void E_Plant_Red_Gun::Load()
{
	Tree_red_left_down = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_red_left_down);
	Tree_red_left_up = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_red_left_up);
	Tree_red_right_down = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_red_right_down);
	Tree_red_right_up = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_red_right_up);
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_red_left_down);
	Object::Load();
	type = tree_red_shoot;
}

void E_Plant_Red_Gun::Update(float gameTime)
{
	Object::Update(gameTime);
}
