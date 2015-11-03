#pragma once
#include"Object.h"
class Objects
{
	Object** m_hObjects;
	int m_hCount;
public:
	void Load(string file);
	Objects();
	~Objects();
};

