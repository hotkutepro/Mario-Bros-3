#include "FrkContent.h"
FrkContent::FrkContent(FrkGame* hGame)
{
	m_hGame = hGame;
}

FrkTexture* FrkContent::LoadTexture(string path)
{
	this->m_hMytexture = new FrkTexture();
	LPDIRECT3DTEXTURE9 texture = NULL;
	D3DXIMAGE_INFO info;
	HRESULT hr;
	ZeroMemory(&info, sizeof(info));
	//l?y thông tin v? hình ?nh
	hr = D3DXGetImageInfoFromFile(path.c_str(), &info);
	if (hr != D3D_OK)
		return NULL;
	//t?o texture
	hr = D3DXCreateTextureFromFileEx(this->m_hGame->GetDevice(),
		path.c_str(),
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,// t? ??ng ch?n format phù h?p
		D3DPOOL_DEFAULT, //Ch?n b? nh? ?? l?u t? ??ng
		D3DX_DEFAULT,//Ch?n tham s? m?c ??nh
		D3DX_DEFAULT,//Ch?n tham s? m?c ??nh
		D3DCOLOR_XRGB(255, 255, 255),
		&info,//thông tin hình ?nh
		NULL,
		&texture);

	if (hr != D3D_OK)
		return 0;
	this->m_hMytexture->SetImage(texture);
	this->m_hMytexture->SetHeight(info.Height);
	this->m_hMytexture->SetWidth(info.Width);
	return m_hMytexture;
}

LPDIRECT3DSURFACE9 FrkContent::LoadSurface(string path)
{
	LPDIRECT3DSURFACE9 surface = NULL;
	D3DXIMAGE_INFO info;
	HRESULT hr;
	ZeroMemory(&info, sizeof(info));
	hr = D3DXGetImageInfoFromFile(path.c_str(), &info);
	if (hr != D3D_OK)
		return NULL;
	hr = this->m_hGame->GetDevice()->CreateOffscreenPlainSurface(
		info.Width,
		info.Height,
		D3DFMT_UNKNOWN,//Ch?n format t? ??ng
		D3DPOOL_DEFAULT,//Ch?n vùng nh? t? ??ng
		&surface,//Con tr? l?u surface ???c t?o ra
		NULL);
	if (hr != D3D_OK)
		return 0;
	//load hình lên surface ?ã t?o ra
	hr = D3DXLoadSurfaceFromFile(surface, NULL, NULL, path.c_str(), NULL, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), &info);
	if (hr != D3D_OK)
		return 0;
	return surface;
}

FrkContent::~FrkContent(void)
{

}
