#include "FrkSurFace.h"

FrkSurface::FrkSurface()
{
	lpSurface = 0;
	lpBackBuffer = 0;
}

FrkSurface::FrkSurface(const FrkSurface& surface)
{
	lpSurface = LPDIRECT3DSURFACE9(surface.lpSurface);
	lpBackBuffer = LPDIRECT3DSURFACE9(surface.lpBackBuffer);
}

FrkSurface::~FrkSurface()
{
	
}

void FrkSurface::LoadSurfaceFromFile(LPDIRECT3DDEVICE9 lpDirectDevice, D3DCOLOR colorKey, LPCSTR fileName)
{
	D3DXIMAGE_INFO infoImage;
	HRESULT hr;

	hr = D3DXGetImageInfoFromFile(fileName, &infoImage);
	if (FAILED(hr))
	{
		return;
	}
	hr = lpDirectDevice->CreateOffscreenPlainSurface(infoImage.Width,
		infoImage.Height,
		D3DFMT_A8R8G8B8,
		D3DPOOL_DEFAULT,
		&lpSurface,
		0);

	if (FAILED(hr))
	{
		return;
	}

	hr = D3DXLoadSurfaceFromFile(
		lpSurface,
		0,
		0,
		fileName,
		0,
		D3DX_DEFAULT,
		colorKey,
		0);

	if (FAILED(hr))
	{
		return;
	}

	hr = lpDirectDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &lpBackBuffer);

	if (FAILED(hr))
	{
		return;
	}
}

void FrkSurface::RenderSurface(LPDIRECT3DDEVICE9 lpDirectDevice, RECT *srcRect, RECT *desRect)
{
	lpDirectDevice->StretchRect(
		lpSurface,
		srcRect,
		lpBackBuffer,
		desRect,
		D3DTEXF_NONE);
}

void FrkSurface::UnLoadSurface()
{

}
