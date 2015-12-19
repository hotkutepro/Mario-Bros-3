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
	ZPipe_md = ResourcesManager::GetInstance()->GetSprite(SpriteID::ZPipe_md);
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_red_left_down);
	Object::Load();
	pos.x = m_hPosition.x;
	pos.y = m_hPosition.y - 32;
	m_hPosition.x += 8;	
	type = tree_red_shoot;
}

void E_Plant_Red_Gun::Update(float gameTime)
{
	Object::Update(gameTime);
	int n = getDirectWithHero(_LocalHero);
	if (n == 1)
	{
		setCurrentSprite(Tree_red_left_down);
	}
	else if (n == 2)
	{
		setCurrentSprite(Tree_red_left_up);
	}
	else if (n == 3){
		setCurrentSprite(Tree_red_right_up);
	}
	else if (n == 4){
		setCurrentSprite(Tree_red_right_down);
	}
}

void E_Plant_Red_Gun::Render()
{
	Object::Render();
	ZPipe_md->Render(pos);
}
