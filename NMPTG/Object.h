#pragma once
#include <d3dx9math.h>
#include "FrkContent.h"
#include"QNode.h"
#include<map>
#include"FrkSprite.h"
#include"Box.h"
#include"Operate.h"
#include <list>
#define GRAVITY -0.5f
enum TYPEOBJECT{
	brick, coin, drain, land, leaf, mushroom_red, p, box, question_block, star, tarnooki, tarnooki_fly,
	tortoise, tortoise_fly, tortoise_red, tree, tree_red, tree_red_shoot, tree_shoot,bullet
};
enum STATE{ON_GROUND,ON_SPACE,ON_FLY};
enum DIRECT{left,right};
class Object:public Operate
{
protected:		

public:
	//toc do
	D3DXVECTOR2 m_hSpeed;
	Object* m_hObjectGround;//
	FrkSprite* m_hCurrentSprite;
	D3DXVECTOR2 m_hPosition;
	D3DXVECTOR2 m_hSize;//chỉ dùng cho box, land.
	STATE m_hState = ON_GROUND;
	DIRECT m_hDirect;
	Box* m_hBox;
	Box* m_hBox_Colis;
	TYPEOBJECT type;
//dung cho quadtree
	int id;
	bool life=true;
	bool connect=false;//Kiểm tra có kết nối với brick ko.
	list<Object*> GetStaticObject();
	//
	void setCurrentSprite(FrkSprite*);
	FrkSprite* getCurrentSprite();
	virtual void Load();
	virtual void Render();
	virtual void UpdateBox(float gameTime);
	virtual void Update(float gameTime);
	virtual void Tortoise_Shell();
	virtual void Die();
	virtual void RenderDebug();
	virtual void RenderBoxDebug();
	virtual Box GetBox();
	void FallDown(float remainingtime);
	void Jump();
	void SetPosition(int x, int y);
	D3DXVECTOR2 GetPosition();
	Object(D3DXVECTOR2 pos, D3DXVECTOR2 speed);
	Object(int _id,D3DXVECTOR2 pos, TYPEOBJECT _type);
	Object(TYPEOBJECT _type);
	Object();
	~Object();
};

