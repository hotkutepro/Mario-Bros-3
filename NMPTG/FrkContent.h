#pragma once
#include <d3dx9.h>
#include <string>
#include "FrkGame.h"
#include "FrkTexture.h"
using namespace std;
class FrkContent
{
protected:
	FrkGame* m_hGame;
	FrkTexture* m_hMytexture;
public:
	// load 1 texture
	FrkTexture* LoadTexture(string path);
	//load 1 sufface
	LPDIRECT3DSURFACE9 LoadSurface(string path);
	FrkContent(FrkGame*);
	~FrkContent(void);
	
};

