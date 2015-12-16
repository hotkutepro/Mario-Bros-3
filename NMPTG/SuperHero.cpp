#include "SuperHero.h"
#include"ResourcesManager.h"

SuperHero::SuperHero()
{
}


SuperHero::~SuperHero()
{
}

void SuperHero::Load()
{
	Strike = ResourcesManager::GetInstance()->GetSprite(SpriteID::Strike);
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
#pragma endregion
	setCurrentSprite(MarioRight);
	m_hPosition.x = 100;
	m_hPosition.y = 320;
	status = 0;
	level = 5;
	m_hState = ON_SPACE;
	Object::Load();
}

void SuperHero::Update(float gametime)
{
	if (m_hBox->v.y == 0){
		if (direction == true)
		{
			switch (status)
			{
			case MARIO:
				setCurrentSprite(MarioRight);
				break;
			case BIGMARIO:
				setCurrentSprite(BigMarioRight);
				break;
			case BROS:
				setCurrentSprite(BrosRight);
				break;
			default:
				break;
			}

		}
		else
		{
			switch (status)
			{
			case MARIO:
				setCurrentSprite(MarioLeft);
				break;
			case BIGMARIO:
				setCurrentSprite(BigMarioLeft);
				break;
			case BROS:
				setCurrentSprite(BrosLeft);
				break;
			default:
				break;
			}

		}
	}
	_LocalKeyboard->GetDeviceState();
	if (_LocalKeyboard->IsKeyDown(DIK_LCONTROL))
	{
		if (_LocalKeyboard->IsKeyDown(DIK_RIGHT))
		{
			RunRight(gametime);
		}
		else if (_LocalKeyboard->IsKeyDown(DIK_LEFT))
		{
			RunLeft(gametime);
		}
		else
		{
			Inertia(gametime);
		}
	}
	else
	{
		if (_LocalKeyboard->IsKeyDown(DIK_RIGHT))
		{
			GoRight(gametime);
		}
		else if (_LocalKeyboard->IsKeyDown(DIK_LEFT))
		{
			GoLeft(gametime);
		}
		else
		{
			Inertia(gametime);
		}
	}
	/*if (_LocalKeyboard->IsKeyDown(DIK_SPACE))
	{		
		if (m_hState==ON_GROUND)
		{

			Jump(gametime);
			m_hState = ON_SPACE;
		}
	}*/
	//if (m_hState == ON_SPACE)
 		//Fall(gametime);
	m_hCurrentSprite->Next();
	_LocalKeyboard->ClearBuffer();


	for (DWORD i = 0; i < _LocalKeyboard->dwElements; i++)
	{
		int state = _LocalKeyboard->_KeyEvents[i].dwData;
		int keycode = _LocalKeyboard->_KeyEvents[i].dwOfs;
		if (state & 0x80)
		{
			if (keycode == DIK_SPACE)
			{
				Jump(gametime);
				//m_hBox->v.y = 10;
				//m_hState = ON_SPACE;
			}			
		}
		else
		{
			if (keycode == DIK_SPACE)
			{
				JumpKeyUp(gametime);
				//m_hState = ON_SPACE
			}

		}
	}

	Object::Update(gametime);
}

void SuperHero::GoLeft(float gameTime)
{		
	m_hBox->v.x -= _tx_frame;
	if (m_hBox->v.x <= -_hero_SPEED)
	{
		m_hBox->v.x = -_hero_SPEED;
	}	
	if (isJump == true)
	{
		switch (status)
		{
		case MARIO:
			setCurrentSprite(MarioJumpLeft);
			break;
		case BIGMARIO:
			if (m_hBox->v.y > 0)
			{
				setCurrentSprite(BigMarioJumpLeft);
			}
			else
			{
				setCurrentSprite(BigMarioFallLeft);
			}
			break;
		case BROS:
			setCurrentSprite(BrosJumpLeft);
			break;
		default:

			break;
		}
	}
	//ngược lại thì tạo animation
	else
	{
		if (m_hBox->v.x > 0)
		{
			switch (status)
			{
			case MARIO:
				setCurrentSprite(MarioDriftToLeft);
				break;
			case BIGMARIO:
				setCurrentSprite(BigMarioDriftToLeft);
				break;
			case BROS:
				setCurrentSprite(BrosDriftToLeft);
			default:

				break;
			}

		}
		else
		{

			switch (status)
			{
			case BIGMARIO:
				setCurrentSprite(BigMarioLeft);
				break;
			case BROS:
				setCurrentSprite(BrosLeft);
				break;
			default:
				setCurrentSprite(MarioLeft);
				break;
			}			
		}

	}
}

void SuperHero::GoRight(float gameTime)
{
	m_hBox->v.x += _tx_frame;
	if (m_hBox->v.x >= _hero_SPEED)
	{
		m_hBox->v.x = _hero_SPEED;
	}
	m_hPosition.x += m_hBox->v.x;
	//nếu mario đang nhảy thì chỉ update tọa độ x qua phải
	if (isJump == true)
	{

		switch (status)
		{
		case MARIO:
			if (getCurrentSprite() != MarioJumpRight)
			{
				setCurrentSprite(MarioJumpRight);
			}

			break;
		case BIGMARIO:
			if (m_hBox->v.y > 0)
			{
				setCurrentSprite(BigMarioJumpRight);
			}
			else
			{
				setCurrentSprite(BigMarioFallRight);
			}
			break;
		case BROS:
			setCurrentSprite(BrosJumpRight);
		default:
			break;
		}
	}
	//ngược lại mario k nhảy thì update tọa độ qua phải và tạo animation
	else
	{

		//chuyển spirte
		if (m_hBox->v.x < 0)
		{
			switch (status)
			{
			case MARIO:
				setCurrentSprite(MarioDriftToRight);
				break;
			case BIGMARIO:
				setCurrentSprite(BigMarioDriftToRight);
				break;
			case BROS:
				setCurrentSprite(BrosDriftToRight);
				break;
			default:

				break;
			}
		}
		else
		{
			switch (status)
			{
			case MARIO:
				setCurrentSprite(MarioRight);
				break;
			case BIGMARIO:
				setCurrentSprite(BigMarioRight);
				break;
			case BROS:
				setCurrentSprite(BrosRight);
				break;
			default:
				break;
			}			
		}

	}

}

void SuperHero::RunLeft(float gameTime)
{
	direction = false;
	isRun = true;
	if (m_hBox->v.x > -_hero_SPEED)
	{
		m_hBox->v.x -= _tx_frame;
	}
	else
	{
		m_hBox->v.x -= level*_SPEED_RUN;
	}
	if (m_hBox->v.x <= -_max_SPEED_RUN)
	{
		m_hBox->v.x = -_max_SPEED_RUN;
	}
}

void SuperHero::RunRight(float gameTime)
{
	direction = true;
	isRun = true;
	if (m_hBox->v.x < _hero_SPEED)
	{
		m_hBox->v.x += _tx_frame;
	}
	else
	{
		m_hBox->v.x += level*_SPEED_RUN;
	}
	if (m_hBox->v.x >= _max_SPEED_RUN)
	{
		m_hBox->v.x = _max_SPEED_RUN;
	}
}

void SuperHero::Inertia(float gameTime)
{
	if (m_hBox->v.x > 0)
	{		
		m_hBox->v.x -= _tx_frame;		
		if (m_hBox->v.x < 0)
		{
			m_hBox->v.x = 0;
		}

	}
	//nếu thả phím qua trái thì vận tốc tăng từ min đến 0
	if (m_hBox->v.x < 0)
	{		
		m_hBox->v.x += _tx_frame;		
		if (m_hBox->v.x > 0)
		{
			m_hBox->v.x = 0;
		}
	}	
}

void SuperHero::InertiaRun(float gameTime)
{

}

void SuperHero::Jump(float gameTime)
{
	if (m_hState==ON_SPACE)
		return;
	isJump = true;
	m_hBox->v.y = 10;
	m_hState = ON_SPACE;
	//set sprite
#pragma region Set Sprite

	if (abs(m_hSpeed.x) >= _max_SPEED_RUN)
	{
		switch (status)
		{
		case MARIO:
			if (direction == true)
			{
				setCurrentSprite(MarioSuperJumpRight);
			}
			else
			{
				setCurrentSprite(MarioSuperJumpLeft);
			}
			break;
		case BIGMARIO:
			if (direction == true)
			{
				setCurrentSprite(BigMarioSuperJumpRight);
			}
			else
			{
				setCurrentSprite(BigMarioSuperJumpLeft);
			}
			break;
		case BROS:
			if (direction == true)
			{
				setCurrentSprite(BrosFlyRight);
			}
			else
			{
				setCurrentSprite(BrosFlyLeft);
			}
		default:
			break;
		}
	}
	else
	{
		switch (status)
		{
		case MARIO:
			if (direction == true)
			{
				setCurrentSprite(MarioJumpRight);
			}
			else
			{
				setCurrentSprite(MarioJumpLeft);
			}
			break;
		case BIGMARIO:
			if (direction == true)
			{
				setCurrentSprite(BigMarioJumpRight);
			}
			else
			{
				setCurrentSprite(BigMarioJumpLeft);
			}
			break;
		case BROS:
			if (direction == true)
			{
				setCurrentSprite(BrosJumpRight);
			}
			else
			{
				setCurrentSprite(BrosJumpLeft);
			}
		default:
			break;
		}
	}
		
	//if (m_hBox->v.y<_max_SPEED_JUMP)
	//{
	//	m_hBox->v.y += _SPEED_JUMP;
	//}
	//else
	//{
	//	m_hState = STATE::ON_SPACE;
	//}
	
	
}

void SuperHero::JumpKeyUp(float gameTime)
{
	if (m_hBox->v.y > 0)
		m_hBox->v.y /= 2;
}

void SuperHero::Fall(float remaintime)//binh thuong =1
{
	if (m_hState != ON_SPACE)
		return;
	m_hBox->v.y -= _SPEED_JUMP*remaintime;
	if (isJump == true)
	{
		if (m_hBox->v.y < 0)
		{
			switch (status)
			{

			case BIGMARIO:
				if (direction == true)
				{
					setCurrentSprite(BigMarioFallRight);
				}
				else
				{
					setCurrentSprite(BigMarioFallLeft);
				}
				break;

			}
		}

	}
}

void SuperHero::Squat(float gameTime)
{
	switch (status)
	{
	case BIGMARIO:
		if (direction == true)
		{
			setCurrentSprite(BigMarioSitRight);
		}
		else
		{
			setCurrentSprite(BigMarioSitLeft);
		}
		break;
	case BROS:
		if (direction == true)
		{
			setCurrentSprite(BrosSitRight);
		}
		else
		{
			setCurrentSprite(BrosSitLeft);
		}
		break;
	default:
		break;
	}
}
