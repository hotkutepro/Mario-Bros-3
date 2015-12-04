#include "E_Mushroom.h"
#include "ResourcesManager.h"
#include "FrkShareControl.h"


E_Mushroom::E_Mushroom(int x, int y)
{
	this->m_hPosition.x = x;
	this->m_hPosition.y = y;
	this->m_hAcceleration = 0.5;
	this->m_hSpeed.x = 1;
	this->m_hSpeed.y = -4;
}

E_Mushroom::E_Mushroom()
{

}


E_Mushroom::~E_Mushroom()
{
}

void E_Mushroom::Load()
{
//	FrkTexture* mushroomTexture = ResourcesManager::GetInstance()->GetTexture(TextureID::HeroLeft);
	//this->mushroomSprite = new FrkSprite(mushroomTexture, 2, 2);
}

void E_Mushroom::Render()
{
	mushroomSprite->Render(m_hPosition);
}
float delay = 0;
void E_Mushroom::Update(float gameTime)
{
	delay += gameTime/10 ;
	m_hPosition.x += m_hSpeed.x;
	m_hSpeed.y -= 0.2*gameTime/10;
	m_hPosition.y += m_hSpeed.y*gameTime/10;
	if (m_hPosition.x < 100 || m_hPosition.x>300)
	{
		m_hSpeed.x = -m_hSpeed.x;
	}
	if (gameTime < delay)
	{
		mushroomSprite->Next();
		delay = 0;
	}
	_LocalKeyboard->GetDeviceState();
	DWORD dwElements = KEYBOARD_BUFFERSIZE;
	HRESULT hr = _LocalKeyboard->GetKeyboarddevice()->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), _LocalKeyboard->_KeyEvents, &dwElements, 0);
	for (DWORD i = 0; i < dwElements; i++)
	{
		int KeyCode = _LocalKeyboard->_KeyEvents[i].dwOfs;
		int KeyState = _LocalKeyboard->_KeyEvents[i].dwData;
		
			if ((KeyState & 0x80) > 0)
			{
				if (KeyCode == DIK_SPACE&&m_hPosition.y<=200)
				{
					m_hSpeed.y = 10;
				}
			}
			else
			{
				if (KeyCode == DIK_SPACE)
				{
					if (m_hSpeed.y>0)
					m_hSpeed.y /=2 ;
				}
			}
	}
	
	/*if (m_hPosition.y > 400)
	{
		m_hSpeed.y = -m_hSpeed.y;
		
	}*/
	if (m_hPosition.y < 200)
	{
		m_hPosition.y = 200;
	}

}
