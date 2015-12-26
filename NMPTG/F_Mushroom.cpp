#include "F_Mushroom.h"
#include "ResourcesManager.h"



void F_Mushroom::Load()
{	
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::One_up);
	Object::Load();
	type = TYPEOBJECT::oneup;
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

void F_Mushroom::Die()
{
	m_hCurrentSprite = NULL;
	life = false;
}
