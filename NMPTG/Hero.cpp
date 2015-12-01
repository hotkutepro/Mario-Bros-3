#include "Hero.h"
#include"FrkShareControl.h"

Hero::Hero()
{

}

Hero::Hero(D3DXVECTOR2 pos, D3DXVECTOR2 speed) :Object(pos,speed)
{

}


Hero::~Hero()
{
}

void Hero::setCurrentSprite(FrkSprite* s)
{
	m_hCurrentSprite = s;
}

FrkSprite* Hero::getCurrentSprite()
{
	return m_hCurrentSprite;
}

void Hero::Load()
{
	m_hSpeed = D3DXVECTOR2(10, 10);	
	SetSite(200, 200);
	setCurrentSprite(m_hMarioRight);
	//m_hBox = new Box(GetPosition().x, GetPosition().y, getCurrentSprite()->_Width, getCurrentSprite()->_Height, m_hSpeed.x, m_hSpeed.y);
	BigMarioDriftToLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioDriftToLeft);
	BigMarioDriftToRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioDriftToRight);
	BigMarioFallLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioFallLeft);
	BigMarioFallRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioFallRight);
	BigMarioHugLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioHugLeft);
	BigMarioHugRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioHugRight);
	BigMarioJumpLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioJumpLeft);
	BigMarioJumpRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioJumpRight);
	BigMarioKickLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioKickLeft);
	BigMarioKickRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioKickRight);
	BigMarioLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioLeft);
	BigMarioRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioRight);
	BigMarioRunLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioRunLeft);
	BigMarioRunRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioRunRight);
	BigMarioSitLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioSitLeft);
	BigMarioSitRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioSitRight);
	BigMarioSuperJumpLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioSuperJumpLeft);
	BigMarioSuperJumpRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BigMarioSuperJumpRight);
	BrosBaleLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosBaleLeft);
	BrosBaleRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosBaleRight);
	BrosDriftToLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosDriftToLeft);
	BrosDriftToRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosDriftToRight);
	BrosFallLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosFallLeft);
	BrosFallRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosFallRight);
	BrosFlyLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosFlyLeft);
	BrosFlyRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosFlyRight);
	BrosHugLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosHugLeft);
	BrosHugRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosHugRight);
	BrosJumpLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosJumpLeft);
	BrosJumpRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosJumpRight);
	BrosKickLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosKickLeft);
	BrosKickRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosKickRight);
	BrosLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosLeft);
	BrosRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosRight);
	BrosRunLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosRunLeft);
	BrosRunRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosRunRight);
	BrosSitLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosSitLeft);
	BrosSitRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::BrosSitRight);
	MarioDeath = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioDeath);
	MarioDriftToLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioDriftToLeft);
	MarioDriftToRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioDriftToRight);
	MarioHugLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioHugLeft);
	MarioHugRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioHugRight);
	MarioJumpLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioJumpLeft);
	MarioJumpRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioJumpRight);
	MarioKickLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioKickLeft);
	MarioKickRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioKickRight);
	MarioLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioLeft);
	MarioRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioRight);
	MarioRunLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioRunLeft);
	MarioRunRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioRunRight);
	MarioSuperJumpLeft = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioSuperJumpLeft);
	MarioSuperJumpRight = ResourcesManager::GetInstance()->GetSprite(SpriteID::MarioSuperJumpRight);
	setCurrentSprite(MarioRight);
}

void Hero::Render()
{
	getCurrentSprite()->Render(GetPosition());
}

void Hero::Update(float gameTime)
{	
	_LocalKeyboard->GetDeviceState();
	if (_LocalKeyboard->IsKeyDown(DIK_LEFT))
	{
		m_hSpeed.x = -abs(m_hSpeed.x);
		SetSite(GetPosition().x + m_hSpeed.x, GetPosition().y);		
		setCurrentSprite(BigMarioRunLeft);
		getCurrentSprite()->Next();
	}
	if (_LocalKeyboard->IsKeyDown(DIK_RIGHT)){
		m_hSpeed.x = abs(m_hSpeed.x);
		SetSite(GetPosition().x+m_hSpeed.x, GetPosition().y );
		setCurrentSprite(BigMarioRunRight);
		getCurrentSprite()->Next();
	}
	if (_LocalKeyboard->IsKeyDown(DIK_UP))
	{
		m_hSpeed.y = abs(m_hSpeed.y);
		SetSite(GetPosition().x, GetPosition().y+m_hSpeed.y);
	}
	if (_LocalKeyboard->IsKeyDown(DIK_DOWN)){
		m_hSpeed.y = -abs(m_hSpeed.y);
		SetSite(GetPosition().x , GetPosition().y+m_hSpeed.y);
	}
	m_hBox = new Box(GetPosition().x, GetPosition().y, getCurrentSprite()->_Width, getCurrentSprite()->_Height, m_hSpeed.x, m_hSpeed.y);
	_LocalKeyboard->ClearBuffer();

	//_LocalKeyboard->GetKeyboarddevice()->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), _LocalKeyboard->_KeyEvents, &_LocalKeyboard->dwElements, 0);
	for (DWORD i = 0; i < _LocalKeyboard->dwElements; i++)
	{

		int state = _LocalKeyboard->_KeyEvents[i].dwData;
		int keycode = _LocalKeyboard->_KeyEvents[i].dwOfs;
		if (state & 0x80)
		{
			if (keycode == DIK_K)
			{
				SetSite(GetPosition().x, GetPosition().y + 50);
			}
			if (keycode == DIK_F)
			{
				SetSite(GetPosition().x+16, GetPosition().y);
			}

		}else
		{
			if (keycode == DIK_K)
			{
				SetSite(GetPosition().x, GetPosition().y -100);
			}
			if (keycode == DIK_F)
			{
				SetSite(GetPosition().x -50, GetPosition().y);
			}
		}
	}
}

Box* Hero::getBox()
{
	return m_hBox;
}

void Hero::onkeydown()
{
	SetSite(GetPosition().x-20, GetPosition().y-20);
}
