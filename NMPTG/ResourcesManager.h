#pragma once
#include "FrkContent.h"
#include "FrkGame.h"
enum TextureID
{
	HeroLeft, HeroRight, HeroJumpLeft, HeroJumpRight, TileMap1, Wall_1, Wall_2,
	HeroDriftToLeft, HeroDriftToRight, MushroomPower, CoinBox, CoinBoxNull, Leaf,
	EnermyMushroom
};
class ResourcesManager
{
private:
	
	FrkTexture* wall_2;
	FrkTexture* wall_1;
	FrkTexture* heroLeft;
	FrkTexture* heroRight;
	FrkTexture* heroJumpLeft;
	FrkTexture* heroJumpRight;
	FrkTexture* heroDriftToLeft;
	FrkTexture* heroDriftToRight;
	FrkTexture* heroFlyLeft;
	FrkTexture* heroFlyRight;
	FrkTexture* tileMap1;
	FrkTexture* coinBox;
	FrkTexture* coinBoxNull;
	FrkTexture* mushroomPower;
	FrkTexture* leaf;
	FrkTexture* E_mushroom;

public:
	static ResourcesManager* Instance;

	static ResourcesManager* GetInstance();
	void Init();
	FrkTexture* GetTexture(TextureID ID);
	ResourcesManager();
	~ResourcesManager();
	
};

