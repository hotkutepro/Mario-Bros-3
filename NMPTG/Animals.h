#pragma once
#include "Object.h"

#include "FrkSprite.h"
class Animals : public Object
{
private:
	D3DXVECTOR2 m_hPosition;	
public:
	FrkSprite* m_hMarioLeft;
	FrkSprite* m_hMarioRight;
	FrkSprite* m_hRenderMario;
	Animals();
	~Animals();
	void Load();
	void Render();
	void Update(float gameTime);
	void SetSite(int x,int y);
	D3DXVECTOR2 getPosition();
	
};

