#include "FrkTexture.h"

FrkTexture::FrkTexture()
{
	m_hWidth = 0;
	m_hHeight = 0;
	m_hLpDirect3DTexture = NULL;
}

FrkTexture::FrkTexture(int width, int height)
{
	SetHeight(height);
	SetWidth(width);
}

FrkTexture::FrkTexture(FrkTexture* texture)
{
	SetHeight(texture->m_hHeight);
	SetWidth(texture->m_hWidth);
}

void FrkTexture::SetHeight(int height)
{
	m_hHeight = height;
}

void FrkTexture::SetWidth(int width)
{
	m_hWidth = width;
}

int FrkTexture::GetHeight()
{
	return m_hHeight;
}

int FrkTexture::GetWidth()
{
	return m_hWidth;
}

void FrkTexture::SetImage(LPDIRECT3DTEXTURE9 lpImage)
{
	m_hLpDirect3DTexture = lpImage;
}

LPDIRECT3DTEXTURE9 FrkTexture::GetImage()
{
	return m_hLpDirect3DTexture;
}

FrkTexture::~FrkTexture()
{

}