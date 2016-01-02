#include "State_4.h"
#include "ResourcesManager.h"
#include"FrkShareControl.h"
#include "State_5.h"



State_4::State_4(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM) :State(hIns, width, height, wName, SM)
{
	//state_4 = new State_5(hIns, width, height, wName, SM);
}

State_4::~State_4()
{
}

void State_4::Load()
{
	
	
	collision = new Collision();
	qnode = new QNode();
	qnode->LoadQNode("QNode.txt");
	qnode->LoadObjects("Object.txt");
	qnode->Connect();
	qnode->InsertObject("OiNode.txt");
	qnode->getIdObjectInViewPort(R_Viewport, qnode);

	camera = new FrkCamera(2848, 720);
	map1 = new Map();
	map1->Init("hihi.txt", ResourcesManager::GetInstance()->GetTexture(TextureID::TileMap1));
	hero = new SuperHero();
	hero->Load();
	hero->status = BROS;
	_LocalHero = hero;
	camera->Update(hero->GetPosition());
	mapObject::iterator it;
	for (it = qnode->m_Objects.begin(); it != qnode->m_Objects.end(); it++)
	{
		if (it->second == NULL)
			continue;
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

void State_4::Render()
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
		if (it_Object->second->getCurrentSprite() != NULL)
			 it_Object->second->Render();
	}
	//hero->RenderBoundBox();
	//hero->RenderDebug();
	//hero->RenderV();
	//hero->ReanderViewPort();
	hero->Render();
	//hero->RenderAffection();
	//hero->RenderBoxAttack();
	//hero->RenderBoxRight();
	//hero->ReanderGroundBox();
	_LocalGraphic->End();

}

void State_4::Update(float gameTime)
{
	//if (hero->m_hPosition.y < 0)
	//{
	//	ChangeState(state_4);
	//	
	//}
	map1->Update();
	
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
	
	for (id_Objects = qnode->s_IdObjectInViewPort.begin(); id_Objects != qnode->s_IdObjectInViewPort.end(); id_Objects++)//sửa lại, chỉ chọn đối tượng tĩnh
	{
		it_Object = qnode->m_Objects.find(*id_Objects);		
		it_Object->second->Update(gameTime);		

	}
	hero->Update(gameTime);
}