#ifndef __FRKTEXTURE_H__
#define __FRKTEXTURE_H__

#include <d3d9.h>
#include <d3dx9.h>
#include <sstream>
#include <vector>
#include <exception>
#include <time.h>

using namespace std;

class FrkTexture
{
private:
	LPDIRECT3DTEXTURE9 m_hLpDirect3DTexture;
	int m_hWidth;//Kích thước của một bưc ảnh lớn
	int m_hHeight;
public:
	void SetHeight(int);
	void SetWidth(int);
	int GetHeight();
	int GetWidth();
	FrkTexture();
	LPDIRECT3DTEXTURE9 GetImage();
	void SetImage(LPDIRECT3DTEXTURE9);
	FrkTexture(FrkTexture*);
	FrkTexture(int, int);
	~FrkTexture();
};

#endif