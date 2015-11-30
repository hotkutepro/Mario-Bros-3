#include "State_2.h"
#include "ResourcesManager.h"
#include "FrkShareControl.h"



State_2::State_2(HINSTANCE hIns, int width, int height, char* wName, StateManager* SM) :State(hIns,width,height,wName,SM)
{
	
}


State_2::~State_2()
{
}

void State_2::Load()
{
//	wall = ResourcesManager::GetInstance()->GetTexture(TextureID::Wall_2);
}

void State_2::Update(float gameTime)
{
	_LocalKeyboard->GetDeviceState();
	if (_LocalKeyboard->IsKeyDown(DIK_RIGHT))
	{
		m_hStateManager->Remove(this);
		
		
	}
}

void State_2::Render()
{
	_LocalGraphic->Begin();
	_LocalGraphic->DrawTexture(wall, D3DXVECTOR2(720, 450), D3DXVECTOR2(720, 450), D3DCOLOR_XRGB(255, 255, 255), 0.2);
	_LocalGraphic->End();
}
