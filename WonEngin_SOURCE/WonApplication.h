#pragma once
#include "..\\Editer_Window\MyInclude.h"

class WonApplication
{
public:
	WonApplication();
	~WonApplication();

	void Run();
	void Update();
	void Initialize(HWND hWnd, UINT width, UINT Heigh);
	void Render();

private:
	class Actor* MyActor;

	UINT mwidth;
	UINT mheigh;

	HDC mBackHDC;
	HBITMAP mBuffer;

	HWND mhwnd;
	HDC mhdc;
};

