#pragma once
#include"Box.h"
class SweptAABB
{

public:
	bool AABBCheck(Box* b1, Box* b2);
	bool AABB(Box* b1, Box* b2, float& moveX, float& moveY);
	Box* GetSweptBroadphaseBox(Box* b);
	float SweptAABB1(Box* b1, Box* b2, float& normalx, float& normaly);

	SweptAABB();
	~SweptAABB();
};

