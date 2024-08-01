#include "WonApplication.h"
#include "Actor.h"
#include "..\\Editer_Window\MyInclude.h"
#include "Input.h"
#include "mTimer.h"


WonApplication::WonApplication()
{
	MyActor = new Actor;
	mhdc = nullptr;
	mhwnd = nullptr;
	mwidth = 0;
	mheigh = 0;
	mBackHDC = nullptr;
	mBuffer = nullptr;
}
WonApplication::~WonApplication()
{
	delete MyActor;
}

void WonApplication::Run()
{
	Update();
	Render();
}
void WonApplication::Update()
{
	mTimer::Update();
	Input::Update();
	MyActor->Update();
}
void WonApplication::Initialize(HWND hWnd, UINT width, UINT Heigh)
{
	mhwnd = hWnd;
	mhdc = GetDC(hWnd);

	mwidth = width;
	mheigh = Heigh;

	mBackHDC = CreateCompatibleDC(mhdc);
	mBuffer = CreateCompatibleBitmap(mhdc, width, Heigh);

	HBITMAP OldBuffer = (HBITMAP)SelectObject(mBackHDC, mBuffer);
	DeleteObject(OldBuffer);

	Input::Initialize();
	mTimer::Initialize();
}
void WonApplication::Render()
{
	mTimer::Render(mBackHDC);
	MyActor->Render(mBackHDC);

	BitBlt(mhdc, 0, 0, mwidth, mheigh, mBackHDC, 0, 0, SRCCOPY);

	RECT mRect = { 0, 0, 1600, 900 };
	HBRUSH mBrush = CreateSolidBrush(RGB(255, 255, 255));
	FillRect(mBackHDC, &mRect, mBrush);

}

