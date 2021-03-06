#include "C_Question_Block.h"
#include"ResourcesManager.h"


C_Question_Block::C_Question_Block()
{
	type = TYPEOBJECT::question_block;
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
}

void C_Question_Block::Update(float gameTime)
{
	DelayNext(4);
}

void C_Question_Block::Die()
{
	if (life_state == 0)
	{
		mapObject::iterator it_up;
		it_up = QNode::m_Objects.find(id - 178);
		it_up->second->WatchUp();
	}
	life_state = 1;
	setCurrentSprite(CoinBoxNull);
}

void C_Question_Block::IsAttacked()
{
	if (life_state == 0)
	{
		mapObject::iterator it_up;
		it_up = QNode::m_Objects.find(id - 178);
		it_up->second->WatchUp();
	}
	life_state = 1;
	setCurrentSprite(CoinBoxNull);
}
