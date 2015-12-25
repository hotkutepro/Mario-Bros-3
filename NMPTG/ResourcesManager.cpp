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
	tileMap1 = _LocalContent->LoadTexture("hihi.png");		
	tileMap2 = _LocalContent->LoadTexture("hihi2.png");
}

FrkTexture* ResourcesManager::GetTexture(TextureID ID)
{
	switch (ID)
	{	
	case TileMap1:
		return this->tileMap1;	
	case TileMap2:
		return this->tileMap2;
	}
	return NULL;
}

FrkSprite* ResourcesManager::GetSprite(SpriteID id)//chú ý khi thêm mới phải sửa 84
{
	for (int i = 0; i < Count_Sprite;i++)
	{
		if (SpriteID(i) == id)
			return sprite_vector[i];
	}	
	return NULL;
}

void ResourcesManager::LoadSprite(string path)//o viết lại
{
	sprite_texture = new FrkTexture();
	sprite_texture = _LocalContent->LoadTexture("sprite1.png");//load tất cả sprite 
	sprite_vector.reserve(100);
	fstream open(path);	
	open >> Count_Sprite;
	for (int i = 0; i < Count_Sprite; i++)
	{
		FrkSprite* fs = new FrkSprite();
		open >> fs->_Count;
		open >> fs->_X;
		open>> fs->_Y;
		open >> fs->_Width;
		open >> fs->_Height;
		fs->_Image = sprite_texture;
		fs->_Index = 0;
		sprite_vector.push_back(fs);
	}


}
