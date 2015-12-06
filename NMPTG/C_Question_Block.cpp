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
	setCurrentSprite(CoinBox);
}

void C_Question_Block::Update(float gameTime)
{

}
