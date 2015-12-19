#include "F_Leaf.h"
#include"ResourcesManager.h"
#include "FrkCamera.h"
#include"SuperHero.h"
#include "FrkShareControl.h"
F_Leaf::F_Leaf()
{
}


F_Leaf::~F_Leaf()
{
}

void F_Leaf::Load()
{	
	Leaf = ResourcesManager::GetInstance()->GetSprite(SpriteID::Leaf);
	F_MushroomPower = ResourcesManager::GetInstance()->GetSprite(SpriteID::F_MushroomPower);
	setCurrentSprite(Leaf);
	Object::Load();
	type = TYPEOBJECT::leaf;
}

void F_Leaf::Update(float gameTime)
{
	Object::Update(gameTime);
}

void F_Leaf::Die()
{
	m_hCurrentSprite = NULL;
}

void F_Leaf::WatchUp()
{
	if (_LocalHero->status != MARIO)
		setCurrentSprite(Leaf);
	else
		setCurrentSprite(F_MushroomPower);
}

