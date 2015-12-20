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
	type = TYPEOBJECT::tree;
	m_hPosition.x += 8;	
	m_hPosition.y += 16;
	m_hSpeed.y = -1;
	type = tree_red_shoot;
	n = 0;
}

void E_Plant::Update(float gameTime)
{
	if (!life)
		return;
	if (n <= 33)
		m_hPosition.y += m_hSpeed.y;
	if (n++ == 60)
	{
		n = 0;
		m_hSpeed.y = -m_hSpeed.y;
	}
	m_hCurrentSprite->Next();
	Object::Update(gameTime);
}

void E_Plant::Render()
{
	Object::Render();
	ZPipe_sm->Render(pos);
}
