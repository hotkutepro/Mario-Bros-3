#pragma once
#include<d3dx9.h>
#include<d3d9.h>
#include"FrkTexture.h"
class FrkSprite
{
public:
public:
	int _X;//vị trí của sprite trên bức ảnh lớn
	int _Y;//
	int _Index=0;
	int _Width;//kích thước của một frame con
	int _Height;
	int _Count;//số sprite trong một texture 
	int _SpriteperRow;
	FrkTexture* _Image;

	void Next();
	void Reset();
	void Set(int index);		
	void Render2(D3DXVECTOR2 position);
	void Render(D3DXVECTOR2 position);
	bool IsSprite(FrkSprite* compare);
	FrkSprite(FrkSprite* sprite);
	FrkSprite(FrkTexture* img,int count, int spriteperrow);
	FrkSprite();
	~FrkSprite();
};

