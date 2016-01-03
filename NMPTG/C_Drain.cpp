#include "C_Drain.h"
#include"Collision.h"
#include "FrkShareControl.h"

C_Drain::C_Drain()
{
	type = TYPEOBJECT::drain;
}


C_Drain::~C_Drain()
{
}

void C_Drain::Update(float gameTime)
{
	if (id == 1388 && Collision::checkAABB(GetBox(), _LocalHero->GetBox()) && _LocalHero->isDown)
	{
 		_LocalHero->m_hPosition.y -= 430;		
			sound = new FrkSound("resources\\sounds\\effect\\smb3_pipe.wav");
		sound->Play();
	}
	if (id == 966 && Collision::checkAABB(GetBox(), _LocalHero->GetBox()) && _LocalHero->isDown)
	{
		sound = new FrkSound("resources\\sounds\\effect\\smb3_pipe.wav");
		sound->Play();
		_LocalHero->m_hPosition.y -= 430;
	}
	if (id == 6208 && Collision::checkAABB(GetBox(), _LocalHero->GetBox()) && _LocalHero->isUp)
	{
		sound = new FrkSound("resources\\sounds\\effect\\smb3_pipe.wav");
		sound->Play();
		_LocalHero->m_hPosition.y += 176;
		_LocalHero->m_hPosition.x -= 176;
	}
	if (id == 7190 && Collision::checkAABB(GetBox(), _LocalHero->GetBox()) && _LocalHero->isLeft)
	{
		sound = new FrkSound("resources\\sounds\\effect\\smb3_pipe.wav");
		sound->Play();
		_LocalHero->m_hPosition.y += 544;
		_LocalHero->m_hPosition.x -= 144;
	}
}


void C_Drain::Load()
{	
	m_hCurrentSprite = NULL;	
	Object::Load();
	//Object::Load();
}
