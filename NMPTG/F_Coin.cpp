#include "F_Coin.h"
#include"ResourcesManager.h"
#include "FrkShareControl.h"

F_Coin::F_Coin()
{
	type = TYPEOBJECT::coin;
}


F_Coin::~F_Coin()
{
}

void F_Coin::Load()
{	
	brick = ResourcesManager::GetInstance()->GetSprite(SpriteID::Brick);
	Coin = ResourcesManager::GetInstance()->GetSprite(SpriteID::Coin);
	setCurrentSprite(Coin);	
	Object::Load();	
	status = 0;
}
void F_Coin::WatchUp()
{
	if (life==false)
	{
		life = true;
		return;
	}
	else
	{
		setCurrentSprite(brick);
		status = 1;
		n++;
	}
	
}
void F_Coin::Update(float gameTime)
{
	if (n >0)
		n++;
	if (n == 300)
		Reset();
	if (connect == true && life == true)
		Show();
	DelayNext(5);
}

void F_Coin::Die()
{
	sound = new FrkSound("resources\\sounds\\effect\\smb3_coin.wav");
	sound->Play();
	life = false;
	_LocalHero->Collision_Coin();
}

void F_Coin::Show()
{	
	n++;
	m_hSpeed.y += 1.5;
	m_hPosition.y += m_hSpeed.y;
	if (n >= 4)
	{
		life = false;
		_LocalHero->Collision_Coin();		
	}
}
void F_Coin::Reset()
{
	setCurrentSprite(Coin);
	n = 0;
	status = 0;
}

