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
	if (connect == true && life == true)
		Show();
}

void F_Coin::Die()
{
	m_hCurrentSprite = NULL;
}

void F_Coin::Show()
{	
	n++;
	m_hSpeed.y = 0.05;
	if (n >= 15)
	{
		life = false;
		m_hCurrentSprite = NULL;
	}
}
