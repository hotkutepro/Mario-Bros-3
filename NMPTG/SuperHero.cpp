#include "SuperHero.h"
#include"ResourcesManager.h"
#include <stdlib.h>
#include "Collision.h"

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
	info = new Infomation(300, 0, 0, 4, 0);
	info->Load();
	type = mario;
	setCurrentSprite(MarioRight);
	m_hPosition.x = 30;
	m_hPosition.y = 600;
	status = 2;
	m_hDirect = DIRECT::right;
	delayMaxSpeed = 0;
	m_hState = ON_SPACE;
	timeSuper = 0;
	Object::Load();
}

void SuperHero::Update(float gametime)
{
	info->Update();
	if (timeSuper < 30)
		timeSuper++;
	f_str = "Vx = " + std::to_string(m_hSpeed.x);
	a = new char[f_str.length() + 1];
	strcpy(a, f_str.c_str());
	f_str1 = "Vy = " + std::to_string(m_hSpeed.y);
	a1 = new char[f_str1.length() + 1];
	strcpy(a1, f_str1.c_str());

	_LocalKeyboard->GetDeviceState();
	if (m_hState != OTHER)
	{
#pragma region KeyDown

		//quán tính vận tốc
		if (m_hSpeed.x != 0 && !_LocalKeyboard->IsKeyDown(DIK_LEFT) && !_LocalKeyboard->IsKeyDown(DIK_RIGHT) && (!_LocalKeyboard->IsKeyDown(DIK_LCONTROL) || _LocalKeyboard->IsKeyDown(DIK_LCONTROL)))
		{
			Inertia(gametime);
		}

		//đi qua trái
		if (_LocalKeyboard->IsKeyDown(DIK_LEFT) && !_LocalKeyboard->IsKeyDown(DIK_LCONTROL) && !_LocalKeyboard->IsKeyDown(DIK_RIGHT) && !_LocalKeyboard->IsKeyDown(DIK_DOWN))
		{
			isLeft = true;
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
			isLeft = true;
			ready = true;
			RunLeft(gametime);
		}
		//đi qua phải
		if (_LocalKeyboard->IsKeyDown(DIK_RIGHT) && !_LocalKeyboard->IsKeyDown(DIK_LCONTROL) && !_LocalKeyboard->IsKeyDown(DIK_LEFT) && !_LocalKeyboard->IsKeyDown(DIK_DOWN))
		{
			isRight = true;
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
			isRight = true;
			ready = true;
			RunRight(gametime);
		}

		if (_LocalKeyboard->IsKeyDown(DIK_DOWN) && !_LocalKeyboard->IsKeyDown(DIK_RIGHT) && !_LocalKeyboard->IsKeyDown(DIK_LEFT))
		{
			isDown = true;
			Squat(gametime);
		}
		if (_LocalKeyboard->IsKeyDown(DIK_X))
		{
			BrosFly(gametime);
		}
		if (_LocalKeyboard->IsKeyDown(DIK_UP))
		{
			isUp = true;
		}
#pragma endregion	

#pragma region KeyPressed/Up
		if (_LocalKeyboard->IsKeyPressed(DIK_LCONTROL))
		{
			Attack();
		}
		if (_LocalKeyboard->IsKeyPressed(DIK_SPACE))
		{
			SuperJump();
			Jump(_hero_JUMP);
		}

		if (_LocalKeyboard->IsKeyUp(DIK_SPACE))
		{
			JumpKeyUp(1);
		}

		if (_LocalKeyboard->IsKeyUp(DIK_X))
		{
			m_hState = ON_SPACE;
		}

		if (_LocalKeyboard->IsKeyUp(DIK_LCONTROL))
		{
			ready = false;
		}
		if (_LocalKeyboard->IsKeyUp(DIK_DOWN))
		{
			isDown = false;
			isSquat = false;
		}
		if (_LocalKeyboard->IsKeyUp(DIK_UP))
		{
			isUp = false;
		}
		if (_LocalKeyboard->IsKeyUp(DIK_LEFT))
		{
			isLeft = false;
		}
		if (_LocalKeyboard->IsKeyUp(DIK_RIGHT))
		{
			isRight = false;
		}
#pragma endregion
	}
	_LocalKeyboard->ClearBuffer();

#pragma region Process next sprite
	if (m_hState == ON_FLY)
	{

	}
#pragma  region ON_GROUND
	if (m_hState == ON_GROUND && !attack)
	{
		if (!isSquat)
		{
			if (m_hSpeed.x != 0)
			{
				DelayNext(3);
			}
			else
			{
				if (m_hDirect == DIRECT::right)
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
#pragma endregion
#pragma region On_SPACE

	if (m_hState == ON_SPACE && !attack && !isDown)
	{
		if (m_hSpeed.y < 0)
		{
			switch (status)
			{
			case BROS:
				if (m_hDirect == DIRECT::right)
				{
					setCurrentSprite(BrosFallRight);
				}
				else
				{
					setCurrentSprite(BrosFallLeft);
				}
				break;
			case BIGMARIO:
				if (m_hDirect == DIRECT::right)
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
#pragma region FALL_DOWN
	if (m_hState == FALL_DOWN)
	{
		if (m_hDirect == DIRECT::right)
		{
			if (!getCurrentSprite()->IsSprite(BrosFallRight))
			{
				setCurrentSprite(BrosFallRight);
			}
		}
		else
		{
			if (!getCurrentSprite()->IsSprite(BrosFallLeft))
			{
				setCurrentSprite(BrosFallLeft);
			}
		}
		getCurrentSprite()->Next();
	}
#pragma endregion
#pragma region ATTACK
	if (attack && m_hState != ON_FLY)
	{
		timeAttack++;
		if (timeAttack > 9)
		{
			timeAttack = 0;
			attack = false;
			return;
		}
		if (m_hDirect == DIRECT::right)
		{
			if (m_hSpeed.x == 0)
			{
				if (!getCurrentSprite()->IsSprite(BrosBaleRight))
					setCurrentSprite(BrosBaleRight);
				else
					DelayNext(3);
			}
			else
			{
				setCurrentSprite(BrosBaleRight);
				DelayNext(2);
			}

		}
		else
		{
			if (m_hSpeed.x == 0)
			{
				if (!getCurrentSprite()->IsSprite(BrosBaleLeft))
				{
					setCurrentSprite(BrosBaleLeft);
				}
				else
				{
					DelayNext(3);
				}
			}
			else
			{
				setCurrentSprite(BrosBaleLeft);
				DelayNext(2);
			}

		}
	}
#pragma endregion
#pragma endregion
	if (m_hState != OTHER)
	{
		KillEnemy();
		EatFood();
	}
	
	this->Move();
}

void SuperHero::Render()
{
	Object::Render();
	info->Render();
}


void SuperHero::GoLeft(float gameTime)
{
	m_hDirect = DIRECT::left;
	if (m_hState == ON_FLY)
	{
		return;
	}
	m_hSpeed.x -= _hero_ACCELERATION;
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
	m_hDirect = DIRECT::right;
	if (m_hState == ON_FLY)
	{
		return;
	}

	m_hSpeed.x += _hero_ACCELERATION;
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
	m_hDirect = m_hDirect = DIRECT::left;
	isRun = true;
	if (m_hSpeed.x > -_hero_SPEED)
	{
		m_hSpeed.x -= _hero_ACCELERATION;
	}
	else
	{
		m_hSpeed.x -= _hero_RUN_ACCELERATION;
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
	m_hDirect = DIRECT::right;
	isRun = true;
	if (m_hSpeed.x < _hero_SPEED)
	{
		m_hSpeed.x += _hero_ACCELERATION;
	}
	else
	{
		m_hSpeed.x += _hero_RUN_ACCELERATION;
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
		m_hSpeed.x -= _hero_ACCELERATION / 3;
		if (m_hSpeed.x < 0)
		{
			m_hSpeed.x = 0;
		}

	}
	//nếu thả phím qua trái thì vận tốc tăng từ min đến 0
	if (m_hSpeed.x < 0)
	{
		m_hSpeed.x += _hero_ACCELERATION / 3;
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
	if (abs(m_hSpeed.x) == _hero_MAXSPEED)
	{
		delayMaxSpeed += gameTime;
		if (delayMaxSpeed > gameTime * 13)
		{
			if (m_hSpeed.x > _hero_SPEED)
			{
				m_hSpeed.x -= _hero_ACCELERATION / 10;
				if (m_hSpeed.x < _hero_SPEED)
				{
					delayMaxSpeed = 0;
					m_hSpeed.x = _hero_SPEED;
				}

			}
			//nếu thả phím qua trái thì vận tốc tăng từ min đến 0
			if (m_hSpeed.x < -_hero_SPEED)
			{
				m_hSpeed.x += _hero_ACCELERATION / 10;
				if (m_hSpeed.x > -_hero_SPEED)
				{
					delayMaxSpeed = 0;
					m_hSpeed.x = -_hero_SPEED;
				}
			}
		}
	}
	else
	{

		if (m_hSpeed.x > _hero_SPEED)
		{
			m_hSpeed.x -= _hero_ACCELERATION / 10;
			if (m_hSpeed.x < _hero_SPEED)
			{
				delayMaxSpeed = 0;
				m_hSpeed.x = _hero_SPEED;
			}

		}
		//nếu thả phím qua trái thì vận tốc tăng từ min đến 0
		if (m_hSpeed.x < -_hero_SPEED)
		{
			m_hSpeed.x += _hero_ACCELERATION / 10;
			if (m_hSpeed.x > -_hero_SPEED)
			{
				delayMaxSpeed = 0;
				m_hSpeed.x = -_hero_SPEED;
			}
		}
	}

}

void SuperHero::Jump(float vJump)
{
	if (m_hState != ON_GROUND)
		return;
	
	m_hSpeed.y = vJump;
	m_hState = ON_SPACE;
	m_hObjectGround = NULL;
	if (m_hSpeed.y == _hero_MAXJUM)
	{
		return;
	}
	//set sprite
#pragma region Set Sprite	
	if (isSquat)
	{
		return;
	}
	switch (status)
	{
	case MARIO:
		if (m_hDirect == DIRECT::right)
		{
			setCurrentSprite(MarioJumpRight);
		}
		else
		{
			setCurrentSprite(MarioJumpLeft);
		}
		break;
	case BIGMARIO:
		if (m_hDirect == DIRECT::right)
		{
			setCurrentSprite(BigMarioJumpRight);
		}
		else
		{
			setCurrentSprite(BigMarioJumpLeft);
		}
		break;
	case BROS:
		if (m_hDirect == DIRECT::right)
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
#pragma endregion
}

void SuperHero::JumpKeyUp(float gameTime)
{
	if (m_hSpeed.y > 0)
		m_hSpeed.y /= 2;
}


void SuperHero::Squat(float gameTime)
{
	isSquat = true;
	switch (status)
	{
	case BIGMARIO:
		if (m_hDirect == DIRECT::right)
		{
			setCurrentSprite(BigMarioSitRight);
		}
		else
		{
			setCurrentSprite(BigMarioSitLeft);
		}
		break;
	case BROS:
		if (m_hDirect == DIRECT::right)
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
	_LocalGraphic->sDraw(a1, D3DXVECTOR2(m_hPosition.x, m_hPosition.y + 60), D3DCOLOR_XRGB(255, 0, 0));
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
			if (m_hDirect == DIRECT::right)
			{
				m_hSpeed.x = _hero_MAXSPEED;
			}
			else
			{
				m_hSpeed.x = -_hero_MAXSPEED;
			}
			m_hSpeed.y += 0.1;

#pragma region Set Sprite
			if (m_hDirect == DIRECT::right)
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
			Jump(_hero_JUMP - 5);//nhảy liên tục khi giữ X
			BrosFall(gameTime);
		}
		break;
	}

}

void SuperHero::BrosFall(float gameTime)
{
	if (m_hState != ON_SPACE)
	{
		return;
	}
	if (m_hSpeed.y >= 0)
	{
		return;
	}
	else
	{
		m_hState = FALL_DOWN;
	}
}

void SuperHero::Attack()
{
	if (status == BROS&&!attack)
	{
		attack = true;
	}

}


void SuperHero::SuperJump()
{
	if (m_hState != ON_GROUND)
	{
		return;
	}
	if (abs(m_hSpeed.x) >= _hero_MAXSPEED)
	{
		Jump(_hero_MAXJUM);
		switch (status)
		{
		case MARIO:
			if (m_hDirect == DIRECT::right)
			{
				setCurrentSprite(MarioSuperJumpRight);
			}
			else
			{
				setCurrentSprite(MarioSuperJumpLeft);
			}
			break;
		case BIGMARIO:
			if (m_hDirect == DIRECT::right)
			{
				setCurrentSprite(BigMarioSuperJumpRight);
			}
			else
			{
				setCurrentSprite(BigMarioSuperJumpLeft);
			}
			break;
		case BROS:
			if (m_hDirect == DIRECT::right)
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
		return;
	}
	else
	{
		return;
	}
}
Box* SuperHero::GetBox()
{
	m_hBox->_position.y = m_hPosition.y;
	m_hBox->_size.y = getCurrentSprite()->_Height;
	m_hBox->_v = m_hSpeed;
	m_hBox->_size.x = _hero_BOX_WIDTH;
	switch (status)
	{
	case MARIO:
		m_hBox->_position.x = m_hPosition.x + 4;
		m_hBox->_size.x = 9;
		break;
	case BIGMARIO:
		if (m_hDirect == DIRECT::right)
		{
			m_hBox->_position.x = m_hPosition.x + _hero_BOX_ADJUST_POS_RIGHT;
		}
		else
		{
			m_hBox->_position.x = m_hPosition.x + _hero_BOX_ADJUST_POS_LEFT + 1;
		}
		break;
	case BROS:
		if (m_hDirect == DIRECT::right)
		{
			m_hBox->_position.x = m_hPosition.x + _hero_BOX_ADJUST_POS_RIGHT + 8;
		}
		else
		{
			m_hBox->_position.x = m_hPosition.x + _hero_BOX_ADJUST_POS_LEFT + 3;
		}
		break;
	}

	return m_hBox;
}
Box* SuperHero::GetBoxWithObject(Object* object)
{
	Box* x = new Box();
	x->_position.y = m_hPosition.y;
	x->_size.y = getCurrentSprite()->_Height;
	x->_v.x = m_hSpeed.x - object->m_hSpeed.x;
	x->_v.y = m_hSpeed.y - object->m_hSpeed.y;
	x->_size.x = _hero_BOX_WIDTH;
	switch (status)
	{
	case MARIO:
		x->_position.x = m_hPosition.x + 4;
		x->_size.x = 9;
		break;
	case BIGMARIO:
		if (m_hDirect == DIRECT::right)
		{
			x->_position.x = m_hPosition.x + _hero_BOX_ADJUST_POS_RIGHT;
		}
		else
		{
			x->_position.x = m_hPosition.x + _hero_BOX_ADJUST_POS_LEFT + 1;
		}
		break;
	case BROS:
		if (m_hDirect == DIRECT::right)
		{
			x->_position.x = m_hPosition.x + _hero_BOX_ADJUST_POS_RIGHT + 8;
		}
		else
		{
			x->_position.x = m_hPosition.x + _hero_BOX_ADJUST_POS_LEFT + 3;
		}
		break;
	}

	
	return x;
}
Box* SuperHero::GetBox_CGround()
{
	Box* x = new Box();
	x->_position.y = m_hPosition.y - 10;
	x->_size.y = getCurrentSprite()->_Height / 2;
	x->_size.x = _hero_BOX_WIDTH;
	switch (status)
	{
	case MARIO:
		x->_position.x = m_hPosition.x + 4;
		break;
	case BIGMARIO:
		if (m_hDirect == DIRECT::right)
		{
			x->_position.x = m_hPosition.x + _hero_BOX_ADJUST_POS_RIGHT;
		}
		else
		{
			x->_position.x = m_hPosition.x + _hero_BOX_ADJUST_POS_LEFT + 1;
		}
		break;
	case BROS:
		if (m_hDirect == DIRECT::right)
		{
			x->_position.x = m_hPosition.x + _hero_BOX_ADJUST_POS_RIGHT + 8;
		}
		else
		{
			x->_position.x = m_hPosition.x + _hero_BOX_ADJUST_POS_LEFT + 3;
		}
		break;
	}

	return x;
}


void SuperHero::Move()
{
	vector<Object*> object_static_can_collision = GetStaticObject();
	float time, nx, ny;
	switch (m_hState)
	{
	case OTHER:
		m_hPosition.y += m_hSpeed.y;
		m_hSpeed.y += GRAVITY / 2;
		break;
	case ON_FLY:

		for (int i = 0; i < object_static_can_collision.size(); i++)
		{
			time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->GetBox(), nx, ny);
			if (time < 1&&time>0)
			{
				if (nx == 1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = 0;
					m_hObjectLeft = object_static_can_collision.at(i);
				}
				if (nx == -1 && object_static_can_collision.at(i)->type != box)
				{

					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = 0;
					m_hObjectRight = object_static_can_collision.at(i);
				}
				if (ny == 1)
				{
					return;
				}
				if (ny == -1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.y += time*m_hSpeed.y;
					m_hSpeed.y = 0;
				}
			}			
		}
		m_hPosition.x += m_hSpeed.x;
		m_hPosition.y += m_hSpeed.y;
		break;
	case FALL_DOWN:

		m_hObjectLeft = NULL;
		m_hObjectRight = NULL;
		for (int i = 0; i < object_static_can_collision.size(); i++)
		{
			time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->GetBox(), nx, ny);
			if (time < 1){
				if (nx == 1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = 0;
					m_hObjectLeft = object_static_can_collision.at(i);
				}
				if (nx == -1 && object_static_can_collision.at(i)->type != box)
				{

					m_hPosition.x += time*m_hSpeed.x;
					m_hSpeed.x = 0;
					m_hObjectRight = object_static_can_collision.at(i);
				}
				if (ny == 1)
				{
					FallDown(time, V_FALLDOWN);/////////
					m_hSpeed.y = 0;
					m_hState = ON_GROUND;
					m_hObjectGround = object_static_can_collision.at(i);///////
					return;
				}
				if (ny == -1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.y += time*m_hSpeed.y;
					m_hSpeed.y = 0;
				}
			}
		}
		//	m_hSpeed.y = -0.5f;
		//	m_hPosition.y += m_hSpeed.y;
		FallDown(1, V_FALLDOWN);
		if (m_hObjectLeft == NULL || m_hObjectRight == NULL)
			m_hPosition.x += m_hSpeed.x;
		break;
	case ON_SPACE:

		m_hObjectLeft = NULL;
		m_hObjectRight = NULL;
		for (int i = 0; i < object_static_can_collision.size(); i++)
		{

			time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->GetBox(), nx, ny);
			if (time < 1){
				//time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->GetBox(), nx, ny);
				if (nx == 1 && object_static_can_collision.at(i)->type != box)
				{
					time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->GetBox(), nx, ny);
					m_hPosition.x += time*m_hSpeed.x;

					m_hSpeed.x = 0;
					m_hObjectLeft = object_static_can_collision.at(i);

				}
				if (nx == -1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.x += time*m_hSpeed.x;

					m_hSpeed.x = 0;
					m_hObjectRight = object_static_can_collision.at(i);

				}
				if (ny == 1 && nx == 0)
				{
					FallDown(time, 0);/////////
					m_hSpeed.y = 0;
					m_hState = ON_GROUND;
					m_hObjectGround = object_static_can_collision.at(i);///////
					return;
				}
				if (ny == -1 && object_static_can_collision.at(i)->type != box)
				{
					m_hPosition.y += time*m_hSpeed.y;
					m_hSpeed.y = 0;
				}
			}
		}
		FallDown(1, 0);
		if (m_hObjectLeft == NULL || m_hObjectRight == NULL)
			m_hPosition.x += m_hSpeed.x;
		break;
	case ON_GROUND:		

		m_hObjectLeft = NULL;
		m_hObjectRight = NULL;
		for (int i = 0; i < object_static_can_collision.size(); i++)
		{			
			if (Collision::checkAABB(Collision::getBoardPhaseBox(GetBox()), object_static_can_collision.at(i)->GetBox()))
			{
				time = Collision::sweptAABBCheck(GetBox(), object_static_can_collision.at(i)->GetBox(), nx, ny);
				if (time < 1 && time >= 0 && object_static_can_collision.at(i)->type != box){
					if (type != mario&&nx != 0){
						//m_hPosition.x += time*m_hSpeed.x;
						m_hSpeed.x = -m_hSpeed.x;
					}
					else if (nx == 1 && object_static_can_collision.at(i)->type != box)
					{

						m_hPosition.x += time*m_hSpeed.x;
						m_hSpeed.x = 0;
						m_hObjectLeft = object_static_can_collision.at(i);
					}
					else if (nx == -1 && object_static_can_collision.at(i)->type != box)
					{
						m_hPosition.x += time*m_hSpeed.x;
						m_hSpeed.x = 0;
						m_hObjectRight = object_static_can_collision.at(i);
					}
				}
			}

		}
		if (this->m_hObjectGround != NULL)
		{
			if (!Collision::checkAABB(this->GetBox_CGround(), this->m_hObjectGround->GetBox()))
			{
				m_hState = ON_SPACE;
			}
		}
		if (m_hObjectLeft == NULL && m_hObjectRight == NULL)
			m_hPosition.x += m_hSpeed.x;
		break;

	}
}

Box* SuperHero::GetBoxTop()
{
	Box* x;
	x = new Box();
	x->_size.x = _hero_BOX_TOP_WIDTH;
	x->_size.y = _hero_BOX_TOP_HEIGHT;
	x->_v = m_hSpeed;
	x->_position.y = m_hPosition.y + getCurrentSprite()->_Height - _hero_BOX_TOP_HEIGHT;
	switch (status)
	{
	case BROS:
		if (m_hDirect == DIRECT::right)
		{
			x->_position.x = m_hPosition.x + getCurrentSprite()->_Height / 2 + 2;
		}
		else
		{
			x->_position.x = m_hPosition.x + getCurrentSprite()->_Height / 2 - 4;
		}
		break;
	case BIGMARIO:
		if (m_hDirect == DIRECT::right)
		{
			x->_position.x = m_hPosition.x + getCurrentSprite()->_Height / 2 - 5;
		}
		else
		{
			x->_position.x = m_hPosition.x + getCurrentSprite()->_Height / 2 - 4;
		}
		break;
	default:
		x->_position.x = m_hPosition.x + getCurrentSprite()->_Height / 2;
		break;
	}



	return x;
}

Box* SuperHero::GetBoxAttack()
{

	Box* x = new Box();
	if (attack)
	{
		x->_size.x = 10;
		x->_size.y = 5;
		x->_v.x = 5;
		x->_v.y = 0;
		if (m_hDirect == DIRECT::right)
		{
			x->_position.x = m_hPosition.x + 20;
			x->_position.y = m_hPosition.y;
		}
		else
		{
			x->_position.x = m_hPosition.x - 5;
			x->_position.y = m_hPosition.y;
		}
	}
	return x;
}

void SuperHero::IsAttacked()
{
	if (timeSuper != 30)
		return;
	else
		timeSuper = 0;
	switch (status)
	{
	case BROS:
		status--;
		if (m_hDirect == DIRECT::right)
		{
			setCurrentSprite(BigMarioRight);
		}
		else
		{
			setCurrentSprite(BigMarioLeft);
		}
		break;
	case BIGMARIO:
		status--;
		if (m_hDirect == DIRECT::right)
		{
			setCurrentSprite(MarioRight);
		}
		else
		{
			setCurrentSprite(MarioLeft);
		}
		break;
	default:
		setCurrentSprite(MarioDeath);
		m_hSpeed.y = 5;
		m_hState = OTHER;
		break;
	}
}

void SuperHero::RenderBoxAttack()
{
	if (attack)
	{
		RECT src;
		src.left = 0;
		src.right = src.left + 1;
		src.top = 0;
		src.bottom = src.top + 1;
		RECT a;
		a = GetBoxAttack()->getRect();
		_LocalGraphic->tDrawTexture(_LocalContent->LoadTexture("boxbottom.png"), src, a, D3DXVECTOR2(GetBoxAttack()->getCenter()), D3DCOLOR_XRGB(255, 255, 255), 0);
	}
}
void SuperHero::RenderBoxBottom()
{
	RECT src;
	src.left = 0;
	src.right = src.left + 1;
	src.top = 0;
	src.bottom = src.top + 1;

	RECT a;
	a = GetBox_CGround()->getRect();
	_LocalGraphic->tDrawTexture(_LocalContent->LoadTexture("boxbottom.png"), src, a, D3DXVECTOR2(GetBox_CGround()->getCenter()), D3DCOLOR_XRGB(255, 255, 255), 0);

}
void SuperHero::RendeBoxTop()
{
	RECT src;
	src.left = 0;
	src.right = src.left + 1;
	src.top = 0;
	src.bottom = src.top + 1;
	RECT a;
	a = GetBoxTop()->getRect();
	_LocalGraphic->tDrawTexture(_LocalContent->LoadTexture("boxbottom.png"), src, a, D3DXVECTOR2(GetBoxTop()->getCenter()), D3DCOLOR_XRGB(255, 255, 255), 0);
}

void SuperHero::Collision_Coin()
{
	info->I_Coin++;
	info->I_Score += 10;
}

void SuperHero::Collision_Leaf()
{
	if (status != BROS)
	{
		status++;
	}
	info->I_Score += 100;
}

void SuperHero::Collision_1up()
{
	info->I_Life++;
}


void SuperHero::Collision_Mushroom()
{
	status++;
}


