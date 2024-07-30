#include "WonApplication.h"
#include "Actor.h"
#include "..\\Editer_Window\MyInclude.h"
#include "Input.h"


WonApplication::WonApplication()
{
	MyActor = new Actor;
	mhdc = nullptr;
	mhwnd = nullptr;
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
	Input::Update();
	MyActor->Update();
}
void WonApplication::Initialize(HWND hWnd)
{
	mhwnd = hWnd;
	mhdc = GetDC(hWnd);
	Input::Initialize();
}
void WonApplication::Render()
{
	MyActor->Render(mhdc);
}

