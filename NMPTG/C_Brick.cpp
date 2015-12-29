#include "C_Brick.h"
#include"FrkShareControl.h"
#include "ResourcesManager.h"

C_Brick::C_Brick()
{
}

C_Brick::C_Brick(D3DXVECTOR2 pos, D3DXVECTOR2 speed) :Object(pos,speed)
{

}

C_Brick::C_Brick(TYPEOBJECT _t) : Object(_t)
{

}


C_Brick::~C_Brick()
{
}

void C_Brick::Load()
{		
	brick = ResourcesManager::GetInstance()->GetSprite(SpriteID::Brick);
	Coin = ResourcesManager::GetInstance()->GetSprite(SpriteID::Coin);
	setCurrentSprite(brick);
	type = TYPEOBJECT::brick;
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
