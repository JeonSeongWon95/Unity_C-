#pragma once
#include "..\\Editer_Window\MyInclude.h"

class WonApplication
{
public:
	WonApplication();
	~WonApplication();

	void Run();
	void Update();
	void Initialize(HWND hWnd);
	void Render();

private:
	class Actor* MyActor;
	HWND mhwnd;
	HDC mhdc;
};

