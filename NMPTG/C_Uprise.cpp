#include "C_Uprise.h"


C_Uprise::C_Uprise()
{
	type = TYPEOBJECT::uprise;
}


C_Uprise::~C_Uprise()
{
}

void C_Uprise::Load()
{
	m_hCurrentSprite = NULL;	
	Object::Load();
	m_hBox_Shadow = new Box();
	m_hBox_Shadow->_position.x = m_hPosition.x;
	m_hBox_Shadow->_position.y = m_hPosition.y;
	m_hBox_Shadow->_size.x = 3;
	m_hBox_Shadow->_size.y = 2;
}

void C_Uprise::Update(float gameTime)
{
	if (_LocalHero->m_hPosition.x < m_hPosition.x-8)
	{
		m_hBox_Shadow->_position.x = m_hPosition.x;
		m_hBox_Shadow->_position.y = m_hPosition.y;
	}
	else if (_LocalHero->m_hPosition.x>m_hPosition.x+m_hSize.x-8)
	{
		m_hBox_Shadow->_position.x = m_hPosition.x+m_hSize.x;
		m_hBox_Shadow->_position.y = m_hPosition.y+m_hSize.y;
	}
	else
	{
		m_hBox_Shadow->_position.x = _LocalHero->m_hPosition.x;
		float dy = (_LocalHero->m_hPosition.x - m_hPosition.x)*(m_hVector.y / m_hVector.x);
		m_hBox_Shadow->_position.y = m_hPosition.y + dy;
	}
}
