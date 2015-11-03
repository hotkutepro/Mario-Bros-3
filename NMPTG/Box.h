#pragma once
class Box
{
	
public:
	// position of top-left corner
	float x, y;

	// dimensions
	float w, h;

	// velocity
	float vx, vy;
	Box(float _x, float _y, float _w, float _h, float _vx, float _vy);
	Box(float _x, float _y, float _w, float _h);
	Box();
	~Box();
};

