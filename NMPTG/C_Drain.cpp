#include "C_Drain.h"


C_Drain::C_Drain()
{
}


C_Drain::~C_Drain()
{
}

void C_Drain::Update(float gameTime)
{

}


void C_Drain::Load()
{	
	m_hCurrentSprite = NULL;
	type = typeObject::drain;
	//Object::Load();
}
