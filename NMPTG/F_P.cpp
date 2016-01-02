#include "F_P.h"
#include "ResourcesManager.h"


F_P::F_P()
{
	type = TYPEOBJECT::p;
}


F_P::~F_P()
{
}

void F_P::Load()
{	
	P = ResourcesManager::GetInstance()->GetSprite(SpriteID::P);
	KickP = ResourcesManager::GetInstance()->GetSprite(SpriteID::KickP);
	setCurrentSprite(P);
	Object::Load();	
}

void F_P::Update(float gameTime)
{
	Object::Update(gameTime);
}

void F_P::Die()
{
	life = false;
	vector<Object*> result;
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = QNode::s_IdObjectInViewPort.begin(); id_Objects != QNode::s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = QNode::m_Objects.find(*id_Objects);
		if (it_Object->second->type == brick || it_Object->second->type == coin)
		{
			it_Object->second->WatchUp();
		}
	}
}

void F_P::WatchUp()
{
	life = true;
}

