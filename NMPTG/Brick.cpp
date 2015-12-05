#include "Brick.h"
#include"FrkShareControl.h"
#include "ResourcesManager.h"

Brick::Brick()
{
}

Brick::Brick(D3DXVECTOR2 pos, D3DXVECTOR2 speed) :Object(pos,speed)
{

}

Brick::Brick(typeObject _t) : Object(_t)
{

}


Brick::~Brick()
{
}

void Brick::Load()
{	
	brick = ResourcesManager::GetInstance()->GetSprite(SpriteID::Brick);
	setCurrentSprite(brick);
}

void Brick::Update(float gameTime)
{

}
