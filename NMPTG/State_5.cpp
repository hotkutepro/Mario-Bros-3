#include "State_5.h"
#include "ResourcesManager.h"
#include"FrkShareControl.h"



State_5::State_5(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM) :State(hIns, width, height, wName, SM)
{

}


State_5::~State_5()
{
}

void State_5::Load()
{	
	collision = new Collision();
	qnode = new QNode();
	qnode->LoadQNode("QNode2.txt");
	qnode->LoadObjects("Object2.txt");
	qnode->Connect();
	qnode->InsertObject("OiNode2.txt");
	qnode->getIdObjectInViewPort(R_Viewport, qnode);

	camera = new FrkCamera(2848, 720);
	map1 = new Map();
	map1->Init("hihi2.txt", ResourcesManager::GetInstance()->GetTexture(TextureID::TileMap2));
	hero = new SuperHero();
	hero->Load();
	hero->status = MARIO;
	_LocalHero = hero;
	camera->Update(hero->GetPosition());
	mapObject::iterator it;
	for (it = qnode->m_Objects.begin(); it != qnode->m_Objects.end(); it++)
	{
		//if (it->second == NULL)
		//continue;
		it->second->Load();
		if (it->second->type == TYPEOBJECT::question_block)
		{
			mapObject::iterator it_up;
			it_up = qnode->m_Objects.find(it->first - 178);
			if (it_up != qnode->m_Objects.end())
			{
				//qnode->m_Objects.find(it->first - 178)->second->life = false;
				//qnode->m_Objects.find(it->first - 178)->second->connect = true;
				it_up->second->life = false;
				it_up->second->connect = true;
			}
		}
	}
	for (it = qnode->m_Objects_Dynamic.begin(); it != qnode->m_Objects_Dynamic.end(); it++)
	{
		it->second->Load();
	}
}

void State_5::Render()
{
	_LocalGraphic->Begin(camera->GetTransformMatrix());

	//_LocalGraphic->DrawTexture(wall, D3DXVECTOR2(720,450), D3DXVECTOR2(720, 450), D3DCOLOR_XRGB(255, 255, 255), 0.2);
	map1->Render();

	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = qnode->s_IdObjectInViewPort.begin(); id_Objects != qnode->s_IdObjectInViewPort.end(); id_Objects++)
	{

		it_Object = qnode->m_Objects.find(*id_Objects);
		
		//it_Object->second->RenderBoxDebug();
		if (it_Object->second->type == uprise)
			it_Object->second->RenderBoxShadow();
		if (it_Object->second->getCurrentSprite() != NULL)
			it_Object->second->Render();
	}
	//hero->RenderBoundBox();
	hero->RenderDebug();
	//hero->RenderV();
	//hero->ReanderViewPort();
	hero->Render();
	//hero->ReanderGroundBox();
	_LocalGraphic->End();

}

void State_5::Update(float gameTime)
{
	map1->Update();
	hero->Update(gameTime);
	//hero->GetStaticObject();
	camera->Update(hero->GetPosition());
	mapQNode::iterator it_Node;
	it_Node = qnode->m_QNode.find(0);
	qnode->s_IdObjectInViewPort.clear();
	qnode->getIdObjectInViewPort(R_Viewport, it_Node->second);
	sId::iterator id_Objects;
	sId::iterator id_ONext;
	mapObject::iterator it_Object;
	mapObject::iterator it_ONext;

	for (id_Objects = qnode->s_IdObjectInViewPort.begin(); id_Objects != qnode->s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = qnode->m_Objects.find(*id_Objects);
		it_Object->second->Update(gameTime);
	}

}