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
	Swept = new SweptAABB();
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
	hero = new Hero(D3DXVECTOR2(200, 1000), D3DXVECTOR2(0, 0));
	hero->Load();
	camera->Update(hero->GetPosition());

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
	float nx=0;float ny=0;//swept aabb
	float mx, my;//swept aabb
	Box*b1; Box*b2;
	for (id_Objects = qnode->s_IdObjectInViewPort.begin(); id_Objects != qnode->s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = qnode->m_Objects.find(*id_Objects);		//Object đang xét		
		it_Object->second->Update(gameTime);
		if (it_Object->second->getCurrentSprite())
			it_Object->second->getCurrentSprite()->Next();
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
			for (id_ONext = qnode->s_IdObjectInViewPort.begin(); id_ONext != qnode->s_IdObjectInViewPort.end(); id_ONext++)
			{
				it_ONext = qnode->m_Objects.find(*id_ONext);
				if (it_ONext->second->type == typeObject::mushroom_red || it_ONext->second->type == typeObject::tarnooki ||
					it_ONext->second->type == typeObject::tarnooki_fly || it_ONext->second->type == typeObject::tortoise ||
					it_ONext->second->type == typeObject::tortoise_fly || it_ONext->second->type == typeObject::tortoise_red)
				{					
					if (Swept->AABBCheck(it_ONext->second->box, it_Object->second->box))
					{
						it_ONext->second->m_hPosition.y = it_ONext->second->box->y ;
					}
				}
			}
			break;
		case typeObject::question_block:
			if (Swept->AABB(hero->box, it_Object->second->box, mx, my) && it_Object->second->life)
			{
				if (my < 0){
					hero->m_hPosition.y = it_Object->second->box->y - it_Object->second->box->h;
					hero->m_hSpeed.y = 0;
					it_Object->second->life = false;
					mapObject::iterator it_up;
					it_up = qnode->m_Objects.find(it_Object->first - 178);
					if (it_up != qnode->m_Objects.end())
					{
						it_up->second->life = false;
						it_up->second->connect = true;
					}
				}
				if (my>0)
				{
					hero->m_hPosition.y = it_Object->second->box->y;
					hero->m_hSpeed.y = 0;
				}
			}
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
			if (Swept->AABB(hero->box,it_Object->second->box,mx,my)&&it_Object->second->life)
			{
				if (my != 0)
				{
					it_Object->second->Die();
					it_Object->second->m_hSpeed.x = it_Object->second->m_hSpeed.y = 0;
					hero->Jump(gameTime);
				}
				else{
					it_Object->second->m_hPosition.x -= 20;
				}
			}
			break;
		case typeObject::tarnooki_fly:
			break;
		case typeObject::tortoise:									
			if (Swept->AABB(hero->box, it_Object->second->box, mx, my) && it_Object->second->life)
			{
				if (my != 0)
				{
					it_Object->second->Die();
					it_Object->second->m_hSpeed.x = it_Object->second->m_hSpeed.y = 0;
					hero->Jump(gameTime);
				}
				else{
					it_Object->second->m_hPosition.x -= 20;
				}
			}
			break;
		case typeObject::tortoise_fly:
			break;
		case typeObject::tortoise_red:
			break;
		case typeObject::coin:
			if (Swept->AABBCheck(hero->box,it_Object->second->box) &&it_Object->second->life)
			{
				it_Object->second->Die();
			}
			break;
		case typeObject::leaf:
			if (Swept->AABBCheck(hero->box, it_Object->second->box) && it_Object->second->life)
			{
				it_Object->second->Die();
			}
			break;
		case typeObject::mushroom_red:
			if (Swept->AABBCheck(hero->box, it_Object->second->box) && it_Object->second->life)
			{
				it_Object->second->Die();
			}
			break;
		case typeObject::p:
			break;
		case typeObject::star:
			break;
		default:
			break;
		}		
		/*if (Swept->AABBCheck(hero->box, it_Object->second->box))
			it_Object->second->SetPosition(it_Object->second->GetPosition().x + 4, it_Object->second->GetPosition().y);
		dl += gameTime / 5;
		if (dl>gameTime)
		{
			dl = 0;
			if (it_Object->second->getCurrentSprite() != NULL)
			{
				it_Object->second->getCurrentSprite()->Next();
				it_Object->second->Update(gameTime);
			}
		}*/
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
