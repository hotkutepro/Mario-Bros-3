#include "State_1.h"
#include "State.h"
#include "StateManager.h"
#include "ResourcesManager.h"
#include "FrkShareControl.h"
#include"Box.h"

State_2::State_2(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM) :State(hIns, width, height, wName, SM)
{
}




State_2::~State_2()
{

}

void State_2::Load()
{
	collis = new Collision();
	qnode = new QNode();
	qnode->LoadQNode("QNode.txt");
	qnode->LoadObjects("Object.txt");
	qnode->Connect();
	qnode->InsertObject("OiNode.txt");
	qnode->getIdObjectInViewPort(R_Viewport, qnode);

	leaf = new F_Leaf();
	leaf->Load();
	camera = new FrkCamera(2848, 720);
	map1 = new Map();
	map1->Init("hihi.txt", ResourcesManager::GetInstance()->GetTexture(TextureID::TileMap1));
	man = new Man();
	man->Load();
	camera->Update(man->GetPosition());

	mapObject::iterator it;
	for (it = qnode->m_Objects.begin(); it != qnode->m_Objects.end(); it++)
	{
		it->second->Load();
		if (it->second->type==typeObject::question_block)
		{
			mapObject::iterator it_up;
			it_up = qnode->m_Objects.find(it->first-178);
			if (it_up != qnode->m_Objects.end())
			{
				it_up->second->life = false;
				it_up->second->connect = true;
			}
		}
	}
}
void State_2::Update(float gameTime)
{
	_LocalKeyboard->GetDeviceState();
	camera->Update(man->GetPosition());
	man->Update(gameTime);

	mapQNode::iterator it_Node;
	it_Node = qnode->m_QNode.find(0);
	qnode->s_IdObjectInViewPort.clear();
	qnode->getIdObjectInViewPort(R_Viewport, it_Node->second);
	sId::iterator id_Objects;
	sId::iterator id_ONext;
	mapObject::iterator it_Object;
	mapObject::iterator it_ONext;
	float time = 0;
	float nx=0;float ny=0;//swept aabb
	float mx, my;//swept aabb
	Box*b1; Box*b2;
	for (id_Objects = qnode->s_IdObjectInViewPort.begin(); id_Objects != qnode->s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = qnode->m_Objects.find(*id_Objects);		//Object đang xét		
		//it_Object->second->Update(gameTime);
		if (it_Object->second->getCurrentSprite())
			it_Object->second->getCurrentSprite()->Next();
		switch (it_Object->second->type)
		{
		case typeObject::brick:
						
			if (_LocalKeyboard->IsKeyDown(DIK_LEFT))
			{
				man->box->v.x = -2;
				time = collis->SweptAABB(man->box, it_Object->second->box, nx, ny);
				man->box->position.left += man->box->v.x*time;
				man->box->position.right += man->box->v.x*time;
				man->m_hPosition.x = man->box->position.left;
				//man->m_hPosition.x = man->box->position.left;
				if (time < 1.0f)
					man->box->v.x = 0;
			}
			if (_LocalKeyboard->IsKeyDown(DIK_RIGHT))
			{
				man->box->v.x = 2;
				time = collis->SweptAABB(man->box, it_Object->second->box, nx, ny);
				man->box->position.left += man->box->v.x*time;
				man->box->position.right += man->box->v.x*time;
				man->m_hPosition.x = man->box->position.left;
				//man->m_hPosition.x = man->box->position.left;
				if (time < 1.0f)
					man->box->v.x = 0;
			}
			if (_LocalKeyboard->IsKeyDown(DIK_UP))
			{
				man->box->v.y = 2;
				time = collis->SweptAABB(man->box, it_Object->second->box, nx, ny);
			}
			if (_LocalKeyboard->IsKeyDown(DIK_DOWN))
			{
				man->box->v.y = -2;
				time = collis->SweptAABB(man->box, it_Object->second->box, nx, ny);
			}
			break;
		case typeObject::bullet:
			break;
		case typeObject::box:
			break;
		case typeObject::drain:
			break;
		case typeObject::land:
			
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
			/*if (swept->AABBCheck(man->box,it_Object->second->box) &&it_Object->second->life)
			{
				it_Object->second->Die();
			}*/
			break;
		case typeObject::leaf:
			/*if (swept->AABBCheck(man->box, it_Object->second->box) && it_Object->second->life)
			{
				it_Object->second->Die();
			}*/
			break;
		case typeObject::mushroom_red:
			/*if (swept->AABBCheck(man->box, it_Object->second->box) && it_Object->second->life)
			{
				it_Object->second->Die();
			}*/
			break;
		case typeObject::p:
			break;
		case typeObject::star:
			break;
		default:
			break;
		}				
	}	
	
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
	man->Render();
	_LocalGraphic->End();
}
