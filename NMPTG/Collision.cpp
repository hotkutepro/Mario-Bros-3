#include "Collision.h"
#define TIME 1



Collision::Collision(void)
{
}


Collision::~Collision(void)
{
}

bool Collision::AABBCheck(Box b1, Box b2)
{
	return !(b1.position.right < b2.position.left || b1.position.bottom < b2.position.top ||b2.position.right < b1.position.left || b2.position.bottom < b1.position.top);
}

Box* Collision::GetBoardPhaseBox(Box* box)
{
	Box* result = new Box(RECT(),D3DXVECTOR2());
	result->position.left = box->v.x > 0 ? box->position.left : box->position.left + box->v.x;
	result->position.top = box->v.y > 0 ? box->position.top : box->position.top + box->v.y;
	result->position.right = box->position.right + abs(box->v.x);
	result->position.bottom = box->position.bottom + abs(box->v.y);
	return result;
}

float Collision::SweptAABB(Box* b1, Box* b2,float &x,float &y)
{
	float dxEntry,dyEntry;//khoang cach gan nhat
	float dxExit,dyExit;//khoang cach xa nhat
	float txEntry,txExit;
	float tyEntry,tyExit;
	float EntryTime,ExitTime;//thoi gian bắt đâu, thoi gian ket thuc
	if(b1->v.x > 0.0f)//chi quan tam toi cac b2 o ben phai
	{

		dxEntry = b2->position.left - b1->position.right;//chi quan quan tam canh trai cua b2
		dxExit = b2->position.right - b1->position.left;//chỉ quan tam toi canh phai
	}
	else//di chuyen qua trai => chi can quan tan cac b2 nam ben trai
	{
		dxEntry = (b2->position.right) - b1->position.left;//quan tam toi canh phai b2
		dxExit = b2->position.left - b1->position.right;//chi quan tam toi canh trai b2
	}

	if(b1->v.y > 0.0f)
	{
		dyEntry = b2->position.top - b1->position.bottom;
		dyExit = b2->position.bottom - b1->position.top;
	}
	else
	{
		dyEntry = b2->position.bottom - b1->position.top;
		dyExit = b2->position.top - b1->position.bottom;
	}

	//ta can lay Max cua EntryTime va Min cua ExitTime => cong thuc tinh thoi gian
	if(b1->v.x == 0.0f)
	{
		txEntry = -std::numeric_limits<float>::infinity();
		txExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		txEntry = dxEntry / (b1->v.x * TIME);
		txExit = dxExit / (b1->v.x * TIME);
	}

	if(b1->v.y == 0.0f)
	{
		tyEntry = -std::numeric_limits<float>::infinity();
		tyExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		tyEntry = dyEntry / (b1->v.y * TIME);
		tyExit = dyExit / (b1->v.y * TIME);
	}


	EntryTime = max(txEntry,tyEntry);
	ExitTime = min(txExit,tyExit);
	
	bool c1 = EntryTime > ExitTime ;
	bool c2 = txEntry < 0.0f && tyEntry < 0.0f;
	
	bool c3 = tyEntry > 1.0f;
	bool c4 =	txEntry > 1.0f;	
	if(c3)
	{
		int x = 5;
	}
	if(c1 || c2 || c3 || c4)
	{
		x = 0; y = 0; 
		return 1.0f;
	}
	//nghi ngo co va cham
	if(txEntry < 0.0f)
	{
		if(b1->position.right < b2->position.left || b2->position.right < b1->position.left)
		{
			x = 0; y = 0; 
			return 1.0f;
		}
	}
	//nghi ngo co va cham
	if(tyEntry < 0.0f)
	{
		if(b1->position.bottom < b2->position.top || b2->position.bottom < b1->position.top)
		{
			x = 0; y = 0; 
			return 1.0f;
		}
	}

	//xay ra va cham
	if(txEntry > tyEntry)
	{
		if (dxEntry < 0)
		{
			x = 1.0f; y = 0.0f;
		}
		else
		{
			x = -1.0f; y = 0.0f;
		}

	}
	else
	{
		if(dyEntry < 0)
		{
			x = 0.0f; y = 1.0f;
		}
		else
		{
			x = 1.0f; y = 0.0f;
		}
	}


	return EntryTime;
}
