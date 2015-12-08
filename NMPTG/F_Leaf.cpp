#include "F_Leaf.h"
#include"ResourcesManager.h"
#include "FrkCamera.h"

F_Leaf::F_Leaf()
{
}


F_Leaf::~F_Leaf()
{
}

void F_Leaf::Load()
{	
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Leaf);	
	Object::Load();
}

void F_Leaf::Update(float gameTime)
{
	Object::Update(gameTime);
}

