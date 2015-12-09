#include "F_Coin.h"
#include"ResourcesManager.h"


F_Coin::F_Coin()
{
}


F_Coin::~F_Coin()
{
}

void F_Coin::Load()
{	
	m_hCurrentSprite= ResourcesManager::GetInstance()->GetSprite(SpriteID::Coin);
	Object::Load();
	type = typeObject::coin;
}

void F_Coin::Update(float gameTime)
{	
}
