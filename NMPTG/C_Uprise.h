#pragma once
#include "Object.h"
class C_Uprise:public Object
{
public:	
	void Load();
	void Update(float gameTime);
	void Render();
	C_Uprise();
	~C_Uprise();
};

