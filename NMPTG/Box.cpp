#include "Box.h"
Box::Box(RECT _p,D3DXVECTOR2 _v)
{
	position.top = _p.top;
	position.left = _p.left;
	position.bottom = _p.bottom;
	position.right = _p.right;
	this->v = _v;
}
Box::Box(){

}

Box::~Box(void)
{
}
