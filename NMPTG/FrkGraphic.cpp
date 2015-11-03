#include "FrkGraphic.h"

FrkGraphic::FrkGraphic(FrkGame* hGame)
{
	this->m_hGame = hGame;
	D3DXCreateSprite(this->m_hGame->GetDevice(), &this->m_hD3DXSprite);
}



FrkGraphic::~FrkGraphic(void)
{
}

void FrkGraphic::Begin()
{
	// x�a c?a s? v? b?ng m�u tr?ng D3DCOLOR_XRGB(255,255,255)
	this->m_hGame->GetDevice()->Clear(1, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1, NULL);
	// bat dau ve
	this->m_hGame->GetDevice()->BeginScene();
	this->m_hD3DXSprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void FrkGraphic::Begin(D3DXMATRIX* tranformMatrix)
{
	this->_TranformMatrix = tranformMatrix;
	this->Begin();
}

void FrkGraphic::End()
{
	// ket thuc ve
	this->m_hD3DXSprite->End();
	this->m_hGame->GetDevice()->EndScene();
	// the hien cac doi tuong 
	this->m_hGame->GetDevice()->Present(NULL, NULL, NULL, NULL);
}
void FrkGraphic::DrawTexture(FrkTexture* texture, D3DXVECTOR2 draw_postion, D3DXVECTOR2 texture_center, D3DCOLOR color, float depth)
{
	this->m_hD3DXSprite->Draw(
		texture->GetImage(),//hinh can ve
		NULL,//khung cat tu hinh
		&D3DXVECTOR3(texture_center.x,texture_center.y,0),//tam cua texture
		&D3DXVECTOR3(draw_postion.x, draw_postion.y, depth),//toa do texture tren man hinh
		color
		);
}

void FrkGraphic::DrawTexture(FrkTexture* texture, RECT rect_Present, D3DXVECTOR2 texture_center, D3DCOLOR color,float depth)
{
	float xScale = (float)(rect_Present.right - rect_Present.left) / texture->GetWidth();
	float yScale = (float)(rect_Present.bottom - rect_Present.top) / texture->GetHeight();

	D3DXMATRIX _normal;
	D3DXMATRIX _ScaleMatrix;

	D3DXMatrixScaling(&_ScaleMatrix, xScale, yScale, depth);

	D3DXVECTOR3 postion_Present;
	postion_Present.x = (float)rect_Present.left / xScale;
	postion_Present.y = (float)rect_Present.top / yScale;
	postion_Present.z = depth;

	D3DXVECTOR3 draw_center;
	draw_center.x = (float)texture_center.x / xScale;
	draw_center.y = (float)texture_center.y / yScale;
	draw_center.z = 0;

	m_hD3DXSprite->GetTransform(&_normal);
	m_hD3DXSprite->SetTransform(&_ScaleMatrix);
	this->m_hD3DXSprite->Draw(
		texture->GetImage(),//hinh can ve
		&rect_Present,//khung cat tu hinh
		&draw_center,//tam cua texture (sau khi Scale)
		&postion_Present,//toa do texture tren man hinh (sau khi Scale)
		color
		);
	m_hD3DXSprite->SetTransform(&_normal);
}

void FrkGraphic::DrawTexture(FrkTexture* texture, RECT rect_source, RECT rect_Present, D3DXVECTOR2 texture_center, D3DCOLOR color, float depth)
{
	float xScale = (float)(rect_Present.right - rect_Present.left) / (float)(rect_source.right - rect_source.left);
	float yScale = (float)(rect_Present.bottom - rect_Present.top) / (float)(rect_source.bottom - rect_source.top);

	D3DXMATRIX _normal;
	D3DXMATRIX _ScaleMatrix;

	D3DXMatrixScaling(&_ScaleMatrix, xScale, yScale, depth);

	D3DXVECTOR3 postion_Present;
	postion_Present.x = (float)rect_Present.left / xScale;
	postion_Present.y = (float)rect_Present.top / yScale;
	postion_Present.z = depth;

	D3DXVECTOR3 draw_center;
	draw_center.x = (float)texture_center.x / xScale;
	draw_center.y = (float)texture_center.y / yScale;
	draw_center.z = 0;

	m_hD3DXSprite->GetTransform(&_normal);
	m_hD3DXSprite->SetTransform(&_ScaleMatrix);
	this->m_hD3DXSprite->Draw(
		texture->GetImage(),//hinh can ve
		&rect_source,//khung cat tu hinh//////////////////////////////////////////////
		&draw_center,//tam cua texture (sau khi Scale)
		&postion_Present,//toa do texture tren man hinh (sau khi Scale)
		color
		);
	m_hD3DXSprite->SetTransform(&_normal);
}



void FrkGraphic::DrawSurface(LPDIRECT3DSURFACE9 surface, RECT rect, int x, int y)
{
	// xoa man hinh
	LPDIRECT3DSURFACE9 back_buffer;
	this->m_hGame->GetDevice()->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &back_buffer);
	this->m_hGame->GetDevice()->ColorFill(back_buffer, NULL, D3DCOLOR_XRGB(50, 50, 50));
	// random color
	int r = rand() % 255;
	int g = rand() % 255;
	int b = rand() % 255;
	//set position 
	rect.top = y;
	rect.bottom = rect.top + 100;
	rect.left = x;
	rect.right = rect.left + 100;
	this->m_hGame->GetDevice()->ColorFill(surface, &rect, D3DCOLOR_XRGB(r, g, b));
	//draw surface
	this->m_hGame->GetDevice()->StretchRect(surface, NULL, back_buffer, &rect, D3DTEXF_NONE);

}

D3DXVECTOR2 FrkGraphic::ConvertCoordinate(D3DXVECTOR2 ObjectWorldPosition, D3DXVECTOR2 ObjectCenter)
{
	D3DXVECTOR4 result;
	D3DXVECTOR3 input;
	input.x = ObjectWorldPosition.x + ObjectCenter.x;
	input.y = ObjectWorldPosition.y + ObjectCenter.y;
	input.z = 0;
	D3DXVec3Transform(&result, &input, _TranformMatrix);
	return D3DXVECTOR2(result.x, result.y);
}

void FrkGraphic::tDrawTexture(FrkTexture* texture, D3DXVECTOR2 draw_postion, D3DXVECTOR2 texture_center, D3DCOLOR color, float depth)
{
	D3DXVECTOR2 result = ConvertCoordinate(D3DXVECTOR2(draw_postion.x,draw_postion.y), D3DXVECTOR2(texture_center.x, texture_center.y));
	draw_postion.x = result.x;
	draw_postion.y = result.y;
	DrawTexture(texture, draw_postion, texture_center, color, depth);
}

void FrkGraphic::tDrawTexture(FrkTexture* texture, RECT rect_Present, D3DXVECTOR2 texture_center, D3DCOLOR color, float depth)
{
	D3DXVECTOR2 result = ConvertCoordinate(D3DXVECTOR2(rect_Present.left, rect_Present.top), D3DXVECTOR2(texture_center.x,texture_center.y)); 
	int dx = rect_Present.right - rect_Present.left;
	int dy = rect_Present.bottom - rect_Present.top;
	rect_Present.left = result.x;
	rect_Present.top = result.y;
	rect_Present.right = rect_Present.left + dx;
	rect_Present.bottom = rect_Present.top + dy;
	DrawTexture(texture, rect_Present, texture_center, color, depth);
}

void FrkGraphic::tDrawTexture(FrkTexture* texture, RECT rect_source, RECT rect_Present, D3DXVECTOR2 texture_center, D3DCOLOR color, float depth)
{
	D3DXVECTOR2 result = ConvertCoordinate(D3DXVECTOR2(rect_Present.left, rect_Present.top), D3DXVECTOR2(texture_center.x, texture_center.y));
	int dx = rect_Present.right - rect_Present.left;
	int dy = rect_Present.bottom - rect_Present.top;
	rect_Present.left = result.x;
	rect_Present.top = result.y;
	rect_Present.right = rect_Present.left + dx;
	rect_Present.bottom = rect_Present.top + dy;
	DrawTexture(texture, rect_source, rect_Present, texture_center, color, depth);
}

