#pragma once
#include <Windows.h>
#include <d3dx9.h>
class Box
{
	
public:
	RECT position;
	D3DXVECTOR2 v;
	Box(RECT _p,D3DXVECTOR2 _v);
	Box();
	~Box(void);
	int getWidth(){return position.right - position.left;}
	int getHeight(){return position.bottom - position.top;}
};

