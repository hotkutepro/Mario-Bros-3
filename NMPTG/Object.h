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
#define GRAVITY -0.7f // trọng lực
#define  V_FALLDOWN -1 // tốc độ rơi khi press X
enum TYPEOBJECT{
	brick, coin, drain, land, leaf, mushroom_red, p, box, question_block, star, tarnooki, tarnooki_fly,
	tortoise, tortoise_fly, tortoise_red, tree, tree_red, tree_red_shoot, tree_shoot, bullet, mario,uprise,oneup
};
enum STATE{ ON_GROUND, ON_SPACE, FALL_DOWN, ON_FLY,OTHER };
enum DIRECT{ left,right };
enum Status
{
	MARIO, BIGMARIO, BROS
};
class Object:public Operate
{
private:
	 
protected:		
	
public:
	//xu ly phim khi keyup
	bool isUp = false;
	bool isDown = false;
	bool isLeft = false;
	bool isRight = false;
	// chuan bi cam rua
	bool ready = false;

	Box* m_hBox;
	// thoi gian co the bay
	int flyTime = 0;
	//toc do
	D3DXVECTOR2 m_hSpeed;
	Object* m_hObjectGround;//
	Object* m_hObjectLeft;
	Object* m_hObjectRight;
	D3DXVECTOR2 m_hVector;

	FrkSprite* m_hCurrentSprite;
	D3DXVECTOR2 m_hPosition;
	D3DXVECTOR2 m_hSize;//chỉ dùng cho box, land.
	STATE m_hState = ON_GROUND;
	DIRECT m_hDirect= DIRECT::left;	
	float delayNext = 0;
	int status;//chi dung cho hero, tortoise 0: bt , 1: shell, 3: reverse
	//Box* m_hBoundBox; viet ham get la duoc roi
	TYPEOBJECT type;
//dung cho quadtree
	int id;
	bool life;
	bool life_state;//dung cho question_block
	bool connect=false;//Kiểm tra có kết nối với brick ko.
	//khong dieu kien
	vector<Object*> GetStaticObject();///tra ve danh sach land, box, brick, QUESTION_BLOCK, uprise  de kiem tra khi object roi	
	//Dieu kien life = true
	vector<Object*> GetDynamicObject();//tra ve danh sach cac doi tuong di chuyen tortoise, mushroom, tarnooki, tree,	leaf	DIEU KIEN: LIFE = TRUE

	vector<Object*> GetFoodObject();//tra ve danh sach cac doi tuong dung yen va co the an duoc hoac pha huy: coin, brick, star, QUESTION_BLOCK, P, F_Mushroom DIEU KIEN: LIFE = TRUE
	// lay danh sach cac doi tuong tinh co the va cham voi object
	vector<Object*> GetStaticObjectCanCollision();
	vector<Object*> GetListTortoise();//trả về danh sách các loại tortoise, bắt đầu từ tortoise tiếp theo nằm trong danh sách

	void setCurrentSprite(FrkSprite*);
	FrkSprite* getCurrentSprite();

	virtual int getDirectWithHero(Object*);//dùng cho xet huong tree, 1: bl 2: tl 3: tr 4 br, hoac dùng xet hướng rùa, tarnooki....
	virtual void Load();	 
	virtual void DelayNext(float frame);
	virtual void Render();	
	virtual void Update(float gameTime);	
	virtual void Collision_Up();
	virtual void Collision_Down();
	virtual void Collision_Left();
	virtual void Collision_Right();
	virtual void Collision_Coin();
	virtual void Collision_Leaf();
	virtual void Collision_Mushroom();
	virtual void Collision_1up();
	virtual void IsAttacked();
	virtual void Die();
	virtual void WatchUp();//dung cho coin, leaf...xet life=true
	virtual void SetSprite();
	virtual void ResetObject();
	virtual void MoveObject();	
	virtual void FallDown(float remainingtime, float Vy);//dung cho object
//	virtual int isOnGround();//kiem tra xem object co dang dung tren ground ko, 1 neu co, 0 neu ko, -1 kxd
	virtual void EatFood();
	virtual void KillEnemy();
	virtual void RenderDebug();
	virtual void RenderBoxDebug();
	
	
	virtual Box* GetBox();
	virtual Box* GetBoxWithObject(Object* object);
	virtual Box* GetBoxTop();
	virtual Box* GetBoxAttack();
	virtual Box* GetBox_CGround();
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

