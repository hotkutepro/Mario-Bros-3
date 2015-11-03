#pragma once
#include<dinput.h>
#include"FrkGame.h"
class FrkKeyboard
{
	char m_hBuffer[256];
	FrkGame *m_hGame;
	//DirectInput Object
	LPDIRECTINPUT8 m_hDI_Object;
	//DirectInput Device
	LPDIRECTINPUTDEVICE8 m_hDI_Device;
	void InitDirectInput();
	void CreateDevice();
	void SetCooperativeLevel();
	void SetDataFormat();
	void Acquire();
	void UnAcquire();
	void Init();		
public:		
	void ClearBuffer();
	void GetDeviceState();
	bool IsKeyDown(int key);
	FrkKeyboard(FrkGame* game);
	FrkKeyboard();
	~FrkKeyboard();
};

