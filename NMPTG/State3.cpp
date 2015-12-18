#include "State3.h"
#include "State.h"
#include "StateManager.h"
#include "ResourcesManager.h"
#include "FrkShareControl.h"

State_3::State_3(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM) :State(hIns, width, height, wName, SM)
{
	state_2 = new State_2(hIns, width, height, wName, SM);
}




State_3::~State_3()
{

}

void State_3::Load()
{
	qnode = new QNode();
	qnode->LoadQNode("QNode.txt");
	qnode->LoadObjects("Object.txt");
	qnode->Connect();
	qnode->InsertObject("OiNode.txt");
	qnode->getIdObjectInViewPort(R_Viewport, qnode);
	camera = new FrkCamera(2848, 720);
	map1 = new Map();
	map1->Init("hihi.txt", ResourcesManager::GetInstance()->GetTexture(TextureID::TileMap1));
	s_hero = new SuperHero();
	s_hero->Load();		
	camera->Update(s_hero->GetPosition());
	speed = -2;
	mapObject::iterator it;
	for (it = qnode->m_Objects.begin(); it != qnode->m_Objects.end(); it++)
	{
		it->second->Load();
	}
}
void State_3::Update(float gameTime)
{
	camera->Update(s_hero->GetPosition());
	s_hero->Update(gameTime);		
	float time = 0;	
	mapQNode::iterator it_Node;
	it_Node = qnode->m_QNode.find(0);
	qnode->s_IdObjectInViewPort.clear();
	qnode->getIdObjectInViewPort(R_Viewport, it_Node->second);
	sId::iterator id_Objects;
	sId::iterator id_ONext;
	mapObject::iterator it_Object;
	mapObject::iterator it_ONext;
	float nx = 0; float ny = 0;//swept aabb
	float nx2, ny2;
	float mx, my;//swept aabb
	for (id_Objects = qnode->s_IdObjectInViewPort.begin(); id_Objects != qnode->s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = qnode->m_Objects.find(*id_Objects);		//Object đang xét		
		time = Collision::SweptAABB(s_hero->m_hBox, it_Object->second->m_hBox, nx, ny);
		if (time!=1)
		{
			if (nx == -1)
			{
				s_hero->m_hBox->position.left += s_hero->m_hBox->v.x*nx*time;
				s_hero->m_hBox->v.x = 0;
				s_hero->canmoveright = false;
			}
			if (nx == 1)
			{
				s_hero->m_hBox->position.left += s_hero->m_hBox->v.x*nx*time;
    				s_hero->m_hBox->v.x = 0;
				s_hero->canmoveleft = false;
			}
			if (ny == -1)
			{
				s_hero->m_hBox->v.y = 0;
			}
			if (ny == 1)
			{
 				s_hero->m_hBox->position.top += s_hero->m_hBox->v.y*time;
				s_hero->m_hBox->position.bottom += s_hero->m_hBox->v.y*time;
				s_hero->m_hBox->v.y = 0;
				s_hero->canfall = false;
				s_hero->m_hState = ON_GROUND;
			}
		}
				
	}	

}

void State_3::Render()
{
	_LocalGraphic->Begin(camera->GetTransformMatrix());

	//_LocalGraphic->DrawTexture(wall, D3DXVECTOR2(720,450), D3DXVECTOR2(720, 450), D3DCOLOR_XRGB(255, 255, 255), 0.2);
	map1->Render();	
	s_hero->Render();
	sId::iterator id_Objects;
	mapObject::iterator it_Object;
	for (id_Objects = qnode->s_IdObjectInViewPort.begin(); id_Objects != qnode->s_IdObjectInViewPort.end(); id_Objects++)
	{

		it_Object = qnode->m_Objects.find(*id_Objects);
		if (it_Object->second->getCurrentSprite() != NULL)
			it_Object->second->getCurrentSprite()->Render(it_Object->second->GetPosition());
	}
	_LocalGraphic->End();
}

