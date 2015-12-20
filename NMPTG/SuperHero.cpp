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
#pragma region LoadSprite
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
	status = 2;
	level = 1;
	direction = DIRECT::right;
	delayMaxSpeed = 0;
	m_hState = ON_SPACE;
	Object::Load();
}

void SuperHero::Update(float gametime)
{
	f_str = "Vx = " + std::to_string(m_hSpeed.x);
	a = new char[f_str.length() + 1];
	strcpy(a, f_str.c_str());

#pragma region KeyDown
	_LocalKeyboard->GetDeviceState();
	//quán tính vận tốc
	if (m_hSpeed.x != 0 && !_LocalKeyboard->IsKeyDown(DIK_LEFT) && !_LocalKeyboard->IsKeyDown(DIK_RIGHT) && (!_LocalKeyboard->IsKeyDown(DIK_LCONTROL) || _LocalKeyboard->IsKeyDown(DIK_LCONTROL)))
	{
		Inertia(gametime);
	}

	//đi qua trái
	if (_LocalKeyboard->IsKeyDown(DIK_LEFT) && !_LocalKeyboard->IsKeyDown(DIK_LCONTROL) && !_LocalKeyboard->IsKeyDown(DIK_RIGHT) && !_LocalKeyboard->IsKeyDown(DIK_DOWN))
	{
		if (isRun && m_hSpeed.x < -_hero_SPEED)
		{
			InertiaRun(gametime);
		}
		else
		{
			isRun = false;
			GoLeft(gametime);
		}
	}
	//chạy qua trái
	if (_LocalKeyboard->IsKeyDown(DIK_LEFT) && _LocalKeyboard->IsKeyDown(DIK_LCONTROL) && !_LocalKeyboard->IsKeyDown(DIK_DOWN) && !_LocalKeyboard->IsKeyDown(DIK_DOWN))
	{
		RunLeft(gametime);
	}
	//đi qua phải
	if (_LocalKeyboard->IsKeyDown(DIK_RIGHT) && !_LocalKeyboard->IsKeyDown(DIK_LCONTROL) && !_LocalKeyboard->IsKeyDown(DIK_LEFT) && !_LocalKeyboard->IsKeyDown(DIK_DOWN))
	{
		if (isRun && m_hSpeed.x > _hero_SPEED)
		{
			InertiaRun(gametime);
		}
		else
		{
			isRun = false;
			GoRight(gametime);
		}
	}
	//chạy qua phải
	if (_LocalKeyboard->IsKeyDown(DIK_RIGHT) && _LocalKeyboard->IsKeyDown(DIK_LCONTROL) && !_LocalKeyboard->IsKeyDown(DIK_LEFT) && !_LocalKeyboard->IsKeyDown(DIK_DOWN))
	{
		RunRight(gametime);
	}

	if (_LocalKeyboard->IsKeyDown(DIK_DOWN))
	{
		Squat(gametime);
	}
	if (_LocalKeyboard->IsKeyDown(DIK_X))
	{
		BrosFly(gametime);
	}
#pragma endregion

#pragma region KeyPressed/Up
	if (_LocalKeyboard->IsKeyPressed(DIK_SPACE))
	{
		Jump(1, 10);
	}

	if (_LocalKeyboard->IsKeyUp(DIK_SPACE))
	{
		JumpKeyUp(1);
	}

	if (_LocalKeyboard->IsKeyUp(DIK_X))
	{
		m_hState = ON_SPACE;
	}
	if (_LocalKeyboard->IsKeyUp(DIK_DOWN))
	{
		isSquat = false;
	}

	_LocalKeyboard->ClearBuffer();
#pragma endregion
#pragma region Process next sprite
	if (m_hState == ON_GROUND)
	{				
		if (!isSquat)
		{
			if (m_hSpeed.x != 0)
			{
				DelayNext(gametime, 2);
			}
			else
			{
				if (direction == DIRECT::right)
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
				getCurrentSprite()->Reset();
			}
		}
	}
	if (m_hState == ON_SPACE)
	{
		if (m_hSpeed.y < 0)
		{
			switch (status)
			{
			case BROS:
				if (direction == DIRECT::right)
				{
					setCurrentSprite(BrosFallRight);
				}
				else
				{
					setCurrentSprite(BrosFallLeft);
				}
				break;
			case BIGMARIO:
				if (direction == DIRECT::right)
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
#pragma endregion
	KillEnemy();
	EatFood();
	this->Move();
}

void SuperHero::GoLeft(float gameTime)
{
	if (m_hState == ON_FLY)
	{
		direction = DIRECT::left;
		return;
	}
	direction = DIRECT::left;
	m_hSpeed.x -= _tx_frame;
	if (m_hSpeed.x <= -_hero_SPEED)
	{
		m_hSpeed.x = -_hero_SPEED;
	}
	//m_hPosition.x += m_hSpeed.x;
	if (m_hState == ON_SPACE)
	{
		return;
	}
	//ngược lại thì tạo animation
	else
	{
		if (m_hSpeed.x > 0)
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
				if (!getCurrentSprite()->IsSprite(BigMarioLeft))
				{
					setCurrentSprite(BigMarioLeft);
				}
				break;
			case BROS:
				if (!getCurrentSprite()->IsSprite(BrosLeft))
				{
					setCurrentSprite(BrosLeft);
				}
				break;
			default:
				if (!getCurrentSprite()->IsSprite(MarioLeft))
				{
					setCurrentSprite(MarioLeft);
				}
				break;
			}
		}

	}
}

void SuperHero::GoRight(float gameTime)
{
	if (m_hState == ON_FLY)
	{
		direction = DIRECT::right;
		return;
	}
	direction = DIRECT::right;
	m_hSpeed.x += _tx_frame;
	if (m_hSpeed.x >= _hero_SPEED)
	{
		m_hSpeed.x = _hero_SPEED;
	}
	//m_hPosition.x += m_hSpeed.x;
	//nếu mario đang nhảy thì chỉ update tọa độ x qua phải
	if (m_hState == ON_SPACE)
	{
		return;
	}
	//ngược lại mario k nhảy thì update tọa độ qua phải và tạo animation
	else
	{
		//chuyển spirte
		if (m_hSpeed.x < 0)
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
				if (!getCurrentSprite()->IsSprite(MarioRight))
				{
					setCurrentSprite(MarioRight);
				}
				break;
			case BIGMARIO:
				if (!getCurrentSprite()->IsSprite(BigMarioRight))
				{
					setCurrentSprite(BigMarioRight);
				}
				break;
			case BROS:
				if (!getCurrentSprite()->IsSprite(BrosRight))
				{
					setCurrentSprite(BrosRight);
				}
				break;
			default:
				break;
			}
		}

	}

}

void SuperHero::RunLeft(float gameTime)
{
	direction = direction = DIRECT::left;
	isRun = true;
	if (m_hSpeed.x > -_hero_SPEED)
	{
		m_hSpeed.x -= _tx_frame;
	}
	else
	{
		m_hSpeed.x -= level*_SPEED_RUN;
	}
	if (m_hSpeed.x <= -_hero_MAXSPEED)
	{
		m_hSpeed.x = -_hero_MAXSPEED;
	}
#pragma region Set Sprite
	if (m_hState == ON_SPACE)
	{
		switch (status)
		{
		case MARIO:
			setCurrentSprite(MarioJumpLeft);
			break;
		case BIGMARIO:
			if (m_hSpeed.y > 0)
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
		default:
			break;
		}
	}
	//ngược lại mario k nhảy thì update tọa độ qua phải và tạo animation
	else
	{
		//chuyển spirte


		switch (status)
		{
		case MARIO:
			if (m_hSpeed.x > 0)
			{
				setCurrentSprite(MarioDriftToLeft);
			}
			else if (m_hSpeed.x < 0 && m_hSpeed.x >= -_hero_SPEED)
			{
				setCurrentSprite(MarioLeft);
			}
			else if (m_hSpeed.x <-_hero_SPEED && m_hSpeed.x >-_hero_MAXSPEED)
			{
				setCurrentSprite(MarioLeft);
			}
			else
			{
				setCurrentSprite(MarioRunLeft);
			}
			break;
		case BIGMARIO:
			if (m_hSpeed.x > 0)
			{
				setCurrentSprite(BigMarioDriftToLeft);
			}
			else if (m_hSpeed.x < 0 && m_hSpeed.x >= -_hero_SPEED)
			{
				setCurrentSprite(BigMarioLeft);
			}
			else if (m_hSpeed.x <-_hero_SPEED && m_hSpeed.x >-_hero_MAXSPEED)
			{
				setCurrentSprite(BigMarioLeft);
			}
			else
			{
				setCurrentSprite(BigMarioRunLeft);
			}
			break;
		case BROS:
			if (m_hSpeed.x > 0)
			{
				setCurrentSprite(BrosDriftToLeft);
			}
			else if (m_hSpeed.x < 0 && m_hSpeed.x >= -_hero_SPEED)
			{
				setCurrentSprite(BrosLeft);
			}
			else if (m_hSpeed.x <-_hero_SPEED && m_hSpeed.x >-_hero_MAXSPEED)
			{
				setCurrentSprite(BrosLeft);
			}
			else
			{
				setCurrentSprite(BrosRunLeft);
			}
			break;
		default:

			break;
		}

	}
#pragma  endregion

}

void SuperHero::RunRight(float gameTime)
{
	//process
	direction = DIRECT::right;
	isRun = true;
	if (m_hSpeed.x < _hero_SPEED)
	{
		m_hSpeed.x += _tx_frame;
	}
	else
	{
		m_hSpeed.x += level*_SPEED_RUN;
	}
	if (m_hSpeed.x >= _hero_MAXSPEED)
	{
		m_hSpeed.x = _hero_MAXSPEED;
	}
#pragma region Set Sprite
	if (m_hState == ON_SPACE)
	{
		switch (status)
		{
		case MARIO:
			setCurrentSprite(MarioJumpRight);
			break;
		case BIGMARIO:
			if (m_hSpeed.y > 0)
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


		switch (status)
		{
		case MARIO:
			if (m_hSpeed.x < 0)
			{
				setCurrentSprite(MarioDriftToRight);
			}
			else if (m_hSpeed.x>0 && m_hSpeed.x <= _hero_SPEED)
			{
				setCurrentSprite(MarioRight);
			}
			else if (m_hSpeed.x > _hero_SPEED && m_hSpeed.x < _hero_MAXSPEED)
			{
				setCurrentSprite(MarioRight);
			}
			else
			{
				setCurrentSprite(MarioRunRight);
			}
			break;
		case BIGMARIO:
			if (m_hSpeed.x < 0)
			{
				setCurrentSprite(BigMarioDriftToRight);
			}
			else if (m_hSpeed.x>0 && m_hSpeed.x <= _hero_SPEED)
			{
				setCurrentSprite(BigMarioRight);
			}
			else if (m_hSpeed.x > _hero_SPEED && m_hSpeed.x < _hero_MAXSPEED)
			{
				setCurrentSprite(BigMarioRight);
			}
			else
			{
				setCurrentSprite(BigMarioRunRight);
			}
			break;
		case BROS:
			if (m_hSpeed.x < 0)
			{
				setCurrentSprite(BrosDriftToRight);
			}
			else if (m_hSpeed.x>0 && m_hSpeed.x <= _hero_SPEED)
			{
				setCurrentSprite(BrosRight);
			}
			else if (m_hSpeed.x > _hero_SPEED && m_hSpeed.x < _hero_MAXSPEED)
			{
				setCurrentSprite(BrosRight);
			}
			else
			{
				setCurrentSprite(BrosRunRight);
			}
			break;
		default:

			break;
		}

	}
#pragma  endregion
}

void SuperHero::Inertia(float gameTime)
{
	if (m_hState == ON_FLY)
	{
		return;
	}
	if (m_hSpeed.x > 0)
	{
		m_hSpeed.x -= _tx_frame;
		if (m_hSpeed.x < 0)
		{
			m_hSpeed.x = 0;
		}

	}
	//nếu thả phím qua trái thì vận tốc tăng từ min đến 0
	if (m_hSpeed.x < 0)
	{
		m_hSpeed.x += _tx_frame;
		if (m_hSpeed.x > 0)
		{
			m_hSpeed.x = 0;
		}
	}
}

void SuperHero::InertiaRun(float gameTime)
{
	if (m_hState == ON_FLY)
	{
		return;
	}
	delayMaxSpeed += gameTime;
	if (delayMaxSpeed > gameTime * 18)
	{
		if (m_hSpeed.x > _hero_SPEED)
		{
			m_hSpeed.x -= _tx_frame;
			if (m_hSpeed.x < _hero_SPEED)
			{
				delayMaxSpeed = 0;
				m_hSpeed.x = _hero_SPEED;
			}

		}
		//nếu thả phím qua trái thì vận tốc tăng từ min đến 0
		if (m_hSpeed.x < -_hero_SPEED)
		{
			m_hSpeed.x += _tx_frame;
			if (m_hSpeed.x > -_hero_SPEED)
			{
				delayMaxSpeed = 0;
				m_hSpeed.x = -_hero_SPEED;
			}
		}
	}
}

void SuperHero::Jump(float gameTime, float vJump)
{
	if (m_hState == ON_SPACE)
		return;
	isJump = true;
	m_hSpeed.y = vJump;
	m_hState = ON_SPACE;
	m_hObjectGround = NULL;
	//set sprite
#pragma region Set Sprite

	if (abs(m_hSpeed.x) >= _max_SPEED_RUN)
	{
		switch (status)
		{
		case MARIO:
			if (direction == DIRECT::right)
			{
				setCurrentSprite(MarioSuperJumpRight);
			}
			else
			{
				setCurrentSprite(MarioSuperJumpLeft);
			}
			break;
		case BIGMARIO:
			if (direction == DIRECT::right)
			{
				setCurrentSprite(BigMarioSuperJumpRight);
			}
			else
			{
				setCurrentSprite(BigMarioSuperJumpLeft);
			}
			break;
		case BROS:
			if (direction == DIRECT::right)
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
			if (direction == DIRECT::right)
			{
				setCurrentSprite(MarioJumpRight);
			}
			else
			{
				setCurrentSprite(MarioJumpLeft);
			}
			break;
		case BIGMARIO:
			if (direction == DIRECT::right)
			{
				setCurrentSprite(BigMarioJumpRight);
			}
			else
			{
				setCurrentSprite(BigMarioJumpLeft);
			}
			break;
		case BROS:
			if (direction == DIRECT::right)
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
#pragma endregion
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
	if (m_hSpeed.y > 0)
		m_hSpeed.y /= 2;
}

void SuperHero::Fall(float remaintime)//binh thuong =1
{
	if (m_hState != ON_SPACE)
		return;
	m_hSpeed.y -= _SPEED_JUMP*remaintime;
	m_hPosition.y += m_hSpeed.y;
	/*if (isJump == true)
	{
	if (m_hSpeed.y < 0)
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

	}*/
}

void SuperHero::Squat(float gameTime)
{
	isSquat = true;
	switch (status)
	{
	case BIGMARIO:
		if (direction == DIRECT::right)
		{
			setCurrentSprite(BigMarioSitRight);
		}
		else
		{
			setCurrentSprite(BigMarioSitLeft);
		}
		break;
	case BROS:
		if (direction == DIRECT::right)
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

void SuperHero::RenderV()
{
	_LocalGraphic->sDraw(a, D3DXVECTOR2(m_hPosition.x, m_hPosition.y + 40), D3DCOLOR_XRGB(255, 0, 0));
}

void SuperHero::BrosFly(float gameTime)
{
	switch (status)
	{
	case BROS:
		if (abs(m_hSpeed.x) == _hero_MAXSPEED)
		{
			m_hState = ON_FLY;
			m_hObjectGround = NULL;
			if (direction == DIRECT::right)
			{
				m_hSpeed.x = _hero_MAXSPEED;
			}
			else
			{
				m_hSpeed.x = -_hero_MAXSPEED;
			}
			m_hSpeed.y += 0.1;
			m_hPosition.x += m_hSpeed.x;
			m_hPosition.y += m_hSpeed.y;
#pragma region Set Sprite
			if (direction == DIRECT::right)
			{
				setCurrentSprite(BrosFlyRight);
			}
			else
			{
				setCurrentSprite(BrosFlyLeft);
			}
#pragma endregion
		}
		else
		{
			Jump(1, 4);

		}
		break;
	}

}

void SuperHero::BrosFall(float gameTime)
{

}
