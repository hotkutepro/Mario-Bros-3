#include "State_1.h"
#include "State.h"
#include "StateManager.h"
#include "ResourcesManager.h"
#include "FrkShareControl.h"

State_1::State_1(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM) :State(hIns,width,height,wName,SM)
{
	state_2 = new State_2(hIns, width, height, wName, SM);
}




State_1::~State_1()
{
	
}

void State_1::Load()
{
	mushroom = new E_Mushroom(200, 200);
	mushroom->Load();
	camera = new FrkCamera(2848, 16);
	map1 = new Map();
	map1->Init("hihi.txt", ResourcesManager::GetInstance()->GetTexture(TextureID::TileMap1));
	wall = ResourcesManager::GetInstance()->GetTexture(TextureID::Wall_1);
}

void State_1::Update(float gameTime)
{
	camera->Update(D3DXVECTOR2(0, 100));
	_LocalKeyboard->GetDeviceState();
	if (_LocalKeyboard->IsKeyDown(DIK_L))
	{
		//m_hStateManager->Remove(this);
		m_hStateManager->Add(state_2);
		state_2->Load();
	}
	mushroom->Update(gameTime);
}

void State_1::Render()
{
	_LocalGraphic->Begin(camera->GetTransformMatrix());
	
	//_LocalGraphic->DrawTexture(wall, D3DXVECTOR2(720,450), D3DXVECTOR2(720, 450), D3DCOLOR_XRGB(255, 255, 255), 0.2);
	map1->Render();
	mushroom->Render();
	_LocalGraphic->End();
}
