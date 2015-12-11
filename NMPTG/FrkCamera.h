﻿#pragma once
#include"d3dx9.h"
#define Center_W  120
#define Center_H  160
#include "FrkShareControl.h"

class FrkCamera
{
private: 
	float m_hVpx, m_hVpy, m_hMaxWidth, m_hMaxHeight;
	D3DXMATRIX MatrixI;//matrix bậc 4
	D3DXMATRIX MatrixTran;
	D3DVIEWPORT9 viewport;
	
public:
	FrkCamera(float map_Width, float map_height);
	void Update(D3DXVECTOR2 target);
	D3DXMATRIX* GetTransformMatrix();
	FrkCamera();
	~FrkCamera();
};

