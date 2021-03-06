#include "E_Plant_Red_Gun.h"
#include"ResourcesManager.h"
#include"Collision.h"
#include"FrkShareControl.h"

E_Plant_Red_Gun::E_Plant_Red_Gun()
{
	type = tree_red_shoot;
}


E_Plant_Red_Gun::~E_Plant_Red_Gun()
{
}

void E_Plant_Red_Gun::Load()
{
	Tree_red_left_down = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_red_left_down);
	Tree_red_left_up = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_red_left_up);
	Tree_red_right_down = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_red_right_down);
	Tree_red_right_up = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_red_right_up);
	ZPipe_md = ResourcesManager::GetInstance()->GetSprite(SpriteID::ZPipe_md);
	m_hCurrentSprite = ResourcesManager::GetInstance()->GetSprite(SpriteID::Tree_red_left_down);
	Object::Load();
	pos.x = m_hPosition.x;
	pos.y = m_hPosition.y - 32;
	m_hPosition.x += 8;	
	m_hPosition.y += 16;
	m_hSpeed.y = -1;
	n = 0;
	bullet = new Bullet();
	bullet->Load();
	bullet->life = false;	
}

void E_Plant_Red_Gun::Update(float gameTime)
{
	if (!life)
		return;
	
	if (bullet->life)
	{ 
		float time = 2,nx,ny;
		time = Collision::sweptAABBCheck(_LocalHero->GetBoxWithObject(bullet), bullet->GetBox(),nx,ny);
		if (time<1)
		{			
			_LocalHero->IsAttacked();
		}
			
		bullet->Update(gameTime);
		bullet->m_hCurrentSprite->Next();
	}
	if (n <= 33){
		m_hPosition.y += m_hSpeed.y;
		m_hCurrentSprite->Next();
	}
	else if (n < 50)
		m_hCurrentSprite->_Index = 0;
	else
		m_hCurrentSprite->Next();

	if (n++ == 200)
	{
		n = 0;
		m_hSpeed.y = -m_hSpeed.y;
	}

	if (n == 40 && m_hSpeed.y > 0)
		shoot();
	Object::Update(gameTime);	
	SetSprite();
}

void E_Plant_Red_Gun::Render()
{
	if (!life)
		return;
	Object::Render();
	ZPipe_md->Render(pos);
	if (bullet->life)
		bullet->Render();
}

void E_Plant_Red_Gun::shoot()
{
	sound = new FrkSound("resources\\sounds\\effect\\smb3_fireball.wav");
	sound->Play();
	bullet->life = true;
	bullet->m_hPosition.x = m_hPosition.x + 8;
	bullet->m_hPosition.y = m_hPosition.y + 24;
	int n = getDirectWithHero(_LocalHero);
	if (n == 1)
	{
		bullet->m_hSpeed.x = -vx;
		bullet->m_hSpeed.y = -vy;
	}
	else if (n == 2)
	{
		bullet->m_hSpeed.x = -vx;
		bullet->m_hSpeed.y = vy;
	}
	else if (n == 3){
		bullet->m_hSpeed.x = vx;
		bullet->m_hSpeed.y = vy;
	}
	else if (n == 4){
		bullet->m_hSpeed.x = vx;
		bullet->m_hSpeed.y = -vy;
	}
}

void E_Plant_Red_Gun::Collision_Up()
{
	_LocalHero->IsAttacked();
}

void E_Plant_Red_Gun::Collision_Down()
{
	_LocalHero->IsAttacked();
}

void E_Plant_Red_Gun::Collision_Left()
{
	_LocalHero->IsAttacked();
}

void E_Plant_Red_Gun::Collision_Right()
{
	_LocalHero->IsAttacked();
}

void E_Plant_Red_Gun::SetSprite()
{
	int n = getDirectWithHero(_LocalHero);
	if (n == 1)
	{
		setCurrentSprite(Tree_red_left_down);
	}
	else if (n == 2)
	{
		setCurrentSprite(Tree_red_left_up);
	}
	else if (n == 3){
		setCurrentSprite(Tree_red_right_up);
	}
	else if (n == 4){
		setCurrentSprite(Tree_red_right_down);
	}
}

void E_Plant_Red_Gun::IsAttacked()
{
	sound = new FrkSound("resources\\sounds\\effect\\smb3_kick.wav");
	sound->Play();
	if (!(n>33&&m_hSpeed.y<0))
		life = false;
}

void E_Plant_Red_Gun::Die()
{
	life = false;
}
