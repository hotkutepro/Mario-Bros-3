#pragma once
#include"Object.h"
#include"FrkShareControl.h"
#include<list>
#include<vector>
#include<set>
using namespace std;
typedef set<int> sId;
typedef vector<Object*>v_Objects;
class QNode
{
public:	
	v_Objects objects;//danh sách objects mà QNode này chứa
	mapQNode m_QNode;//danh sách chứa tất cả các node
	static mapObject m_Objects;//danh sách chứa tất cả các object	
	static mapObject m_Object_Dynamic;//danh sach rua, tarnooki trong game
	QNode *tl, *tr, *bl, *br;//
	int nodeId;
	
    //set<int> s_IdObjectInViewPort;//chứa id của các object trong viewport
	static sId s_IdObjectInViewPort;//danh sách id object của các node có va chạm với viewport
	RECT Rect;
	bool Intersect(RECT _r1, RECT _r2);
	bool IsRootNode(QNode* node);
	bool IsLeafNode();
	void LoadQNode(string path);//load danh sách QNode
	void Connect();//liên kết, tìm con cho node
	void LoadObjects(string path);//load danh sách Object	
	void LoadObjects_Dynamic(string path);
	void InsertObject(string path);	
	void getIdObjectInViewPort(RECT _rectViewport, QNode* node);
	QNode(int _id, RECT  _rect);
	QNode();
	~QNode();
};
