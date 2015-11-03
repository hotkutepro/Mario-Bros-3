#pragma once
#include <Windows.h>
#include <d3d9.h>
#include<dinput.h>
#include"Map.h"
class FrkGame
{
private:	
	//hinstance cua chuong trinh
	HINSTANCE m_hInstance;
	//hwnd cua cua so
	HWND m_hWnd;
	// kich thuoc cua so
	int m_hWidth;
	int m_hHeight;
	//ten cua so
	char m_hWindowName[256];
	//Thao tac xu ly cua so
	static HRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
protected:
	//doi tuong direct x
	LPDIRECT3D9 m_hD3D;
	//thiet bi ve
	LPDIRECT3DDEVICE9 m_hD3DDevive;
	


public:		
	void InitLocal();
	bool InitDX();
	//thiet lap gia tri cho cua so
	bool InitWindow();
	//load data game
	virtual void Load();
	//update sau khoang thoi gian gameTime
	virtual void Update(float gameTime);
	//draw
	virtual void Render();
	void Run();
	// Constructor
	FrkGame(HINSTANCE hIns, int hWidth, int hHeight, char* hWindowName);
	FrkGame(FrkGame* hGame);
	~FrkGame(void);

	LPDIRECT3DDEVICE9 GetDevice();
	HINSTANCE GethIstance();	
	HWND GetwndHandle();
};

