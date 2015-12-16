#include "State_1.h"
#include "State.h"
#include "StateManager.h"
#include "ResourcesManager.h"
#include "FrkShareControl.h"
#include"Hero.h"

State_1::State_1(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM) :State(hIns,width,height,wName,SM)
{
	state_2 = new State_2(hIns, width, height, wName, SM);
}




State_1::~State_1()
{
	
}

void State_1::Load()
{
//	swept = new SweptAABB();
	qnode = new QNode();
	qnode->LoadQNode("QNode.txt");
	qnode->LoadObjects("Object.txt");
	qnode->Connect();
	qnode->InsertObject("OiNode.txt");
	qnode->getIdObjectInViewPort(R_Viewport, qnode);
	mapObject::iterator it;
	for (it = qnode->m_Objects.begin(); it != qnode->m_Objects.end(); it++)
	{
		it->second->Load();		
	}

	camera = new FrkCamera(2848, 720);
	map1 = new Map();
	map1->Init("hihi.txt", ResourcesManager::GetInstance()->GetTexture(TextureID::TileMap1));
	hero = new Hero(D3DXVECTOR2(200,_hero_GROUND_Y),D3DXVECTOR2(0,0));
	hero->Load();
	camera->Update(hero->GetPosition());

}

void State_1::Update(float gameTime)
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
	float nx = 0; float ny = 0;//swept aabb
	float mx, my;//swept aabb
	Box*b1; Box*b2;
	for (id_Objects = qnode->s_IdObjectInViewPort.begin(); id_Objects != qnode->s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = qnode->m_Objects.find(*id_Objects);		//Object đang xét		
		if (it_Object->second->type == TYPEOBJECT::land){
			/*if (swept->AABB(hero->box, it_Object->second->box, mx, my))
			{
				if (my < 0)//
				{

				}
				if (my > 0)//hero va cham mat dat
				{
					//hero->m_hSpeed.y = 36;
				}
				if (mx < 0)//hero cham ben ben trai cuc dat
				{
					
				}
				if (mx > 0)//hero cham ben phai cuc dat
				{

				}
			}*/
		}
	}
	_LocalKeyboard->GetDeviceState();	
	_LocalKeyboard->ClearBuffer();
}

void State_1::Render()
{
	_LocalGraphic->Begin(camera->GetTransformMatrix());
	
	//_LocalGraphic->DrawTexture(wall, D3DXVECTOR2(720,450), D3DXVECTOR2(720, 450), D3DCOLOR_XRGB(255, 255, 255), 0.2);
	map1->Render();
	hero->Render();
	
	//mushroom->Render();
	_LocalGraphic->End();
}

D3DXVECTOR2 State_1::getSpeed()
{
	return hero->getSpeed();
}
