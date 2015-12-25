#pragma once
#include "FrkContent.h"
#include "FrkGame.h"
#include "FrkSprite.h"
enum SpriteID
{
	BigMarioDriftToLeft, BigMarioDriftToRight, BigMarioFallLeft, BigMarioFallRight, BigMarioHugLeft, BigMarioHugRight, BigMarioJumpLeft, 
	BigMarioJumpRight, BigMarioKickLeft, BigMarioKickRight, BigMarioLeft, BigMarioRight, BigMarioRunLeft, BigMarioRunRight, BigMarioSitLeft,
	BigMarioSitRight, BigMarioSuperJumpLeft, BigMarioSuperJumpRight, Brick, BrosBaleLeft, BrosBaleRight, BrosDriftToLeft, BrosDriftToRight,
	BrosFallLeft, BrosFallRight, BrosFlyLeft, BrosFlyRight, BrosHugLeft, BrosHugRight, BrosJumpLeft, BrosJumpRight, BrosKickLeft,
	BrosKickRight, BrosLeft, BrosRight, BrosRunLeft, BrosRunRight, BrosSitLeft, BrosSitRight, Bull, Cloud, Coin, CoinBox, CoinBoxNull,
	E_FlyMushroom, E_FlyTortoiseGreenLeft, E_FlyTortoiseGreenRight, E_FlyTortoiseRedLeft, E_FlyTortoiseRedRight, E_Mushroom, E_MushroomDeath,
	E_MushroomRed, E_MushroomRedDeath, E_TortoiseGreenLeft, E_TortoiseGreenRight, E_TortoiseGreenWakeUp, E_TortoiseRedRight, 
	E_TortoiseRedWakeUp, E_TortoiseshellGreenLeft, E_TortoiseshellGreenLeftReverse, E_TortoiseshellGreenRight, E_TortoiseshellGreenRightReverse,
	E_TortoiseshellRedLeft, E_TortoiseshellRedLeftReverse, E_TortoiseshellRedRight, E_TortoiseshellRedRightReverse, E_TurtoiseRedLeft, Endgame,
	F_MushroomPower, KickP, Leaf, MarioDeath, MarioDriftToLeft, MarioDriftToRight, MarioHugLeft, MarioHugRight, MarioJumpLeft, MarioJumpRight,
	MarioKickLeft, MarioKickRight, MarioLeft, MarioRight, MarioRunLeft, MarioRunRight, MarioSuperJumpLeft, MarioSuperJumpRight, One_up, P,
	Strike, Tree, Tree_left, Tree_red_left_down, Tree_red_left_up, Tree_red_right_down, Tree_red_right_up, Tree_right, Wood_1, ZPipe_md,
	ZPipe_sm,
};
enum TextureID
{
	TileMap1,TileMap2
};
class ResourcesManager
{
private:
		
	vector<FrkSprite*> sprite_vector;
	FrkTexture* tileMap1;
	FrkTexture* tileMap2;
	FrkTexture* sprite_texture;
public:
	int Count_Sprite;
	static ResourcesManager* Instance;
	static ResourcesManager* GetInstance();
	void LoadSprite(string p);
	void Init();
	FrkTexture* GetTexture(TextureID ID);
	FrkSprite *GetSprite(SpriteID id);
	ResourcesManager();
	~ResourcesManager();
	
};

