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
}

void C_Brick::Update(float gameTime)
{
	Object::Update(gameTime);
}
