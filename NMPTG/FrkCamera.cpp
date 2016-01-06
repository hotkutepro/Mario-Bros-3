#include "FrkCamera.h"
#include "FrkShareControl.h"

float FrkCamera::m_hVpx;
float FrkCamera::m_hVpy;
FrkCamera::FrkCamera()
{
}

FrkCamera::FrkCamera(float map_Width, float map_height)
{
	this->m_hMaxWidth = map_Width;
	this->m_hMaxHeight = map_height;
	m_hVpx = 0; 
	m_hVpy = 720;
	D3DXMatrixIdentity(&MatrixI);
	this->MatrixI._22 = -1;
}


FrkCamera::~FrkCamera()
{
}

void FrkCamera::Update(D3DXVECTOR2 target)
{	
	m_hVpx = Zoom *target.x - Center_W;	
	if (m_hVpx < 0)
		m_hVpx = 0;
	if (m_hVpx + 320 >= m_hMaxWidth*Zoom)
		m_hVpx = m_hMaxWidth*Zoom - 320;
	
	if (_LocalHero->m_hPosition.y <240)
	{
		m_hVpy = 240;		
	}else
	if (_LocalHero->m_hPosition.y>=464)
	{
		m_hVpy = 688;		
	}else
	if (_LocalHero->m_hPosition.y >240)
	{
		m_hVpy = 448;		
	}				
	R_Viewport.left = m_hVpx;
	R_Viewport.right = m_hVpx + 320;//320;
	R_Viewport.top = 688-m_hVpy;//720-mhvpy
	R_Viewport.bottom = m_hVpy+100;//240;	
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
