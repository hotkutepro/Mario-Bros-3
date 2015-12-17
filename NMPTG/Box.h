#pragma once
#include <Windows.h>
#include <d3dx9.h>
class Box
{
public:
	D3DXVECTOR2 _position;
	D3DXVECTOR2 _v;
	D3DXVECTOR2 _size;
	D3DXVECTOR2 getCenter();
	RECT getRect();
	float getRight();
	float getBottom();
	float getLeft();
	float getTop();
	D3DXVECTOR2 getCenterPos();
	Box();
	Box(Box* box);
	Box(D3DXVECTOR2 position, D3DXVECTOR2 size, D3DXVECTOR2 v);
	~Box(void);
};

