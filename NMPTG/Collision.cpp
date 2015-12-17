#include "Collision.h"
#include <limits>
#include "Box.h"

Collision::Collision(void)
{
}


Collision::~Collision(void)
{
}

bool Collision::checkAABB(Box *b1, Box* b2)
{
	return !(b1->getRight() < b2->_position.x || b1->getBottom() < b2->_position.y || b2->getRight() < b1->_position.x || b2->getBottom() < b1->_position.y);
}

float Collision::sweptAABBCheck(Box* b1, Box* b2, float& x, float& y)
{
	float dxEntry, dyEntry;//khoang cach gan nhat
	float dxExit, dyExit;//khang cach xa nhat
	float txEntry, txExit;// thoi gian bat dau va cham theo cac truc
	float tyEntry, tyExit;//thoi gian ket thuc va cham theo cac truc
	float tEntry, tExit;//thoi gian bat dau/ket thuc va cham
	x = y = 0.0f;

	//khoang cach luon luon lay b2 - b1
	if (b1->_v.x > 0.0f)
	{
		//vat di qua phai => chi can quan tam den cac b2 ben phai
		dxEntry = b2->_position.x - b1->getRight();
		dxExit = b2->getRight() - b1->_position.x;
	}
	else
	{
		//vat di qua trai => chi can quan tam den cac b2 ben trai
		dxEntry = b2->getRight() - b1->_position.x;
		dxExit = b2->_position.x - b1->getRight();
	}


	if (b1->_v.y > 0.0f)
	{
		//vat di len => ta chi can quan tam de cac b2 nam ben tren
		dyEntry = b2->_position.y - b1->getBottom();
		dyExit = b2->getBottom() - b1->_position.y;
	}
	else
	{
		//vat di xuong => ta chi can quan tam den cac b2 o ben duoi		
		dyEntry = b2->getBottom() - b1->_position.y;
		dyExit = b2->_position.y - b1->getBottom();
	}

	//tinh thoi gian va cham//ket thuc theo cac truc
	//ta co tEntry = max(txEntry,tyEntry) 
	//neu v = 0 se khong bao gio xay ra va cham. => gan bang cac gia tri tai vo cuc
	if (b1->_v.x == 0.0f)
	{
		txEntry = -std::numeric_limits<float>::infinity();
		txExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		txEntry = dxEntry / b1->_v.x;
		txExit = dxExit / b1->_v.x;
	}

	if (b1->_v.y == 0.0f)
	{
		tyEntry = -std::numeric_limits<float>::infinity();
		tyExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		tyEntry = dyEntry / b1->_v.y;
		tyExit = dyExit / b1->_v.y;
	}


	tEntry = max(txEntry, tyEntry);
	tExit = min(txExit, tyExit);

	if (tEntry > tExit || //truc va cham sau cung chua xay ra thi va cham o truc truc da kt
		txEntry < 0.0f && tyEntry < 0.0f ||//truong hop b1 nam tren/ duoi/ trai/ phai 
		txEntry > 1.0f ||// b1 cach xa b2 theo truc x
		tyEntry > 1.0f)//b1 cach xa b2 theo truc y
	{
		return 1.0f;
	}
	//nghi ngo co va cham
	if (txEntry < 0.0f)
	{
		if (b1->getRight() < b2->_position.x || b2->getRight() < b1->_position.x) return 1.0f;

	}
	if (tyEntry < 0.0f)
	{
		if (b1->getBottom() < b2->_position.y || b2->getBottom() < b1->_position.y) return 1.0f;
	}
	if (txEntry > tyEntry)// va cham xay ra tren truc x
	{
		if (dxEntry > 0.0f)
		{
			//b1 nam ben trai
			x = -1.0f; y = 0.0f;
		}
		else
		{
			//truong hop dx == 0
			if (dxEntry == 0.0f)
			{
				if (b1->getRight() > b2->getRight())
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
				//b1 nam ben phai
				x = 1.0f; y = 0.0f;
			}
		}
	}
	else// va cham xay ra tren truc y
	{
		if (dyEntry > 0.0f)
		{
			//b1 nam o duoi
			x = 0.0f; y = -1.0f;
		}
		else
		{
			if (dyEntry == 0.0f)
			{
				if (b1->getBottom() > b2->getBottom())
				{
					x = 0.0f;
					y = 1.0f;
				}
				else
				{
					x = 0.0f;
					y = -1.0f;
				}
			}
			else
			{
				//b1 nam o tren
				x = 0.0f; y = 1.0f;
			}
		}
	}

	return tEntry;// thoi gian sap xay ra va cham
}

Box* Collision::getBoardPhaseBox(Box* box)
{
	Box* result = new Box(box->_position, box->_size, box->_v);
	//vx > 0 ?
	result->_position.x = box->_v.x > 0.0f ? box->_position.x : box->_position.x + box->_v.x;
	result->_position.y = box->_v.y > 0.0f ? box->_position.y : box->_position.y + box->_v.y;
	result->_size.x = box->_size.x + abs(box->_v.x);
	result->_size.y = box->_size.y + abs(box->_v.y);
	return result;
}
