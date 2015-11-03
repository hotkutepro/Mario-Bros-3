#include "SweptAABB.h"
#include <cmath>
#include <algorithm>
#include <limits>


SweptAABB::SweptAABB()
{
}


SweptAABB::~SweptAABB()
{
}
//trả về true nếu có xảy ra va chạm
bool SweptAABB::AABBCheck(Box* b1, Box* b2)
{
	return !(b1->x + b1->w < b2->x || b1->x > b2->x + b2->w || b1->y + b1->h < b2->y || b1->y > b2->y + b2->h);
}

//trả về true nếu có xảy ra va chạm. đồng thời trả về giá trị mà ta cần phải di chuyển để không còn xảy ra va chạm.
//ta sẽ ưu tiên lấy giá trị của trục nhỏ hơn để di chuyển, giá trị của trục còn lại bằng 0(vì di chuyển một trục là đủ)
bool SweptAABB::AABB(Box* b1, Box* b2, float& moveX, float& moveY)
{
	moveX = moveY = 0.0f;

	float l = b2->x - (b1->x + b1->w);
	float r = (b2->x + b2->w) - b1->x;
	float t = b2->y - (b1->y + b1->h);
	float b = (b2->y + b2->h) - b1->y;

	// check that there was a collision
	if (l > 0 || r < 0 || t > 0 || b < 0)
		return false;

	// find the offset of both sides
	moveX = abs(l) < r ? l : r;
	moveY = abs(t) < b ? t : b;

	// only use whichever offset is the smallest
	if (abs(moveX) < abs(moveY))
		moveY = 0.0f;
	else
		moveX = 0.0f;

	return true;
}

//trả về một vùng mà vùng đó sẽ chứa box lúc chưa di chuyển và box đã di chuyển tới một đích.
Box* SweptAABB::GetSweptBroadphaseBox(Box* b)
{
	Box* broadphasebox = new Box(0.0f, 0.0f, 0.0f, 0.0f);

	broadphasebox->x = b->vx > 0 ? b->x : b->x + b->vx;
	broadphasebox->y = b->vy > 0 ? b->y : b->y + b->vy;
	broadphasebox->w = b->vx > 0 ? b->vx + b->w : b->w - b->vx;
	broadphasebox->h = b->vy > 0 ? b->vy + b->h : b->h - b->vy;

	return broadphasebox;
}

// performs collision detection on moving box b1 and static box b2
// returns the time that the collision occured (where 0 is the start of the movement and 1 is the destination)
// getting the new position can be retrieved by box.x = box.x + box.vx * collisiontime
// normalx and normaly return the normal of the collided surface (this can be used to do a response)
//trả về thời gian xảy ra va chạm(b1 di chuyển, b2 vật làm mốc)
//normalx và nomarly cho ta biết va chạm xảy ra ở đâu 
float SweptAABB::SweptAABB1(Box* b1, Box* b2, float& normalx, float& normaly)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	// find the distance between the objects on the near and far sides for both x and y
	if (b1->vx > 0.0f)//b1 đang tiến lên để gặp b2
	{
		xInvEntry = b2->x - (b1->x + b1->w);
		xInvExit = (b2->x + b2->w) - b1->x;
	}
	else//b1 đang lùi về để gặp b2
	{
		xInvEntry = (b2->x + b2->w) - b1->x;
		xInvExit = b2->x - (b1->x + b1->w);
	}

	if (b1->vy > 0.0f)//tiến lên hướng phía b2
	{
		yInvEntry = b2->y - (b1->y + b1->h);
		yInvExit = (b2->y + b2->h) - b1->y;
	}
	else//lùi về hướng về phía b2
	{
		yInvEntry = (b2->y + b2->h) - b1->y;
		yInvExit = b2->y - (b1->y + b1->h);
	}

	// find time of collision and time of leaving for each axis (if statement is to prevent divide by zero)
	float xEntry, yEntry;
	float xExit, yExit;

	if (b1->vx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / b1->vx;//trả về thời gian hai box sẽ gặp nhau theo trục x(nói về hình chiếu của hai box theo trục x)
		xExit = xInvExit / b1->vx;//trả về thời gian kết thúc va chạm theo trục x
	}

	if (b1->vy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / b1->vy;//trả về thời gian hai box sẽ gặp nhau theo trục y(nói về hình chiếu của hai box theo trục y)
		yExit = yInvExit / b1->vy;//trả về thời gian kết thúc va chạm theo trục y
	}

	// tìm thời gian bắt đầu và kết thúc va chạm(kết thúc có nghĩa là khi nào thì box1 sẽ xuyên và qua khỏi box 2)
	float entryTime = std::max(xEntry, yEntry);//Thời gian xảy ra va chạm tại hệ trục tọa độ oxy
	float exitTime = std::min(xExit, yExit);//Thời gian kết thúc va chạm

	// Nếu không có xảy ra va chạm thì
	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}
	else // Nếu như có xảy ra va chạm
	{
		// calculate normal of collided surface
		if (xEntry > yEntry)//Xảy ra va chạm theo trục x(bắt đầu va chạm tại xEntry)
		{
			if (xInvEntry < 0.0f)//box1 đang lùi về trục tọa độ, tiến đến b2(va chạm tại cạnh trái b2)
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else
			{
				normalx = -1.0f;//va chạm tại cạnh phải b2
				normaly = 0.0f;
			}
		}
		else//Băt đầu va chạm tại yEntry
		{
			if (yInvEntry < 0.0f)
			{
				normalx = 0.0f;
				normaly = 1.0f;//va chạm tại cạnh dưới b2
			}
			else
			{
				normalx = 0.0f;
				normaly = -1.0f;//va chạm tại cạnh trên b2
			}
		}

		// return the time of collision
		return entryTime;
	}
}
