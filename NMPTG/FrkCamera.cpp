﻿#include "FrkCamera.h"
#include "FrkShareControl.h"
FrkCamera::FrkCamera()
{
}

FrkCamera::FrkCamera(float map_Width, float map_height)
{
	this->m_hMaxWidth = map_Width;
	this->m_hMaxHeight = map_height;
	m_hVpx = m_hVpy = 0;
	D3DXMatrixIdentity(&MatrixI);
	this->MatrixI._22 = -1;	
}


FrkCamera::~FrkCamera()
{
}

void FrkCamera::Update(D3DXVECTOR2 target)
{
	if (_LocalHero->m_hPosition.y>520||_LocalHero->m_hState==ON_FLY){
	m_hVpx = Zoom *target.x- Center_W;
	m_hVpy = (target.y)*Zoom + Center_H;
	if (m_hVpx < 0)
		m_hVpx = 0;
	if (m_hVpx + 320 >= m_hMaxWidth*Zoom)//800 là chiều dài của cửa sổ
		m_hVpx = m_hMaxWidth*Zoom - 320;

	if (m_hVpy > m_hMaxHeight*Zoom-16)
		m_hVpy = m_hMaxHeight*Zoom-16;
	if (m_hVpy <= 240)
		m_hVpy = 240;//480 là chiều cao của cửa sổ			*/	
	}
	else{
		m_hVpx = Zoom *target.x - Center_W;
		m_hVpy = 480;
		if (m_hVpx < 0)
			m_hVpx = 0;
		if (m_hVpx + 320 >= m_hMaxWidth*Zoom)//800 là chiều dài của cửa sổ
			m_hVpx = m_hMaxWidth*Zoom - 320;		
		if (m_hVpy <= 240)
			m_hVpy = 240;//480 là chiều cao của cửa sổ			*/
	}
	R_Viewport.left = m_hVpx;
	R_Viewport.right = m_hVpx + 320;//320;
	R_Viewport.top = 720 - m_hVpy;
	R_Viewport.bottom = R_Viewport.top + 240;//240;	
}

D3DXMATRIX* FrkCamera::GetTransformMatrix()
{
	D3DXMATRIX transformmatrix;
	D3DXMatrixTranslation(&transformmatrix, -m_hVpx, m_hVpy, 0);
	D3DXMatrixMultiply(&MatrixTran, &MatrixI, &transformmatrix);	
	D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale, Zoom, Zoom, 1.0f);
	D3DXMatrixMultiply(&MatrixTran, &matScale, &MatrixTran);
	
	return &MatrixTran;
}
