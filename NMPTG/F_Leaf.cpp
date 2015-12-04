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
	Leaf = ResourcesManager::GetInstance()->GetSprite(SpriteID::Leaf);
	this->SetPosition(0, 464);
}

void F_Leaf::Render()
{
	Leaf->Render(GetPosition());
}

void F_Leaf::Update(float gameTime)
{

}

