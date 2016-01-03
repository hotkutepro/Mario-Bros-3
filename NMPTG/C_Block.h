#pragma once
#include "Object.h"
#include<vector>
class C_Block:public Object
{
private:	
	int n;
public:
	vector<D3DXVECTOR2*> v_Pos;
	void Load();
	void Update(float gameTime);
	void Render();	
	C_Block();
	~C_Block();
};

