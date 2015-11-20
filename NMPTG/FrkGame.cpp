#include "FrkGame.h"
#include"FrkKeyboard.h"
#include"FrkControl.h"

FrkGame::FrkGame(HINSTANCE hIns, int Width, int Height, char* hWindowName,StateManager* sm)
{
	this->m_hInstance = hIns;
	this->m_hWidth = Width;
	this->m_hHeight = Height;
	this->m_hWnd = NULL;
	this->m_hD3D = NULL;
	this->m_hD3DDevive = NULL;
	strcpy(this->m_hWindowName, hWindowName);
	m_hStateManager = sm;
}

FrkGame::FrkGame(FrkGame* hGame)
{
	this->m_hInstance = hGame->m_hInstance;
	this->m_hWidth = hGame->m_hWidth;
	this->m_hHeight = hGame->m_hHeight;
	this->m_hWnd = hGame->m_hWnd;
	this->m_hD3D = hGame->m_hD3D;
	this->m_hD3DDevive = hGame->m_hD3DDevive;
	strcpy(this->m_hWindowName, hGame->m_hWindowName);
}


FrkGame::~FrkGame(void)
{
}
//Ham xu ly cua so. Chi can quan tam den ?M_DESTROY
LRESULT CALLBACK FrkGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_DESTROY)
	{
		PostQuitMessage(0);
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
// Tao cua so game, cai dat cai doi tuong directX o day
bool FrkGame::InitWindow()
{
	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hIconSm = 0;
	wndclass.hIcon = 0;
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hInstance = this->m_hInstance;
	wndclass.lpfnWndProc = (WNDPROC)WndProc;
	wndclass.lpszClassName = "Game";
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wndclass))
	{
		return false;
	}
	this->m_hWnd = CreateWindow(
		"Game",
		this->m_hWindowName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		this->m_hWidth,
		this->m_hHeight,
		NULL,
		NULL,
		this->m_hInstance,
		NULL);
	if (!this->m_hWnd)
		return false;
	ShowWindow(this->m_hWnd, SW_NORMAL);
	UpdateWindow(this->m_hWnd);
	return true;
}
bool FrkGame::InitDX()
{
	//tao mot doi tuong Direct3D
	this->m_hD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (!this->m_hD3D)
		return false;
	//tao thiet bi ve
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	//thong so man hinh
	d3dpp.BackBufferCount = 1;// 1 backbuffer
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;//auto format
	d3dpp.BackBufferWidth = this->m_hWidth;
	d3dpp.BackBufferHeight = this->m_hHeight;
	d3dpp.hDeviceWindow = this->m_hWnd;// Handle cua so ve~
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;// tham so hay dung
	d3dpp.Windowed = true;// che do co cua so
	HRESULT hr = this->m_hD3D->CreateDevice(D3DADAPTER_DEFAULT,//chon thiet bi ve mac dinh
		D3DDEVTYPE_HAL,//su dung ho tro phan cung
		this->m_hWnd,// Cua so ve
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,// thong so cho back buffer
		&this->m_hD3DDevive//con tro nhan du lieu sau khi tao device
		);

	if (FAILED(hr))
	{
		return false;
	}
	return true;
}
//Init game data
void FrkGame::Load()
{
	
}
void FrkGame::Update(float gameTime)
{

}
void FrkGame::Render()
{

}
//Lay thiet bi ve
LPDIRECT3DDEVICE9 FrkGame::GetDevice()
{
	return this->m_hD3DDevive;
}
HINSTANCE FrkGame::GethIstance(){
	return m_hInstance;
}
HWND FrkGame::GetwndHandle()
{
	return m_hWnd;
}
void FrkGame::Run()
{
	MSG msg;
	float fps = 0;
	float time_eslapse = 0;
	ZeroMemory(&msg, sizeof(MSG));
	LARGE_INTEGER start;
	LARGE_INTEGER now;
	LARGE_INTEGER cycle_count_per_second;
	
	QueryPerformanceFrequency(&cycle_count_per_second);
	//thoi gian 1 xung cpu / so xung cpu /1s
	float time_per_cycle = 1000.0f / cycle_count_per_second.QuadPart;
	float game_time = 0;
	//thoi gian 1 frame / 30 frame /1s
	float frame_rate = 1000.0f / 30.0f;
	//so xung tu luc khoi dong may den luc goi
	QueryPerformanceCounter(&start);
	float sleep;
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);	
			DispatchMessage(&msg);
		}
		else
		{
			//so xung tu luc khoi dong may den luc goi
			QueryPerformanceCounter(&now);
			//A = (now - start)  số xung từ now ->start
			// A * thoi gian 1 xung => thời gian từ now->start
			game_time = (now.QuadPart - start.QuadPart) * time_per_cycle;
			
			if (game_time >= frame_rate)
			{
				/*fps++;
				time_eslapse += game_time;
				if (time_eslapse > 1000.0f)
				{
					string txt = "mario : FPS = ";
					txt.append(std::to_string((fps / time_eslapse) * 1000));
					fps = 0;
					time_eslapse = 0;
					SetWindowText(this->m_hWnd, (char*)(txt.c_str()));
				}*/
				start = now;
				this->m_hStateManager->Update(game_time);
				this->m_hStateManager->Render();
				
			}
			else
			{
				Sleep(frame_rate - game_time);
			}
		}
	}
}
void FrkGame::InitLocal(){
	_LocalGraphic = new FrkGraphic(this);
	_LocalContent = new FrkContent(this);
	_LocalKeyboard = new FrkKeyboard(this);
}