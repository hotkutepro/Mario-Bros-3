#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "FrkGame.h"
#include "FrkTexture.h"

class FrkGraphic
{
private:
	
	////doi tuong direct x
	//LPDIRECT3D9 d3d;
	////thiet bi ve
	//LPDIRECT3DDEVICE9 d3ddev;
	FrkGame* m_hGame;
	//Ve texture
	LPD3DXSPRITE m_hD3DXSprite;
	
	D3DXMATRIX* _TranformMatrix;
public:
	
	//Constructor
	//FrkGraphic(HWND, int, int);
	FrkGraphic(FrkGame* hGame);
	//Destructor
	~FrkGraphic(void);
	//bat dau ve
	void Begin();
	void Begin(D3DXMATRIX* tranformMatrix);
	//Ket thuc ve
	void End();
	//Ve texture
	void DrawTexture(FrkTexture* texture, D3DXVECTOR2 draw_postion,D3DXVECTOR2 texture_center, D3DCOLOR color, float depth);
	void DrawTexture(FrkTexture* texture, RECT rect_Present, D3DXVECTOR2 texture_center, D3DCOLOR color, float depth);
	void FrkGraphic::DrawTexture2(FrkTexture* texture, RECT rect_source, RECT rect_Present, D3DXVECTOR2 texture_center, D3DCOLOR color, float depth);
	void DrawTexture(FrkTexture* texture, RECT rect_source, RECT rect_Present, D3DXVECTOR2 texture_center, D3DCOLOR color, float depth);
	
	D3DXVECTOR2 ConvertCoordinate(D3DXVECTOR2 ObjectWorldPosition, D3DXVECTOR2 ObjectCenter);

	void tDrawTexture(FrkTexture* texture, D3DXVECTOR2 draw_postion, D3DXVECTOR2 texture_center, D3DCOLOR color, float depth);
	void tDrawTexture(FrkTexture* texture, RECT rect_Present, D3DXVECTOR2 texture_center, D3DCOLOR color, float depth);
	void tDrawTexture(FrkTexture* texture, RECT rect_source, RECT rect_Present, D3DXVECTOR2 texture_center, D3DCOLOR color, float depth);
	//Ve surface
	void DrawSurface(LPDIRECT3DSURFACE9 surface, RECT rect, int x, int y);
	
	
};