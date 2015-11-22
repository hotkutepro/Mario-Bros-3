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
	FrkTexture* tLeft;
	tLeft = _LocalContent->LoadTexture("marioleft.png");
	FrkTexture* tRight;
	tRight = _LocalContent->LoadTexture("marioright.png");
	m_hMarioRight = new FrkSprite(tRight, 2, 2);
	m_hMarioLeft = new FrkSprite(tLeft, 4, 4);
	SetSite(200, 200);
	setCurrentSprite(m_hMarioRight);
	m_hBox = new Box(GetPosition().x, GetPosition().y, getCurrentSprite()->_Width, getCurrentSprite()->_Height, m_hSpeed.x, m_hSpeed.y);
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
		setCurrentSprite(m_hMarioLeft);
		getCurrentSprite()->Next();
	}
	if (_LocalKeyboard->IsKeyDown(DIK_RIGHT)){
		m_hSpeed.x = abs(m_hSpeed.x);
		SetSite(GetPosition().x+m_hSpeed.x, GetPosition().y );
		setCurrentSprite(m_hMarioRight);
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
	 
	//////////////////////////////////////////////////////////////////////////
	DWORD dwElements = KEYBOARD_BUFFERSIZE;
	HRESULT hr = _LocalKeyboard->GetKeyboarddevice()->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), _LocalKeyboard->_KeyEvents, &dwElements, 0);
	for (DWORD i = 0; i < dwElements; i++)
	{
		int KeyCode = _LocalKeyboard->_KeyEvents[i].dwOfs;
		int KeyState = _LocalKeyboard->_KeyEvents[i].dwData;
		if (KeyCode == DIK_SPACE && (KeyState & 0x80) > 0)
			onkeydown();
		//if ((KeyState & 0x80) > 0)
			//OnKeyDown(KeyCode);
		//else
			//OnKeyUp(KeyCode);
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
