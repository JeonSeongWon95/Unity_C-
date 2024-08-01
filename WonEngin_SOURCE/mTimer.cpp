#include "mTimer.h"
#include "..\Editer_Window\MyInclude.h"
#include <iostream>

double mTimer::DeltaTime = 0.0;

LARGE_INTEGER mTimer::PreCounter = {};
LARGE_INTEGER mTimer::CurCounter = {};
LARGE_INTEGER mTimer::CpuCounter = {};

void mTimer::Initialize()
{
	QueryPerformanceCounter(&PreCounter);
	QueryPerformanceFrequency(&CpuCounter);
}

void mTimer::Update()
{
	QueryPerformanceCounter(&CurCounter);
	double Temp = static_cast<double>(CurCounter.QuadPart - PreCounter.QuadPart);
	DeltaTime = Temp / static_cast<double>(CpuCounter.QuadPart);
	PreCounter.QuadPart = CurCounter.QuadPart;
}

void mTimer::Render(HDC mhdc)
{
	static double Time = 0.0;
	Time += DeltaTime;

	wchar_t str[50] = L"";
	swprintf_s(str, 50, L"Time : %f", Time);
	int len = wcsnlen_s(str, 50);

	TextOut(mhdc, 0, 0, str, len);
}
