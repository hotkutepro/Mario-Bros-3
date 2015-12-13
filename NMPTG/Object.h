#pragma once
#include <d3dx9math.h>
#include "FrkContent.h"
#include"QNode.h"
#include<map>
#include"FrkSprite.h"
#include"Box.h"
#include"Operate.h"
enum typeObject{
	brick, coin, drain, land, leaf, mushroom_red, p, box, question_block, star, tarnooki, tarnooki_fly,
	tortoise, tortoise_fly, tortoise_red, tree, tree_red, tree_red_shoot, tree_shoot,bullet
};
enum state{ON_GROUND,ON_SPACE,ON_FLY};
class Object:public Operate
{
protected:		

public:	
	int v = 0.05;	
	float m_hAcceleration;
	float m_hgravity = 0.98f;
	D3DXVECTOR2 m_hSpeed;
	FrkSprite* m_hCurrentSprite;
	D3DXVECTOR2 m_hPosition;
	Box* box;
	typeObject type;
	int id;
	bool life=true;
	bool connect=false;//Kiểm tra có kết nối với brick ko.
	void setCurrentSprite(FrkSprite*);
	FrkSprite* getCurrentSprite();
	virtual void Load();
	virtual void Render();
	virtual void UpdateBox(float gameTime);
	virtual void Update(float gameTime);
	virtual void Tortoise_Shell();
	virtual void Die();
	void SetPosition(int x, int y);
	D3DXVECTOR2 GetPosition();
	Object(D3DXVECTOR2 pos, D3DXVECTOR2 speed);
	Object(int _id,D3DXVECTOR2 pos, typeObject _type);
	Object(typeObject _type);
	Object();
	~Object();
};

