#pragma once
#include "FrkContent.h"
#include "FrkGame.h"
#include "FrkSprite.h"
enum SpriteID
{
	a, BigMarioDriftToLeft, BigMarioDriftToRight, BigMarioFallLeft, BigMarioFallRight, BigMarioHugLeft, 
	BigMarioHugRight, BigMarioJumpLeft, BigMarioJumpRight, BigMarioKickLeft, BigMarioKickRight,
	BigMarioLeft, BigMarioRight, BigMarioRunLeft, BigMarioRunRight, BigMarioSitLeft, BigMarioSitRight, 
	BigMarioSuperJumpLeft, BigMarioSuperJumpRight, Brick, BrosBaleLeft, BrosBaleRight, BrosDriftToLeft,
	BrosDriftToRight, BrosFallLeft, BrosFallRight, BrosFlyLeft, BrosFlyRight, BrosHugLeft, BrosHugRight,
	BrosJumpLeft, BrosJumpRight, BrosKickLeft, BrosKickRight, BrosLeft, BrosRight, BrosRunLeft, BrosRunRight, 
	BrosSitLeft, BrosSitRight, cloud, Coin, CoinBox, CoinBoxNull, E_FlyMushroom, E_FlyMushroom1, E_FlyTortoiseGreenLeft, 
	E_FlyTortoiseGreenRight, E_FlyTortoiseRedLeft, E_FlyTortoiseRedRight, E_Mushroom, E_MushroomDeath, E_MushroomRed, 
	E_MushroomRedDeath, E_TortoiseGreenLeft, E_TortoiseGreenRight, E_TortoiseRedRight, E_TortoiseshellGreenLeft,
	E_TortoiseshellGreenRight, E_TortoiseshellRedLeft, E_TortoiseshellRedRight, E_TurtoiseRedLeft, F_MushroomPower, 
	KickP, Leaf, MarioDeath, MarioDriftToLeft, MarioDriftToRight, MarioHugLeft, MarioHugRight, MarioJumpLeft,
	MarioJumpRight, MarioKickLeft, MarioKickRight, MarioLeft, MarioRight, MarioRunLeft, MarioRunRight,
	MarioSuperJumpLeft, MarioSuperJumpRight, P, Strike, up, Wood_1,
};
enum TextureID
{
	TileMap1
};
class ResourcesManager
{
private:
	
	FrkTexture* wall_2;
	FrkTexture* wall_1;	
	vector<FrkSprite*> sprite_vector;
	FrkTexture* tileMap1;
	FrkTexture* sprite_texture;
public:
	static ResourcesManager* Instance;

	static ResourcesManager* GetInstance();
	void LoadSprite(string p);
	void Init();
	FrkTexture* GetTexture(TextureID ID);
	FrkSprite *GetSprite(SpriteID id);
	ResourcesManager();
	~ResourcesManager();
	
};

