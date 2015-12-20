#pragma once
#include <d3dx9math.h>
#include "FrkContent.h"
#include"QNode.h"
#include<map>
#include"FrkSprite.h"
#include"Box.h"
#include"Operate.h"
#include <list>
#include <vector>
#define Range_x 10// dung cho ham lay danh sach cac doi tuong cach object mot khoang rang_x theo chieu ngang
#define Range_y 10// dung cho ham lay danh sach cac doi tuong cach object mot khoang rang_y theo chieu doc
#define GRAVITY -0.5f
enum TYPEOBJECT{
	brick, coin, drain, land, leaf, mushroom_red, p, box, question_block, star, tarnooki, tarnooki_fly,
	tortoise, tortoise_fly, tortoise_red, tree, tree_red, tree_red_shoot, tree_shoot,bullet
};
enum STATE{ ON_GROUND, ON_SPACE, FALL_DOWN, ON_FLY };
enum DIRECT{ left,right };
enum Status
{
	MARIO, BIGMARIO, BROS
};
class Object:public Operate
{
protected:		

public:
	//toc do
	D3DXVECTOR2 m_hSpeed;
	Object* m_hObjectGround;//
	Object* m_hObjectLeft;
	Object* m_hObjectRight;

	FrkSprite* m_hCurrentSprite;
	D3DXVECTOR2 m_hPosition;
	D3DXVECTOR2 m_hSize;//chỉ dùng cho box, land.
	STATE m_hState = ON_GROUND;
	DIRECT m_hDirect= DIRECT::left;
	Box* m_hBox;
	float delayNext = 0;
	int status;//chi dung cho hero
	//Box* m_hBoundBox; viet ham get la duoc roi
	TYPEOBJECT type;
//dung cho quadtree
	int id;
	bool life;
	bool life_state;//dung cho question_block
	bool connect=false;//Kiểm tra có kết nối với brick ko.
	//khong dieu kien
	vector<Object*> GetStaticObject();///tra ve danh sach land, box, brick, QUESTION_BLOCK  de kiem tra khi object roi
	list<Object*> GetStaticObject_vx();//tra ve danh sach object khi di chuyen doi tuong qua trai phai land, brick, QUESTION_BLOCK 
	//Dieu kien life = true
	vector<Object*> GetDynamicObject();//tra ve danh sach cac doi tuong di chuyen tortoise, mushroom, tarnooki, tree,	leaf	DIEU KIEN: LIFE = TRUE

	vector<Object*> GetFoodObject();//tra ve danh sach cac doi tuong dung yen va co the an duoc hoac pha huy: coin, brick, star, QUESTION_BLOCK, P DIEU KIEN: LIFE = TRUE
	// lay danh sach cac doi tuong tinh co the va cham voi object
	vector<Object*> GetStaticObjectCanCollision();


	void setCurrentSprite(FrkSprite*);
	FrkSprite* getCurrentSprite();

	virtual int getDirectWithHero(Object*);//dùng cho xet huong tree, 1: bl 2: tl 3: tr 4 br, hoac dùng xet hướng rùa, tarnooki....
	virtual void Load();	 
	virtual void DelayNext(float gameTime, float frame);
	virtual void Render();	
	virtual void Update(float gameTime);	
	virtual void Die();
	virtual void WatchUp();//dung cho coin, leaf...xet life=true
	virtual void Move();
	virtual void MoveObject();	
	virtual void FallDown(float remainingtime);//dung cho object
	virtual int isOnGround();//kiem tra xem object co dang dung tren ground ko, 1 neu co, 0 neu ko, -1 kxd
	virtual void EatFood();
	virtual void KillEnemy();
	virtual void RenderDebug();
	virtual void RenderBoxDebug();
	virtual void RenderBoundBox();
	virtual Box* GetBox();
	virtual Box* GetBoundBox();
	virtual Box* GetBox_CGround();//va de xet va cham voi mat dat
	virtual Box* GetBox_CLeft();
	virtual Box* GetBox_CRight();	
	void Jump();
	void SetPosition(int x, int y);
	D3DXVECTOR2 GetPosition();
	Object(D3DXVECTOR2 pos, D3DXVECTOR2 speed);
	Object(int _id,D3DXVECTOR2 pos, TYPEOBJECT _type);
	Object(TYPEOBJECT _type);
	Object();
	~Object();
};

