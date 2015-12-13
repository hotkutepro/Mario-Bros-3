#pragma once
#include "Box.h"
#include <iostream>
class Collision
{
public:
	Collision(void);
	static bool AABBCheck(Box b1, Box b2);
	static Box* GetBoardPhaseBox(Box* box);
	static float SweptAABB(Box* b1, Box* b2,float &x,float &y);
	~Collision(void);
};

