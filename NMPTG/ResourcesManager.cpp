#include "ResourcesManager.h"
#include <stddef.h>
#include "FrkGraphic.h"
#include "FrkShareControl.h"
ResourcesManager::ResourcesManager()
{
	
}


ResourcesManager::~ResourcesManager()
{
}

ResourcesManager* ResourcesManager::Instance = NULL;

ResourcesManager* ResourcesManager::GetInstance()
{
	if (Instance == NULL)
	{
		Instance = new ResourcesManager();
	}
	return Instance;
}

void ResourcesManager::Init()
{
	heroLeft = _LocalContent->LoadTexture("marioleft.png");
	heroRight = _LocalContent->LoadTexture("marioright.png");
	tileMap1 = _LocalContent->LoadTexture("hihi.png");
	wall_1 = _LocalContent->LoadTexture("1.jpg");
	wall_2 = _LocalContent->LoadTexture("2.jpg");
	heroJumpLeft = _LocalContent->LoadTexture("MarioJumpLeft.png"); 
	heroJumpRight = _LocalContent->LoadTexture("MarioJumpRight.png");
	heroDriftToLeft = _LocalContent->LoadTexture("MarioDriftToLeft.png");
	heroDriftToRight = _LocalContent->LoadTexture("MarioDriftToRight.png");
	coinBox = _LocalContent->LoadTexture("CoinBox.png");
	E_mushroom = _LocalContent->LoadTexture("resources\\Cut\\E_Mushroom.png");
	E_flyMushroom = _LocalContent->LoadTexture("resources\\Cut\\a.png");
}

FrkTexture* ResourcesManager::GetTexture(TextureID ID)
{
	switch (ID)
	{
	case HeroLeft:
		return this->heroLeft;
	case HeroRight:
		return this->heroRight;
	case TileMap1:
		return this->tileMap1;
	case  Wall_1:
		return this->wall_1;
	case Wall_2:
		return this->wall_2;
	case HeroDriftToLeft:
		return this->heroDriftToLeft;
	case HeroDriftToRight:
		return this->heroDriftToRight;
	case HeroJumpLeft:
		return this->heroJumpLeft;
	case HeroJumpRight:
		return this->heroJumpRight;
	case CoinBox:
		return this->coinBox;
	case CoinBoxNull:
		return this->coinBoxNull;
	case MushroomPower:
		return this->mushroomPower;
	case Leaf:
		return this->leaf;
	case EnermyMushroom:
		return this->E_mushroom;
	case  EnermyFlyMushroom:
		return this->E_flyMushroom;

	}
	return NULL;
}
