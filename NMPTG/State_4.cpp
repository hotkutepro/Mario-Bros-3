#include "State_4.h"
#include "ResourcesManager.h"
#include"FrkShareControl.h"



State_4::State_4(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM) :State(hIns, width, height, wName, SM)
{

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
	hero->RenderV();
	hero->Render();
	_LocalGraphic->End();

}

void State_4::Update(float gameTime)
{
	_LocalTimeDelay++;
	if (_LocalTimeDelay>4)
		_LocalTimeDelay = 0;
	
	hero->Update(gameTime);
	hero->GetStaticObject();
	camera->Update(hero->GetPosition());
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
		it_Object = qnode->m_Objects.find(*id_Objects); 
			it_Object->second->Update(gameTime); 
		if (it_Object->second->m_hCurrentSprite!=NULL)
			it_Object->second->DelayNext(3);
		if (it_Object->second->type == tarnooki || it_Object->second->type == tarnooki_fly || it_Object->second->type == tortoise || it_Object->second->type == tortoise_fly || it_Object->second->type == tortoise_red){
			it_Object->second->MoveObject();
			//it_Object->second->FallDown(1);
		}
	}	
	
	//hero->FallDown(1);//sai j roi
	//float time = 1.0f;	
	//if (hero->m_hState != ON_GROUND)
	//{
	//	hero->Fall(time);
	//}
	//else if (hero->m_hObjectGround != NULL){
	//	if (!Collision::checkAABB(hero->GetBox_CGround(), hero->m_hObjectGround->m_hBox))
	//		hero->m_hState = ON_SPACE;
	//	else
	//		hero->m_hState = ON_GROUND;
	//}

}
