#include "C_Question_Block.h"
#include"ResourcesManager.h"


C_Question_Block::C_Question_Block()
{
}


C_Question_Block::~C_Question_Block()
{
}

void C_Question_Block::Load()
{	
	Coin = ResourcesManager::GetInstance()->GetSprite(SpriteID::Coin);
	CoinBox = ResourcesManager::GetInstance()->GetSprite(SpriteID::CoinBox);
	CoinBoxNull = ResourcesManager::GetInstance()->GetSprite(SpriteID::CoinBoxNull);
	brick = ResourcesManager::GetInstance()->GetSprite(SpriteID::Brick);
	setCurrentSprite(CoinBox);
	Object::Load();
	type = TYPEOBJECT::question_block;
}

void C_Question_Block::Update(float gameTime)
{
	
}

void C_Question_Block::Die()
{
	life_state = 1;
	setCurrentSprite(CoinBoxNull);
}
