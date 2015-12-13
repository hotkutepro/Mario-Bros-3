#include "Man.h"
#include"ResourcesManager.h"

Man::Man()
{
}


Man::~Man()
{
}

void Man::Load()
{
	
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioLeft);
	m_hPosition.x = m_hPosition.y = 300;
	Object::Load();
}

void Man::Update(float gametime)
{
	Object::Update(gametime);
	/*_LocalKeyboard->GetDeviceState();
	if (_LocalKeyboard->IsKeyDown(DIK_LEFT))
	{
		m_hSpeed.x = -2;
	}
	if (_LocalKeyboard->IsKeyDown(DIK_RIGHT))
	{
		m_hSpeed.x = 2;
	}
	if (_LocalKeyboard->IsKeyDown(DIK_UP))
	{
		m_hSpeed.y = 2;
	}
	if (_LocalKeyboard->IsKeyDown(DIK_DOWN))
	{
		m_hSpeed.y = -2;
	}*/
	_LocalKeyboard->ClearBuffer();
}
