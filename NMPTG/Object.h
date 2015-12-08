#pragma once
#include <d3dx9math.h>
#include "FrkContent.h"
#include"QNode.h"
#include<map>
#include"FrkSprite.h"
#include"Box.h"
enum typeObject{ brick, coin, drain, land, leaf, mushroom_red, p,box, question_block, star, tarnooki, tarnooki_fly,
	tortoise, tortoise_fly, tortoise_red, tree, tree_red, tree_red_shoot, tree_shoot };
class Object
{
protected:
	D3DXVECTOR2 m_hPosition;
	float m_hAcceleration;
	D3DXVECTOR2 m_hSpeed;
	FrkSprite* m_hCurrentSprite;

public:	
	Box* box;
	typeObject type;
	int id;
	void setCurrentSprite(FrkSprite*);
	FrkSprite* getCurrentSprite();
	virtual void Load();
	virtual void Render();
	virtual void Update(float gameTime);
	void SetPosition(int x, int y);
	D3DXVECTOR2 GetPosition();
	Object(D3DXVECTOR2 pos, D3DXVECTOR2 speed);
	Object(int _id,D3DXVECTOR2 pos, typeObject _type);
	Object(typeObject _type);
	Object();
	~Object();
};

