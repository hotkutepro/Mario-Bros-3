#pragma once
#include<d3dx9.h>
#include<d3d9.h>
#include"FrkTexture.h"
class FrkSprite
{
public:
public:
	int _Index;
	int _Width;//kích thước của một frame
	int _Height;
	int _Count;//số sprite trong một texture 
	int _SpriteperRow;
	FrkTexture* _Image;

	void Next();
	void Reset();
	void Set(int index);		
	void Render(D3DXVECTOR2 position);
	FrkSprite(FrkSprite* sprite);
	FrkSprite(FrkTexture* img,int count, int spriteperrow);
	FrkSprite();
	~FrkSprite();
};

