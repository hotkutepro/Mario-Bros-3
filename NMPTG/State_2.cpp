#include "State_1.h"
#include "State.h"
#include "StateManager.h"
#include "ResourcesManager.h"
#include "FrkShareControl.h"
#include "FrkShareControl.h"

State_2::State_2(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM) :State(hIns, width, height, wName, SM)
{	
}




State_2::~State_2()
{

}

void State_2::Load()
{
	qnode = new QNode();
	qnode->LoadQNode("QNode.txt");
	qnode->LoadObjects("Object.txt");
	qnode->Connect();
	qnode->InsertObject("OiNode.txt");

	leaf = new F_Leaf();
	leaf->Load();
	camera = new FrkCamera(2848, 720);
	map1 = new Map();
	map1->Init("hihi.txt", ResourcesManager::GetInstance()->GetTexture(TextureID::TileMap1));
	hero = new Hero(D3DXVECTOR2(200, 200), D3DXVECTOR2(0, 0));
	hero->Load();
	camera->Update(hero->GetPosition());

	mapObject::iterator it;
	for (it = qnode->m_Objects.begin(); it != qnode->m_Objects.end(); it++)
	{		
		it->second->Load();
	}
}

void State_2::Update(float gameTime)
{
	camera->Update(hero->GetPosition());
	hero->Update(gameTime);
	mapObject::iterator it;
	for (it = qnode->m_Objects.begin(); it != qnode->m_Objects.end(); it++)
	{		
		if (it->second->getCurrentSprite()!=NULL)
			it->second->getCurrentSprite()->Next();
	}
	_LocalKeyboard->GetDeviceState();
	_LocalKeyboard->ClearBuffer();
}

void State_2::Render()
{
	_LocalGraphic->Begin(camera->GetTransformMatrix());
	map1->Render();
	////render object ben duoi
	leaf->Render();
	hero->Render();
	mapObject::iterator it;
	for (it = qnode->m_Objects.begin(); it != qnode->m_Objects.end(); it++)
	{
		it->second->Render();
	}	
	_LocalGraphic->End();
}
