#include "Box.h"


Box::~Box(void)
{
}

Box::Box(D3DXVECTOR2 _p, D3DXVECTOR2 _s, D3DXVECTOR2 _v)
{
	this->_position = _p;
	this->_size = _s;
	this->_v = _v;
}

Box::Box()
{

}

Box::Box(Box* box)
{
	this->_position = box->_position;
	this->_size = box->_size;
	this->_v = box->_v;
}

RECT Box::getRect()
{
	RECT r;
	r.left = this->_position.x;
	r.top = this->_position.y;
	r.right = getRight();
	r.bottom = getBottom();
	return r;
}

float Box::getBottom()
{
	return this->_position.y + _size.y;
}

float Box::getRight()
{
	return  this->_position.x + _size.x;
}

D3DXVECTOR2 Box::getCenter()
{
	return D3DXVECTOR2(_size.x / 2, _size.y / 2);
}
D3DXVECTOR2 Box::getCenterPos()
{
	return _position + getCenter();
}

float Box::getLeft()
{
	return  this->_position.x;
}

float Box::getTop()
{
	return this->_position.y;
}
