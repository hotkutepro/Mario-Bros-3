#include "C_Block.h"
#include"ResourcesManager.h"


C_Block::C_Block()
{
	type = TYPEOBJECT::block;
}


C_Block::~C_Block()
{
}

void C_Block::Load()
{			
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_left);;
	Object::Load();
	n = m_hSize.x / 16;
	for (int i = 0; i < n;i++)
	{
		D3DXVECTOR2* tmp = new D3DXVECTOR2(m_hPosition.x + i * 16, m_hPosition.y);
		v_Pos.push_back(tmp);
	}
}

void C_Block::Update(float gameTime)
{
	Object::Update(gameTime);
}

void C_Block::Render()
{
	for (int i = 0; i < n;i++)
	{
		m_hCurrentSprite->Render(*v_Pos.at(i));
	}
}
