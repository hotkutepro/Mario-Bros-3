#include "C_Land.h"


C_Land::C_Land()
{
}


C_Land::~C_Land()
{
}

void C_Land::Load()
{		
	m_hCurrentSprite = NULL;
	Object::Load();
	type = typeObject::land;
	box->vx = 0;
	box->vy = 0;	
}

void C_Land::Update(float gameTime)
{

}
