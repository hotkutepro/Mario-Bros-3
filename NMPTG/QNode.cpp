#include "QNode.h"
#include"Object.h"
#include"Brick.h"
#include "F_Coin.h"
#include "C_Box.h"
#include "C_Drain.h"
#include "C_Land.h"
#include "C_Question_Block.h"
#include "E_FlyMushroom.h"
#include "E_FlyTortoise.h"
#include "E_Mushroom.h"
#include "E_Plant.h"
#include "E_Plant_Gun.h"
#include "E_Plant_Red.h"
#include "E_Plant_Red_Gun.h"
#include "E_Tarnooki.h"
#include "E_Tarnooki_Fly.h"
#include "E_Tortoise.h"
#include "E_Tortoise_Red.h"
#include "F_Leaf.h"
#include "F_Mushroom.h"
#include "F_P.h"
#include "F_Star.h"



sId QNode::s_IdObjectInViewPort;
QNode::QNode()
{
}

QNode::QNode(int _id, RECT _rect)
{
	nodeId = _id;
	Rect = _rect;
}


QNode::~QNode()
{
}

void QNode::LoadQNode(string path)
{
	fstream open(path);
	int count_Node = 0;
	open >> count_Node;
	for (int i = 0; i < count_Node; i++){
		QNode* tmp=new QNode;
		open >> tmp->nodeId;
		open >> tmp->Rect.left;
		open >> tmp->Rect.top;
		open >> tmp->Rect.right;
		open >> tmp->Rect.bottom;
		m_QNode.insert(pair<int, QNode*>(tmp->nodeId, tmp));
	}
	
}

void QNode::Connect()
{	
	mapQNode::iterator it;
	mapQNode::iterator tmp_it;
	for (it = m_QNode.begin(); it != m_QNode.end(); it++){
		int j = it->first * 10 + 1;
		tmp_it = m_QNode.find(j);
		if (tmp_it != m_QNode.end())
		{
			it->second->tl = m_QNode[j];
			it->second->tr = m_QNode[j + 1];
			it->second->bl = m_QNode[j + 2];
			it->second->br = m_QNode[j + 3];			
		}
	}
}
void QNode::LoadObjects(string path)//Viet lai
{
	int count;
	typeObject type;
	string stype;
	fstream open(path);
	string line;
	typeObject typeO[19] = { brick, coin, drain, land, leaf, mushroom_red, p,box , question_block, star, tarnooki, 
		tarnooki_fly, tortoise, tortoise_fly, tortoise_red, tree, tree_red, tree_red_shoot, tree_shoot };
	for (int i = 0; i < 18; i++)
	{
		open >> stype;
		open >> count;
		for (int j = 0; j < count; j++)
		{
			Object *tmp;			
			switch (i)
			{
			case 0:
				tmp = new Brick();
				break;
			case 1:
				tmp = new F_Coin();
				break;
			case 2:
				tmp = new C_Drain();
				break;
			case 3:
				tmp = new C_Land();
				break;
			case 4:
				tmp = new F_Leaf();
				break;
			case 5:
				tmp = new E_Mushroom();
				break;
			case 6:
				tmp = new F_P();
				break;
			case 7:
				tmp = new C_Box();
				break;
			case 8:
				tmp = new C_Question_Block();
				break;
			case 9:
				tmp = new F_Star();
				break;
			case 10:
				tmp = new E_Tarnooki();
				break;
			case 11:
				tmp = new E_Tarnooki_Fly();
				break;
			case 12:
				tmp = new E_Tortoise();
				break;
			case 13:
				tmp = new E_FlyTortoise();
				break;
			case 14:
				tmp = new E_Tortoise_Red();
				break;
			case 15:
				tmp = new E_Plant();
				break;
			case 16:
				tmp = new E_Plant_Red();
				break;
			case 17:
				tmp = new E_Plant_Red_Gun();
				break;
			case 18:
				tmp = new E_Plant_Gun();
				break;			
			}
			open >> tmp->id;
			D3DXVECTOR2 pos;
			open >> pos.x;
			open >> pos.y;
			tmp->SetPosition(pos.x, pos.y);
			tmp->type = typeO[i];
			m_Objects.insert(pair<int, Object*>(tmp->id, tmp));
		}				
	}
}
void QNode::LoadObjects2(string path)
{
	int count;
	typeObject type;
	string stype;
	fstream open(path);
	string line;
	typeObject typeO[18] = { brick, coin, drain, land, leaf, mushroom_red, p, question_block, star, tarnooki, tarnooki_fly, tortoise, tortoise_fly, tortoise_red, tree, tree_red, tree_red_shoot, tree_shoot };
	for (int i = 0; i < 18; i++)
	{
		open >> stype;
		open >> count;
		for (int j = 0; j < count;j++)
		{
			Object * tmp=new Object();
			open >> tmp->id;						
			D3DXVECTOR2 pos;
			open >> pos.x;
			open >> pos.y;	
			tmp->SetPosition(pos.x, pos.y);
			tmp->type = typeO[i];			
			m_Objects.insert(pair<int, Object*>(tmp->id, tmp));
		}
	}
}

void QNode::InsertObject(string path)
{
	fstream open(path);
	int n;//số node lá có số đối tượng lớn hơn 0
	int id_Node; //id của node
	int count;//số object trong node
	open >> n;
	int id_Object;
	for (int i = 0; i < n; i++){
		open >> id_Node;
		open >> count;
		for (int j = 0; j < count; j++){
			open >> id_Object;			
			//objects.insert(&m_Objects[id_Object]);
			m_QNode[id_Node]->objects.push_back(m_Objects[id_Object]);

		}
	}
}

void QNode::getIdObjectInViewPort(RECT _rectViewport, QNode* node)
{
	if (node->nodeId==0||node->nodeId==NULL)
		s_IdObjectInViewPort.clear();

	if (!node->tl)
	{
		if (Intersect(_rectViewport,node->Rect))
		{
			if (!node->m_Objects.empty())
			{
				mapObject::iterator it;
				for (it = m_Objects.begin(); it != m_Objects.end(); it++);
					s_IdObjectInViewPort.insert(it->second->id);;
			}
		}
	}
	else
	{
		getIdObjectInViewPort(_rectViewport, node->tl);
		getIdObjectInViewPort(_rectViewport, node->tr);
		getIdObjectInViewPort(_rectViewport, node->bl);
		getIdObjectInViewPort(_rectViewport, node->br);
	}
}

bool QNode::IsRootNode()
{
	if (tl==NULL)
		return false;
	return true;
}

bool QNode::Intersect(RECT _r1, RECT _r2)
{	
	return !(_r1.right<_r2.left||_r1.left>_r2.right||_r1.bottom<_r2.top||_r1.top<_r2.bottom );
}

