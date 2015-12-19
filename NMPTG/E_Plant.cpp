#include "E_Plant.h"
#include "ResourcesManager.h"

E_Plant::E_Plant()
{
}


E_Plant::~E_Plant()
{
}

void E_Plant::Load()
{	
	Tree = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree);
	ZPipe_sm = ResourcesManager::GetInstance()->GetSprite(SpriteID::ZPipe_sm);
	m_hCurrentSprite = Tree;
	Object::Load();
	pos.x = m_hPosition.x;
	pos.y = m_hPosition.y - 16;
	m_hPosition.x += 8;
	type = TYPEOBJECT::tree;
}

void E_Plant::Update(float gameTime)
{
	Object::Update(gameTime);
}

void E_Plant::Render()
{
	Object::Render();
	ZPipe_sm->Render(pos);
}
