#include "C_Drain.h"
#include"Collision.h"
#include "FrkShareControl.h"

C_Drain::C_Drain()
{
}


C_Drain::~C_Drain()
{
}

void C_Drain::Update(float gameTime)
{
	if (id == 1388 && Collision::checkAABB(GetBox(), _LocalHero->GetBox()) && _LocalHero->isDown)
	{
 		_LocalHero->m_hPosition.y -= 430;
	}
	if (id == 6208 && Collision::checkAABB(GetBox(), _LocalHero->GetBox()) && _LocalHero->isUp)
	{
		_LocalHero->m_hPosition.y += 176;
		_LocalHero->m_hPosition.x -= 176;
	}
}


void C_Drain::Load()
{	
	m_hCurrentSprite = NULL;
	type = TYPEOBJECT::drain;	
	Object::Load();
	//Object::Load();
}
