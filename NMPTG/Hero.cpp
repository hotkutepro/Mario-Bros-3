#include "Hero.h"
#include"FrkShareControl.h"
enum Status
{
	MARIO, BIGMARIO, BROS, RUN
};

Hero::Hero()
{
	status = MARIO;
	max_speed = 3;
	delay_next = 0;
	isRun = false;
	isMove = false;
	m_hAcceleration = 0.3;
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
	m_hAcceleration = 0.3;
	direction = true;

}


Hero::~Hero()
{
}

void Hero::Load()
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
	setCurrentSprite(MarioRight);
}

void Hero::Render()
{
	getCurrentSprite()->Render(GetPosition());
}

void Hero::Update(float gameTime)
{
	//trọng lực luôn kéo mario rớt xuống
	m_hSpeed.y -= 0.3*gameTime / 20;
	m_hPosition.y += m_hSpeed.y*gameTime / 20;
	//tọa độ y giảm tới 200 là dừng
	if (m_hPosition.y < 200)
	{
		m_hPosition.y = 200;
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
	//quán tính gia tốc
	if (isRun == false)
	{

		if (m_hAcceleration <= 0.3)
		{
			m_hAcceleration = 0.3;
		}
		m_hAcceleration -= 0.0001;
	}
	//quán tính vận tốc
	if (isMove == false)
	{
		Inertia(gameTime);
	}
	//xử lý phím 
	_LocalKeyboard->GetDeviceState();
	if (_LocalKeyboard->IsKeyDown(DIK_LEFT))
	{
		GoLeft(gameTime);

	}
	if (_LocalKeyboard->IsKeyDown(DIK_RIGHT)){
		GoRight(gameTime);

	}
	if (_LocalKeyboard->IsKeyDown(DIK_LCONTROL))
	{
		Run();
	}

	//	m_hBox = new Box(GetPosition().x, GetPosition().y, getCurrentSprite()->_Width, getCurrentSprite()->_Height, m_hSpeed.x, m_hSpeed.y);
	_LocalKeyboard->ClearBuffer();

	//_LocalKeyboard->GetKeyboarddevice()->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), _LocalKeyboard->_KeyEvents, &_LocalKeyboard->dwElements, 0);
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
			if (keycode == DIK_LEFT)
			{
				isMove = false;
				isRun = false;
			}
			if (keycode == DIK_RIGHT)
			{
				isMove = false;
				isRun = false;
			}
			if (keycode == DIK_SPACE)
			{
				Fall(gameTime);
			}
			if (keycode == DIK_LCONTROL)
			{
				isRun = false;
			}
		}
	}
}

void Hero::GoLeft(float gameTime)
{
	direction = false;
	isMove = true;
	delay_next += gameTime / 2;
	//nếu mario đang nhảy thì chỉ update tọa độ x qua trái
	if (isJump == true)
	{
		switch (status)
		{
		case MARIO:
			setCurrentSprite(MarioJumpLeft);
			break;
		case BIGMARIO:
			setCurrentSprite(BigMarioJumpLeft);
			break;
		case BROS:
			setCurrentSprite(BrosJumpLeft);
			break;
		default:

			break;
		}

		m_hSpeed.x -= m_hAcceleration*gameTime / 20;

		m_hPosition.x += m_hSpeed.x;

	}
	//ngược lại thì update tọa độ qua trái và tạo animation
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
			if (m_hSpeed.x > -6)
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
			else
			{
				switch (status)
				{
				case MARIO:
					setCurrentSprite(MarioRunLeft);
					break;
				case BIGMARIO:
					setCurrentSprite(BigMarioRunLeft);
					break;
				case BROS:
					setCurrentSprite(BrosRunLeft);
				default:
					break;
				}

				getCurrentSprite()->Next();
			}

		}
		m_hSpeed.x -= m_hAcceleration*gameTime / 20;

		m_hPosition.x += m_hSpeed.x;


	}
	//giới hạn tốc độ của mario
	if (isRun == false)
	{
		max_speed = 3;
	}
	else
	{
		max_speed = 6;
	}
	if (m_hSpeed.x < -max_speed)
	{
		m_hSpeed.x = -max_speed;
	}


}

void Hero::GoRight(float gameTime)
{
	direction = true;
	isMove = true;
	delay_next += gameTime / 2;
	//nếu mario đang nhảy thì chỉ update tọa độ x qua phải
	if (isJump == true)
	{
		switch (status)
		{
		case MARIO:
			setCurrentSprite(MarioJumpRight);
			break;
		case BIGMARIO:
			setCurrentSprite(BigMarioJumpRight);
			break;
		case BROS:
			setCurrentSprite(BrosJumpRight);
		default:
			break;
		}

		m_hSpeed.x += m_hAcceleration*gameTime / 20;

		m_hPosition.x += m_hSpeed.x;

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
			if (m_hSpeed.x < 6)
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
			else
			{
				switch (status)
				{
				case MARIO:
					setCurrentSprite(MarioRunRight);
					break;
				case BIGMARIO:
					setCurrentSprite(BigMarioRunRight);
					break;
				case BROS:
					setCurrentSprite(BrosRunRight);
					break;
				default:

					break;
				}
				getCurrentSprite()->Next();
			}

		}
		m_hSpeed.x += m_hAcceleration*gameTime / 20;

		m_hPosition.x += m_hSpeed.x;
	}
	//giới hạn tốc độ của mario

	if (isRun == false)
	{
		max_speed = 3;
	}
	else
	{
		max_speed = 6;
	}
	if (m_hSpeed.x > max_speed)
	{
		m_hSpeed.x = max_speed;
	}

}

void Hero::Jump(float gameTime)
{
	isJump = true;

	if (direction == true)
	{
		if (abs(m_hSpeed.x) >= 6)
		{
			switch (status)
			{
			case MARIO:
				setCurrentSprite(MarioSuperJumpRight);
				break;
			case BIGMARIO:
				setCurrentSprite(BigMarioSuperJumpRight);
				break;
			case BROS:
				setCurrentSprite(BrosFlyRight);
			default:
				break;
			}
		}
		else
		{
			switch (status)
			{
			case MARIO:
				setCurrentSprite(MarioJumpRight);
				break;
			case BIGMARIO:
				setCurrentSprite(BigMarioJumpRight);
				break;
			case BROS:
				setCurrentSprite(BrosJumpRight);
			default:
				break;
			}
		}
	}
	else
	{
		if (abs(m_hSpeed.x) >= 6)
		{
			switch (status)
			{
			case MARIO:
				setCurrentSprite(MarioSuperJumpLeft);
				break;
			case BIGMARIO:
				setCurrentSprite(BigMarioSuperJumpLeft);
				break;
			case BROS:
				setCurrentSprite(BrosFlyLeft);
			default:
				break;
			}
		}
		else
		{
			switch (status)
			{
			case MARIO:
				setCurrentSprite(MarioJumpLeft);
				break;
			case BIGMARIO:
				setCurrentSprite(BigMarioJumpLeft);
				break;
			case BROS:
				setCurrentSprite(BrosJumpLeft);
			default:
				break;
			}
		}

	}
	//không cho mario nhảy khi đang trong không trung
	if (m_hPosition.y <= 200)
	{
		//khi có trớn nhảy cao hơn
		if (abs(m_hSpeed.x) >= 6)
		{
			m_hSpeed.y = 8;
		}
		else//khi không có trớn
		{
			m_hSpeed.y = 5;
		}

	}
}

void Hero::Fall(float gameTime)
{
	if (m_hSpeed.y > 0)
		m_hSpeed.y /= 2;
}

void Hero::Run()
{
	if (m_hSpeed.x != 0)
	{
		isRun = true;
		m_hAcceleration += 0.0001;
		if (m_hAcceleration > 0.8)
		{
			m_hAcceleration = 0.8;
		}
	}
}

void Hero::Inertia(float gameTime)
{

	if (m_hSpeed.x == 0)
	{
		getCurrentSprite()->Reset();
	}
	//nếu thả phím qua phải thì vận tốc giảm từ max đến 0
	if (m_hSpeed.x > 0)
	{
		delay_next += gameTime / 2;
		m_hSpeed.x -= m_hAcceleration*gameTime / 20;
		if (delay_next > gameTime)
		{
			delay_next = 0;
			getCurrentSprite()->Next();
		}


		if (m_hSpeed.x < 0)
		{
			m_hSpeed.x = 0;

		}
		m_hPosition.x += m_hSpeed.x;

	}
	//nếu thả phím qua trái thì vận tốc tăng từ min đến 0
	if (m_hSpeed.x < 0)
	{
		delay_next += gameTime / 2;
		m_hSpeed.x += m_hAcceleration*gameTime / 20;
		if (delay_next > gameTime)
		{
			delay_next = 0;
			getCurrentSprite()->Next();
		}

		if (m_hSpeed.x > 0)
		{
			m_hSpeed.x = 0;
		}
		m_hPosition.x += m_hSpeed.x;
	}
}

D3DXVECTOR2 Hero::getSpeed()
{
	return m_hSpeed;
}
