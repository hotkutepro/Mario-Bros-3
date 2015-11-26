#pragma once
#include<dinput.h>
#include"FrkGame.h"
#define KEYBOARD_BUFFERSIZE 1024
class FrkKeyboard
{
	char m_hBuffer[256];
	char m_hBuffer_last[256];
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
	void SetProperty();
	void Init();			
	DWORD dwElements;
public:		
	LPDIRECTINPUTDEVICE8 GetKeyboarddevice();
	DIDEVICEOBJECTDATA _KeyEvents[KEYBOARD_BUFFERSIZE];
	void ClearBuffer();
	void GetDeviceState();
	bool IsKeyDown(int key);//trạng thái key đang được nhấn	
	bool IsKeyPressed(int key);//lấy trong buffer
	FrkKeyboard(FrkGame* game);
	FrkKeyboard();
	~FrkKeyboard();
};

