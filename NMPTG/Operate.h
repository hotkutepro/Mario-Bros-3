#pragma once
#include<d3dx9.h>
class Operate
{
public:
	void GravityofEarth(D3DXVECTOR2 &m_hPosition, float m_hgravity,float gametime);
	void Goleft(D3DXVECTOR2 &m_hPosition, D3DXVECTOR2 m_hSpeed);
	void Goright(D3DXVECTOR2 &m_hPosition, D3DXVECTOR2 m_hSpeed);
	void JumpLeft(D3DXVECTOR2 &m_hPosition, D3DXVECTOR2 m_hSpeed);
	void JumRight(D3DXVECTOR2 &m_hPosition, D3DXVECTOR2 m_hSpeed);
	void Stop();
	Operate();
	~Operate();
};

