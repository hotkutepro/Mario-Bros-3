﻿#include "FrkCamera.h"

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
	/*m_hVpx = target.x - Center_W;	
	m_hVpy = target.y + Center_H;
	
	if (m_hVpx < 0)
		m_hVpx = 0;	
	if (m_hVpx+800>=m_hMaxWidth)//800 là chiều dài của cửa sổ
		m_hVpx = m_hMaxWidth-800;			
	
	if (m_hVpy> m_hMaxHeight)
		m_hVpy = m_hMaxHeight;
	if (m_hVpy<=480)
		m_hVpy =480;//480 là chiều cao của cửa sổ			*/	
	m_hVpx = (target.x)*Zoom - Center_W;
	m_hVpy = (target.y)*Zoom + Center_H;
	if (m_hVpx < 0)
		m_hVpx = 0;
	if (m_hVpx + 800 >= m_hMaxWidth*Zoom)//800 là chiều dài của cửa sổ
		m_hVpx = m_hMaxWidth*Zoom - 800;

	if (m_hVpy > m_hMaxHeight*Zoom)
		m_hVpy = m_hMaxHeight*Zoom;
	if (m_hVpy <= 480)
		m_hVpy = 480;//480 là chiều cao của cửa sổ			*/
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
