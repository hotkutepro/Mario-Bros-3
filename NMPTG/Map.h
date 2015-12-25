#pragma once
#include"FrkTexture.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class Map
{
private: 	
	int c;//view port
	int r;//	
	FrkTexture* _texture;
	int** _matrix;
	int _row;
	int _column;
	void loadMaxtrix(string path);
public:
	void Init(string path, FrkTexture* texture);
	void Update();
	void Render();
	Map();
	~Map();
};

