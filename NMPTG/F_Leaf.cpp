#include "F_Leaf.h"
#include"ResourcesManager.h"
#include "FrkCamera.h"
#include"SuperHero.h"
#include "FrkShareControl.h"
F_Leaf::F_Leaf()
{
	type = TYPEOBJECT::leaf;
}


F_Leaf::~F_Leaf()
{
}

void F_Leaf::Load()
{	
	Leaf = ResourcesManager::GetInstance()->GetSprite(SpriteID::Leaf);
	F_MushroomPower = ResourcesManager::GetInstance()->GetSprite(SpriteID::F_MushroomPower);
	setCurrentSprite(Leaf);
	Object::Load();	
	n = 0;
	v = 3;
}

void F_Leaf::Update(float gameTime)
{	
	Object::Update(gameTime);
	if (life&&m_hCurrentSprite==F_MushroomPower)
	{
		MoveObject();
	}
	else if (life)
	{
		n++;
		if (n==10)
		{
			n = 0;
			v = -v;
		}
		if (v > 0)
			m_hCurrentSprite->_Index = 1;
		else
			m_hCurrentSprite->_Index = 0;
		m_hPosition.x += v;
		m_hPosition.y +=m_hSpeed.y;
	}
}

void F_Leaf::Die()
{
	life = false;
	_LocalHero->Collision_Leaf();

}

void F_Leaf::WatchUp()
{
	sound = new FrkSound("resources\\sounds\\effect\\smb3_mushroom_appears.wav");
	sound->Play();
	life = true;
	if (_LocalHero->status != MARIO)
	{				
		setCurrentSprite(Leaf);
		m_hPosition.y += 30;
		m_hSpeed.y = -1;
	}
	else
	{
		setCurrentSprite(F_MushroomPower);
		if (_LocalHero->m_hDirect == DIRECT::left)
			m_hSpeed.x = -2;
		else
		{
			m_hSpeed.x = 2;
		}
		m_hSpeed.y = -3;
		m_hState = ON_SPACE;
	}
}

