﻿#pragma once
#include"d3dx9.h"
#define Center_W  160
#define Center_H  120
#include "FrkShareControl.h"

class FrkCamera
{
private: 
	 float m_hMaxWidth, m_hMaxHeight;
	D3DXMATRIX MatrixI;//matrix bậc 4
	D3DXMATRIX MatrixTran;
	D3DVIEWPORT9 viewport;
	
public:
	static float m_hVpx, m_hVpy;
	FrkCamera(float map_Width, float map_height);
	void Update(D3DXVECTOR2 target);
	D3DXMATRIX* GetTransformMatrix();
	FrkCamera();
	~FrkCamera();
};

