#include "C_Land.h"
#include"ResourcesManager.h"

C_Land::C_Land()
{
	type = TYPEOBJECT::land;
}


C_Land::~C_Land()
{
}

void C_Land::Load()
{				
	m_hCurrentSprite = NULL;	
	Object::Load();			
}

void C_Land::Update(float gameTime)
{

}

void C_Land::Render()
{

}
