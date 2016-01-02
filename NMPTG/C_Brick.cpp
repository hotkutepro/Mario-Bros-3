#include "C_Brick.h"
#include"FrkShareControl.h"
#include "ResourcesManager.h"

C_Brick::C_Brick()
{
	type = TYPEOBJECT::brick;
}


C_Brick::~C_Brick()
{
}

void C_Brick::Load()
{		
	brick = ResourcesManager::GetInstance()->GetSprite(SpriteID::Brick);
	Coin = ResourcesManager::GetInstance()->GetSprite(SpriteID::Coin);
	setCurrentSprite(brick);	
	Object::Load();
	status = 0;	
	n = 0;
}

void C_Brick::Update(float gameTime)
{
	if (n != 0 && n < 100)
		n++;
	if (n == 100)
		Reset();
	Object::Update(gameTime);
	DelayNext(3);
}

void C_Brick::IsAttacked()
{
	life = false;
}

void C_Brick::Die()
{
	life = false;
}

void C_Brick::WatchUp()
{
	setCurrentSprite(Coin);
	status = 1;
	n++;
}

void C_Brick::Reset()
{
	setCurrentSprite(brick);
	n = 0;
	status = 0;
}
