#pragma once
class Box;
class Collision
{
public:
	static bool checkAABB(Box *b1, Box* b2);
	static float sweptAABBCheck(Box* b1, Box* b2, float& x, float& y);
	static Box* getBoardPhaseBox(Box* box);
	Collision(void);
	~Collision(void);
};