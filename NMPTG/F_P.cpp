#include "F_P.h"
#include "ResourcesManager.h"


F_P::F_P()
{
}


F_P::~F_P()
{
}

void F_P::Load()
{
	P = ResourcesManager::GetInstance()->GetSprite(SpriteID::P);
	KickP = ResourcesManager::GetInstance()->GetSprite(SpriteID::KickP);
}

void F_P::Update(float gameTime)
{

}
