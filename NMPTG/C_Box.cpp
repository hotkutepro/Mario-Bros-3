#include "C_Box.h"


C_Box::C_Box()
{
	type = TYPEOBJECT::box;
}


C_Box::~C_Box()
{
}

void C_Box::Load()
{
	Object::Load();	
	m_hCurrentSprite = NULL;
}

void C_Box::Update(float gameTime)
{

}

void C_Box::Render()
{

}
