#ifndef __FRKSURFACE_H__
#define __FRKSURFACE_H__
#include <d3dx9.h>
#include <d3d9.h>

class FrkSurface
{
private:
	LPDIRECT3DSURFACE9 lpSurface;
	LPDIRECT3DSURFACE9 lpBackBuffer;
public:
	FrkSurface();
	FrkSurface(const FrkSurface& surface);
	~FrkSurface();
	void LoadSurfaceFromFile(LPDIRECT3DDEVICE9 lpDirectDevice, D3DCOLOR colorKey, LPCSTR fileName);
	void RenderSurface(LPDIRECT3DDEVICE9 lpDirectDevice, RECT* srcRect, RECT* desRect);
	void UnLoadSurface();
};

#endif