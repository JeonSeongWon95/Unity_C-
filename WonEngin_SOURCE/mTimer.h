#pragma once
#include "..\Editer_Window\MyInclude.h"

class mTimer
{
public:

	static void Update();
	static void Render(HDC mhdc);
	static void Initialize();

	static double GetDeltaTime() { return DeltaTime; }


protected:
	static double DeltaTime;
	static LARGE_INTEGER PreCounter;
	static LARGE_INTEGER CurCounter;
	static LARGE_INTEGER CpuCounter;
};

