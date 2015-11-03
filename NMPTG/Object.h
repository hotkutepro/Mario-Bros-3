#pragma once
#include <d3dx9math.h>
#include "FrkContent.h"


class Object
{
protected:
	D3DXVECTOR2 m_hPosition;
	float m_hAcceleration;
	D3DXVECTOR2 m_hSpeed;
public:
	virtual void Load(FrkContent*);
	virtual void Render();
	virtual void Update(float gameTime);
	void SetSite(int x, int y);
	D3DXVECTOR2 GetPosition();
	Object(D3DXVECTOR2 pos, D3DXVECTOR2 speed);
	Object();
	~Object();
};

