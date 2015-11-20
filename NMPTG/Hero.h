#pragma once
#include"Object.h"
#include "FrkSprite.h"
#include"Box.h"
class Hero:public Object
{
private:
	FrkSprite* m_hCurrentSprite;
public:
	Box* m_hBox;
	FrkSprite* m_hMarioLeft;
	FrkSprite* m_hMarioRight;
	Box* getBox();
	void setCurrentSprite(FrkSprite*);
	FrkSprite* getCurrentSprite();
	void Load();
	void Render();
	void onkeydown();///
	void Update(float gameTime);	
	Hero();
	Hero(D3DXVECTOR2 pos, D3DXVECTOR2 speed);
	~Hero();
};

