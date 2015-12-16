#include "C_Box.h"


C_Box::C_Box()
{
}


C_Box::~C_Box()
{
}

void C_Box::Load()
{
	//Object::Load();
	type = TYPEOBJECT::box;
	m_hCurrentSprite = NULL;
}

void C_Box::Update(float gameTime)
{

}
