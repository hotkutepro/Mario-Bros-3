#include "State_1.h"
#include "State.h"
#include "StateManager.h"
#include "ResourcesManager.h"
#include "FrkShareControl.h"

State_2::State_2(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM) :State(hIns, width, height, wName, SM)
{	
}




State_2::~State_2()
{

}

void State_2::Load()
{
	Swept = new SweptAABB();
	qnode = new QNode();
	qnode->LoadQNode("QNode.txt");
	qnode->LoadObjects("Object.txt");
	qnode->Connect();
	qnode->InsertObject("OiNode.txt");
	qnode->getIdObjectInViewPort(R_Viewport,qnode);

	leaf = new F_Leaf();
	leaf->Load();
	camera = new FrkCamera(2848, 720);
	map1 = new Map();
	map1->Init("hihi.txt", ResourcesManager::GetInstance()->GetTexture(TextureID::TileMap1));
	hero = new Hero(D3DXVECTOR2(200, 1000), D3DXVECTOR2(0, 0));
	hero->Load();
	camera->Update(hero->GetPosition());

	mapObject::iterator it;
	for (it = qnode->m_Objects.begin(); it != qnode->m_Objects.end(); it++)
	{		
		it->second->Load();
	}
}
float dl = 0;
void State_2::Update(float gameTime)
{
	camera->Update(hero->GetPosition());
	hero->Update(gameTime);
	
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
		
		switch (it_Object->second->type)
		{
		case typeObject::brick:

			break;
		case typeObject::bullet:
			break;
		case typeObject::box:
			break;
		case typeObject::drain:
			break;
		case typeObject::land:
			for (id_ONext = id_Objects; id_ONext != qnode->s_IdObjectInViewPort.end(); id_ONext++)
			{
				it_ONext= qnode->m_Objects.find(*id_ONext);
			}
			break;
		case typeObject::question_block:
			break;
		case typeObject::tree:
			break;
		case typeObject::tree_shoot:
			break;
		case typeObject::tree_red:
			break;
		case typeObject::tree_red_shoot:
			break;
		case typeObject::tarnooki:
			break;
		case typeObject::tarnooki_fly:
			break;
		case typeObject::tortoise:
			break;
		case typeObject::tortoise_fly:
			break;
		case typeObject::tortoise_red:
			break;
		case typeObject::coin:
			break;
		case typeObject::leaf:
			break;
		case typeObject::mushroom_red:
			break;
		case typeObject::p:
			break;
		case typeObject::star:
			break;		
		default:
			break;
		}
		if (Swept->AABBCheck(hero->box, it_Object->second->box))
			it_Object->second->SetPosition(it_Object->second->GetPosition().x + 10, it_Object->second->GetPosition().y);
		dl += gameTime / 5;
		if (dl>gameTime)
		{
			dl = 0;
			if (it_Object->second->getCurrentSprite() != NULL)
			{
				it_Object->second->getCurrentSprite()->Next();
				it_Object->second->Update(gameTime);
			}
		}
	}
	/*for (it_Object = qnode->m_Objects.begin(); it_Object != qnode->m_Objects.end(); it_Object++)
	{		
		if (it_Object->second->getCurrentSprite() != NULL)
			it_Object->second->getCurrentSprite()->Next();
	}*/
	_LocalKeyboard->GetDeviceState();
	_LocalKeyboard->ClearBuffer();
}

void State_2::Render()
{
	_LocalGraphic->Begin(camera->GetTransformMatrix());
	map1->Render();
	////render object ben duoi
	leaf->Render();		
	/*mapObject::iterator it;
	for (it = qnode->m_Objects.begin(); it != qnode->m_Objects.end(); it++)
	{
		it->second->Render();
	}*/
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = qnode->s_IdObjectInViewPort.begin(); id_Objects != qnode->s_IdObjectInViewPort.end(); id_Objects++)
	{

		it_Object = qnode->m_Objects.find(*id_Objects);
		if (it_Object->second->getCurrentSprite() != NULL)
			it_Object->second->getCurrentSprite()->Render(it_Object->second->GetPosition());
	}
	hero->Render();
	_LocalGraphic->End();
}
