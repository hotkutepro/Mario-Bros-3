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
	bool isRound = false;/////////////////////xem mario tiep dat chua

	_LocalKeyboard->GetDeviceState();
	//b1->v.x = b1->v.y = 0;
	float time = 0;
	float time2 = 0;

	mapQNode::iterator it_Node;
	it_Node = qnode->m_QNode.find(0);
	qnode->s_IdObjectInViewPort.clear();
	qnode->getIdObjectInViewPort(R_Viewport, it_Node->second);
	sId::iterator id_Objects;
	sId::iterator id_ONext;
	mapObject::iterator it_Object;
	mapObject::iterator it_ONext;

	//float time = 0;
	float nx = 0; float ny = 0;//swept aabb
	float nx2, ny2;
	float mx, my;//swept aabb
	//Box*b1; Box*b2;
	for (id_Objects = qnode->s_IdObjectInViewPort.begin(); id_Objects != qnode->s_IdObjectInViewPort.end(); id_Objects++)
	{
		it_Object = qnode->m_Objects.find(*id_Objects);		//Object đang xét
		Box* b = new Box();//box của object đang xét
		b->v.x = b->v.y = 0;
		b->position.left = it_Object->second->m_hPosition.x;
		b->position.top = it_Object->second->m_hPosition.y;
		b->position.right = b->position.left + it_Object->second->m_hSize.x;
		b->position.bottom = b->position.top + it_Object->second->m_hSize.y;
		it_Object = qnode->m_Objects.find(*id_Objects);		//Object đang xét		
		Box* box_hero = Collision::GetBoardPhaseBox(s_hero->m_hBox);
		time = Collision::SweptAABB(s_hero->m_hBox, b, nx, ny);
		//time2 = Collision::SweptAABB(s_hero->m_hBox_Colis, b, nx2, ny2);				
			if (time < 1)
			{
				if (ny==1)
				if (it_Object->second->type == land || it_Object->second->type == box || it_Object->second->type == Brick)
				{					
					s_hero->m_hBox->position.top -= s_hero->m_hBox->v.y*time;
					s_hero->m_hBox->position.bottom -= s_hero->m_hBox->v.y*time;
					s_hero->m_hBox->v.y = 0;
					//isRound = true;

					s_hero->m_hObjectGround = it_Object->second;

					s_hero->m_hBox_Colis->position.left = s_hero->m_hBox->position.left;
					s_hero->m_hBox_Colis->position.right = s_hero->m_hBox->position.right;
					s_hero->m_hBox_Colis->position.top = s_hero->m_hBox->position.top;
					s_hero->m_hBox_Colis->position.bottom = s_hero->m_hBox->position.bottom+2;
					s_hero->m_hState = ON_GROUND;
				}				
			}
			if (s_hero->m_hObjectGround!=NULL)
			if (!Collision::AABBCheck(s_hero->m_hBox_Colis, s_hero->m_hObjectGround->m_hBox))
			{
				s_hero->Fall(1);
			}
			/*else if (time2 < 1){
				if (it_Object->second->type == land || it_Object->second->type == box || it_Object->second->type == Brick)
				{
					//s_hero->Fall(time);
					//s_hero->m_hBox->v.y = 0;
					//isRound = true;
					s_hero->m_hObjectGround = it_Object->second;
					s_hero->m_hState = ON_GROUND;
				}
			}*/					
	}
	if (s_hero->m_hState == ON_SPACE)
		s_hero->Fall(1);
	_LocalKeyboard->ClearBuffer();
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

