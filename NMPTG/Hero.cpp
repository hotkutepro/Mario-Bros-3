#include "Hero.h"
#include"FrkShareControl.h"

enum Status
{
	MARIO, BIGMARIO, BROS, RUN
};

Hero::Hero()
{
	status = MARIO;
	delay_next = 0;
	isRun = false;
	isMove = false;
	m_hAcceleration = _hero_ACCELERATION;
	isJump = false;
	direction = true;
}

Hero::Hero(D3DXVECTOR2 pos, D3DXVECTOR2 speed) :Object(pos, speed)
{
	status = MARIO;
	delay_next = 0;
	isRun = false;
	isJump = false;
	isMove = false;
	m_hAcceleration = _hero_ACCELERATION;
	direction = true;
	isControlUp = false;
}


Hero::~Hero()
{
}

void Hero::Load()
{
#pragma region Sprite
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
	Object::Load();
}



void Hero::Update(float gameTime)
{	
	double sx = m_hSpeed.x;
	double sy = m_hSpeed.y;

	f_str1 = "Vy = " + std::to_string(sy);
	f_str = "Vx = " + std::to_string(sx);
	f_str2 = "a = " + std::to_string(m_hAcceleration);
	f_str3 = "s = " + std::to_string(m_hPosition.x);
	a = new char[f_str.length() + 1];
	b = new char[f_str1.length() + 1];
	c = new char[f_str2.length() + 1];
	d = new char[f_str3.length() + 1];
	strcpy(a, f_str.c_str());
	strcpy(b, f_str1.c_str());
	strcpy(c, f_str2.c_str());
	strcpy(d, f_str3.c_str());
	if (m_hSpeed.x == 0)
	{
		getCurrentSprite()->Reset();
	}
	//trọng lực luôn kéo mario rớt xuống
	m_hSpeed.y -= _hero_GRAVITY*gameTime*_hero_LIMITTIME;
	m_hPosition.y += m_hSpeed.y*gameTime*_hero_LIMITTIME;
	//chuyển sprite khi rơi
	Fall(gameTime);
	//tọa độ y giảm tới 200 là dừng
#pragma region Ground_Y
	if (m_hPosition.y <= _hero_GROUND_Y)
	{
		m_hSpeed.y = 0;
		m_hPosition.y = _hero_GROUND_Y;
		isJump = false;
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
	//quán tính vận tốc
	if (m_hSpeed.x != 0 && !_LocalKeyboard->IsKeyDown(DIK_LEFT) && !_LocalKeyboard->IsKeyDown(DIK_RIGHT) && (!_LocalKeyboard->IsKeyDown(DIK_LCONTROL) || _LocalKeyboard->IsKeyDown(DIK_LCONTROL)))
	{
		Inertia(gameTime);
	}

	//đi qua trái
	if (_LocalKeyboard->IsKeyDown(DIK_LEFT) && !_LocalKeyboard->IsKeyDown(DIK_LCONTROL) && !_LocalKeyboard->IsKeyDown(DIK_RIGHT))
	{
		if (isRun && m_hSpeed.x < -_hero_SPEED)
		{
			Inertia(gameTime);
		}
		else
		{
			isRun = false;
			GoLeft(gameTime);
		}
	}
	//chạy qua trái
	if (_LocalKeyboard->IsKeyDown(DIK_LEFT) && _LocalKeyboard->IsKeyDown(DIK_LCONTROL))
	{
		RunLeft(gameTime);
	}
	//đi qua phải
	if (_LocalKeyboard->IsKeyDown(DIK_RIGHT) && !_LocalKeyboard->IsKeyDown(DIK_LCONTROL))
	{
		if (isRun && m_hSpeed.x > _hero_SPEED)
		{
			Inertia(gameTime);
		}
		else
		{
			isRun = false;
			GoRight(gameTime);
		}
	}
	//chạy qua phải
	if (_LocalKeyboard->IsKeyDown(DIK_RIGHT) && _LocalKeyboard->IsKeyDown(DIK_LCONTROL))
	{
		RunRight(gameTime);
	}
	if (_LocalKeyboard->IsKeyDown(DIK_LCONTROL))
	{
		Run();
	}
	if (_LocalKeyboard->IsKeyDown(DIK_DOWN))
	{
		Squat(gameTime);
	}
#pragma endregion
	//	m_hBox = new Box(GetPosition().x, GetPosition().y, getCurrentSprite()->_Width, getCurrentSprite()->_Height, m_hSpeed.x, m_hSpeed.y);
	_LocalKeyboard->ClearBuffer();


	//_LocalKeyboard->GetKeyboarddevice()->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), _LocalKeyboard->_KeyEvents, &_LocalKeyboard->dwElements, 0);

#pragma region KeyPress
	for (DWORD i = 0; i < _LocalKeyboard->dwElements; i++)
	{
		int state = _LocalKeyboard->_KeyEvents[i].dwData;
		int keycode = _LocalKeyboard->_KeyEvents[i].dwOfs;
		if (state & 0x80)
		{
			if (keycode == DIK_SPACE)
			{
				Jump(gameTime);
			}
			if (keycode == DIK_B)
			{
				if (status == BROS)
				{
					status = MARIO;
				}
				else
				{
					status++;
				}
			}
		}
		else
		{
			if (keycode == DIK_SPACE)
			{
				JumpKeyUp(gameTime);
			}

		}
	}
#pragma endregion
}

void Hero::Render()
{
	_LocalGraphic->sDraw(a, D3DXVECTOR2(m_hPosition.x, m_hPosition.y + 20), D3DCOLOR_XRGB(255, 0, 0));
	_LocalGraphic->sDraw(b, D3DXVECTOR2(m_hPosition.x, m_hPosition.y + 50), D3DCOLOR_XRGB(255, 0, 0));
	_LocalGraphic->sDraw(c, D3DXVECTOR2(m_hPosition.x, m_hPosition.y + 80), D3DCOLOR_XRGB(255, 0, 0));
	_LocalGraphic->sDraw(d, D3DXVECTOR2(m_hPosition.x, m_hPosition.y + 110), D3DCOLOR_XRGB(255, 0, 0));
	getCurrentSprite()->Render(GetPosition());
}

void Hero::GoLeft(float gameTime)
{
	isMove = true;
	direction = false;
	delay_next += gameTime / 1.5;
	//giới hạn tốc độ của mario


	//update position qua trái
	m_hSpeed.x -= m_hAcceleration*_hero_LIMITTIME;
	if (m_hSpeed.x <= -_hero_SPEED)
	{
		m_hSpeed.x = -_hero_SPEED;
	}
	m_hPosition.x += m_hSpeed.x;
	//nếu mario đang nhảy thì chỉ set sprite nhảy
	if (isJump == true)
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
			break;
		default:

			break;
		}
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
				setCurrentSprite(BigMarioLeft);
				break;
			case BROS:
				setCurrentSprite(BrosLeft);
				break;
			default:
				setCurrentSprite(MarioLeft);
				break;
			}
			if (delay_next > gameTime)
			{
				delay_next = 0;
				getCurrentSprite()->Next();
			}

		}

	}
}

void Hero::GoRight(float gameTime)
{
	isMove = true;
	direction = true;
	delay_next += gameTime / 1.5;

	//giới hạn tốc độ của mario



	//update position phải
	m_hSpeed.x += m_hAcceleration*_hero_LIMITTIME;
	if (m_hSpeed.x >= _hero_SPEED)
	{
		m_hSpeed.x = _hero_SPEED;
	}
	m_hPosition.x += m_hSpeed.x;
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
			if (delay_next > gameTime)
			{
				delay_next = 0;
				getCurrentSprite()->Next();
			}
		}

	}

}

void Hero::Jump(float gameTime)
{
	isJump = true;
	//set sprite
#pragma region Set Sprite

	if (abs(m_hSpeed.x) >= _hero_MAXSPEED)
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


#pragma endregion 
	//không cho mario nhảy khi đang trong không trung
	if (m_hPosition.y <= _hero_GROUND_Y)
	{
		//khi có trớn nhảy cao hơn
		if (abs(m_hSpeed.x) >= _hero_MAXSPEED)
		{
			m_hSpeed.y = _hero_MAXJUM;
		}
		else//khi không có trớn
		{
			m_hSpeed.y = _hero_JUMP;
		}

	}
}

//

void Hero::JumpKeyUp(float gameTime)
{
	if (m_hSpeed.y > 0)
		m_hSpeed.y /= 3;
}

void Hero::Run()
{
	if (m_hSpeed.x != 0)
	{
		isRun = true;
	}
}

void Hero::Inertia(float gameTime)
{

	
	//nếu thả phím qua phải thì vận tốc giảm từ max đến 0
	if (m_hSpeed.x > 0)
	{
		delay_next += gameTime / 2;
		m_hSpeed.x -= m_hAcceleration*gameTime*_hero_LIMITTIME;
		if (delay_next > gameTime)
		{
			delay_next = 0;
			getCurrentSprite()->Next();
		}
		if (m_hSpeed.x < 0)
		{
			m_hSpeed.x = 0;
		}

	}
	//nếu thả phím qua trái thì vận tốc tăng từ min đến 0
	if (m_hSpeed.x < 0)
	{
		delay_next += gameTime / 2;
		m_hSpeed.x += m_hAcceleration*gameTime*_hero_LIMITTIME;
		if (delay_next > gameTime)
		{
			delay_next = 0;
			getCurrentSprite()->Next();
		}

		if (m_hSpeed.x > 0)
		{
			m_hSpeed.x = 0;
		}
	}
	m_hPosition.x += m_hSpeed.x;
}

D3DXVECTOR2 Hero::getSpeed()
{
	return m_hSpeed;
}

void Hero::Squat(float gameTime)
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

void Hero::Fall(float gameTime)
{
	if (isJump == true)
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

	}
}

void Hero::InertiaRun(float gameTime)
{

	//nếu thả phím qua phải thì vận tốc giảm từ max đến 0
	if (m_hSpeed.x > 2)
	{
		delay_next += gameTime / 2;
		m_hSpeed.x -= m_hAcceleration*gameTime*_hero_LIMITTIME*0.3;
		if (delay_next > gameTime)
		{
			delay_next = 0;
			getCurrentSprite()->Next();
		}
		if (m_hSpeed.x < 2)
		{
			m_hSpeed.x = 2;
		}

	}
	//nếu thả phím qua trái thì vận tốc tăng từ min đến 0
	if (m_hSpeed.x < -2)
	{
		delay_next += gameTime / 2;
		m_hSpeed.x += m_hAcceleration*gameTime*_hero_LIMITTIME*0.1;
		if (delay_next > gameTime)
		{
			delay_next = 0;
			getCurrentSprite()->Next();
		}

		if (m_hSpeed.x > -2)
		{
			m_hSpeed.x = -2;


		}
	}
	m_hPosition.x += m_hSpeed.x;
}

void Hero::RunLeft(float gameTime)
{
	direction = false;
	isRun = true;
	if (m_hSpeed.x > -_hero_SPEED)
	{
		m_hSpeed.x -= m_hAcceleration*gameTime*_hero_LIMITTIME;
	}
	else
	{
		m_hSpeed.x -= m_hAcceleration*gameTime*_hero_LIMITTIME*0.3;
	}
	if (m_hSpeed.x <= -_hero_MAXSPEED)
	{
		m_hSpeed.x = -_hero_MAXSPEED;
	}
	m_hPosition.x += m_hSpeed.x;
}

void Hero::RunRight(float gameTime)
{
	direction = true;
	isRun = true;
	if (m_hSpeed.x < _hero_SPEED)
	{
		m_hSpeed.x += m_hAcceleration*gameTime*_hero_LIMITTIME;
	}
	else
	{
		m_hSpeed.x += m_hAcceleration*gameTime*_hero_LIMITTIME*0.3;
	}
	if (m_hSpeed.x >= _hero_MAXSPEED)
	{
		m_hSpeed.x = _hero_MAXSPEED;
	}
	m_hPosition.x += m_hSpeed.x;
}
