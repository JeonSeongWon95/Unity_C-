#include "Actor.h"
#include "Input.h"
#include "mTimer.h"

Actor::Actor()
{
	PositionX = 0;
	PositionY = 0;
	mhWnd = nullptr;
	Speed = 100.0f;
}

Actor::~Actor()
{
}

void Actor::Initialize(HWND hwnd)
{
	mhWnd = hwnd;
}

void Actor::Update()
{
	if(Input::GetKey(mKeyCode::A))
	{
		PositionX -= Speed * mTimer::GetDeltaTime();
	}
	if (Input::GetKey(mKeyCode::D))
	{
		PositionX += Speed * mTimer::GetDeltaTime();
	}
	if (Input::GetKey(mKeyCode::W))
	{
		PositionY -= Speed * mTimer::GetDeltaTime();
	}
	if (Input::GetKey(mKeyCode::S))
	{
		PositionY += Speed * mTimer::GetDeltaTime();
	}
}

void Actor::Render(HDC hdc)
{
	HBRUSH Bluebrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH Prebrush = (HBRUSH)SelectObject(hdc, Bluebrush);

	Rectangle(hdc, 100 + (int)PositionX, 100 + (int)PositionY, 200 + (int)PositionX, 200 + (int)PositionY);

	SelectObject(hdc, Prebrush);
	DeleteObject(Bluebrush);
}
