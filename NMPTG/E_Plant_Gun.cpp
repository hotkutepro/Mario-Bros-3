#include "E_Plant_Gun.h"
#include"ResourcesManager.h"


E_Plant_Gun::E_Plant_Gun()
{
}


E_Plant_Gun::~E_Plant_Gun()
{
}

void E_Plant_Gun::Load()
{	
	Tree_left = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_left);
	Tree_right = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_right);
	ZPipe_md = ResourcesManager::GetInstance()->GetSprite(SpriteID::ZPipe_md);
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_left);
	Object::Load();
	pos.x = m_hPosition.x;
	pos.y = m_hPosition.y - 32;
	m_hPosition.x += 8;
	type = TYPEOBJECT::tree_shoot;
}

void E_Plant_Gun::Update(float gameTime)
{
	Object::Update(gameTime);
	ZPipe_md->Render(pos);
}

void E_Plant_Gun::Render()
{
	Object::Render();
	ZPipe_md->Render(pos);
}

void E_Plant_Gun::IsAttacked()
{

}
