#include "FrkSprite.h"
#include"FrkShareControl.h"
FrkSprite::FrkSprite()
{
}
void FrkSprite::Render2(D3DXVECTOR2 position){
	RECT frame;
	frame.left = (this->_Index % this->_SpriteperRow)*(this->_Image->GetWidth() / this->_SpriteperRow);
	frame.right = frame.left + (this->_Image->GetWidth() / this->_SpriteperRow);
	frame.top = (this->_Index / this->_SpriteperRow)*(this->_Image->GetHeight() / this->_SpriteperRow * this->_Count);
	frame.bottom = frame.top + (this->_Image->GetHeight() / this->_SpriteperRow * this->_Count);

	RECT des;
	des.top = position.y;
	des.left = position.x;
	des.bottom = des.top + (this->_Image->GetHeight() / this->_SpriteperRow * this->_Count);
	des.right = des.left + (this->_Image->GetWidth() / this->_SpriteperRow);
	D3DXVECTOR2 center;
	center.y = (this->_Image->GetHeight() * this->_SpriteperRow / this->_Count) / 2;
	center.x = (this->_Image->GetWidth() / this->_SpriteperRow) / 2;
	_LocalGraphic->tDrawTexture(this->_Image, frame, des, center, D3DCOLOR_XRGB(255, 255, 255),0.2);
}
void FrkSprite::Render(D3DXVECTOR2 position)
{
	RECT frame;
	frame.left = _X+_Index*_Width;
	frame.top = _Y;
	frame.right = frame.left+ _Width;
	frame.bottom = _Y + _Height;

	RECT des;
	des.left = position.x;
	des.top = position.y;
	des.right = des.left + _Width/2;
	des.bottom = des.top + _Height/2;
	D3DXVECTOR2 center;
	center.x = _Width / 4;
	center.y = _Height / 4;
	_LocalGraphic->tDrawTexture(this->_Image, frame, des, center, D3DCOLOR_XRGB(255, 255, 255), 0.2);
}
void FrkSprite::Next()
{
	_Index = (_Index + 1) % _Count;
}
void FrkSprite::Reset()
{
	_Index = 0;
}
void FrkSprite::Set(int index){
	this->_Index = index;
}
FrkSprite::FrkSprite(FrkSprite* sprite)
{
	this->_Count = sprite->_Count;
	this->_Height = sprite->_Height;
	this->_Width = sprite->_Width;
	this->_Image = sprite->_Image;
	this->_SpriteperRow = sprite->_SpriteperRow;
}
FrkSprite::FrkSprite(FrkTexture* img,int count, int spriteperrow)
{
	this->_Image = img;
	this->_Count = count;		
	this->_SpriteperRow = spriteperrow;
	this->_Index = 0;
	this->_Height = img->GetHeight()*spriteperrow / count;
	this->_Width = img->GetWidth() / spriteperrow;
}
FrkSprite::~FrkSprite()
{
}
