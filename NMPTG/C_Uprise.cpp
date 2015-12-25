#include "C_Uprise.h"


C_Uprise::C_Uprise()
{
}


C_Uprise::~C_Uprise()
{
}

void C_Uprise::Load()
{
	m_hCurrentSprite = NULL;
	type = TYPEOBJECT::uprise;
	Object::Load();
}

void C_Uprise::Update(float gameTime)
{

}
