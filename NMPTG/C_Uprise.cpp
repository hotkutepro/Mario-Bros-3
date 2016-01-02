#include "C_Uprise.h"
#include "Collision.h"


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
	m_hBox_Shadow->_size.x = 16;//16
	m_hBox_Shadow->_size.y = 6;
	m_hC_Shadow = -(-m_hVector.y*m_hPosition.x+m_hVector.x*m_hPosition.y);
}

void C_Uprise::Update(float gameTime)
{	
	if (_LocalHero->m_hPosition.x < m_hPosition.x )
	{
		m_hBox_Shadow->_position.x = m_hPosition.x;

		m_hBox_Shadow->_position.y = m_hPosition.y;
		if (m_hVector.y*m_hVector.x < 0)
			m_hBox_Shadow->_position.y += m_hSize.y;
	}
	else if (_LocalHero->m_hPosition.x>m_hPosition.x + m_hSize.x -16)
	{
		m_hBox_Shadow->_position.x = m_hPosition.x + m_hSize.x-16;	

		m_hBox_Shadow->_position.y = m_hPosition.y;
		if (m_hVector.y*m_hVector.x > 0)			
			m_hBox_Shadow->_position.y +=+ m_hSize.y;		
			
	}
	else 
	{
		m_hBox_Shadow->_position.x = _LocalHero->m_hPosition.x;
		float dy = (_LocalHero->m_hPosition.x - m_hPosition.x)*(m_hVector.y / m_hVector.x);

		m_hBox_Shadow->_position.y = m_hPosition.y + dy ;
		if (m_hVector.y*m_hVector.x < 0)					
			m_hBox_Shadow->_position.y += m_hSize.y;
	}
}

void C_Uprise::Render()
{

}
