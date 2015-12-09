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
	CoinBoxNull = ResourcesManager::GetInstance()->GetSprite(SpriteID::CoinBoxNull);
	setCurrentSprite(brick);
	type = typeObject::brick;
	Object::Load();
}

void Brick::Update(float gameTime)
{

}
