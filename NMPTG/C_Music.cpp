#include "C_Music.h"
#include "ResourcesManager.h"

C_Music::C_Music()
{
}


C_Music::~C_Music()
{
}

void C_Music::Load()
{
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Cloud);
	Object::Load();
	type = TYPEOBJECT::music;
}

void C_Music::Update(float gameTime)
{

}

void C_Music::IsAttacked()
{

}

void C_Music::Die()
{

}

void C_Music::WatchUp()
{

}

void C_Music::Reset()
{

}
