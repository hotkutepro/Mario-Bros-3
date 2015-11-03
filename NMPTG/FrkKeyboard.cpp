﻿#include "FrkKeyboard.h"


void FrkKeyboard::InitDirectInput()
{
	HRESULT hr = DirectInput8Create(m_hGame->GethIstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_hDI_Object, NULL);
	if (FAILED(hr))
		MessageBox(NULL,"Không khởi tạo được đối tượng DirectInput",NULL,1);		
}
void FrkKeyboard::CreateDevice()
{
	m_hDI_Device = 0;
	HRESULT hr = m_hDI_Object->CreateDevice(GUID_SysKeyboard,&(m_hDI_Device), NULL);	
	if (FAILED(hr))
		MessageBox(NULL, "Không khởi tạo được thiết bị DirectInput ", NULL, 1);
}
void FrkKeyboard::SetDataFormat()
{
	HRESULT hr = m_hDI_Device->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr))
		MessageBox(NULL, "Không thiết lập được định dạng dữ liệu",NULL,1);
}
void FrkKeyboard::SetCooperativeLevel()
{
	HRESULT hr = m_hDI_Device->SetCooperativeLevel(m_hGame->GetwndHandle(), DISCL_FOREGROUND|DISCL_NONEXCLUSIVE);
	if (FAILED(hr))
		MessageBox(NULL, "Lỗi thiết lập mức truy cập của thiết bị",NULL,1);
}
void FrkKeyboard::Acquire()
{
	m_hDI_Device->Acquire();
}
void FrkKeyboard::UnAcquire()
{
	m_hDI_Device->Unacquire();
}
void FrkKeyboard::GetDeviceState()
{
	
	m_hDI_Device->GetDeviceState(sizeof(m_hBuffer), &m_hBuffer);

}
void FrkKeyboard::ClearBuffer(){
	for (int i = 0; i < 256; i++)
		m_hBuffer[i] = 0;
}
bool FrkKeyboard::IsKeyDown(int key)
{	
	return m_hBuffer[key] & 0x80;
}
void FrkKeyboard::Init(){
	ZeroMemory(&m_hBuffer, sizeof(m_hBuffer));
	InitDirectInput();
	CreateDevice();
	SetCooperativeLevel();
	SetDataFormat();
	Acquire();
}
FrkKeyboard::FrkKeyboard(FrkGame* game)
{
	m_hGame = game;
	Init();		
}
FrkKeyboard::FrkKeyboard()
{
}


FrkKeyboard::~FrkKeyboard()
{
}
