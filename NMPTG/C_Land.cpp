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
}

void C_Land::Update(float gameTime)
{

}
