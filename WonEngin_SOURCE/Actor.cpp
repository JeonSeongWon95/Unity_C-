#include "Actor.h"
#include "Input.h"

Actor::Actor()
{
	PositionX = 0;
	PositionY = 0;
	mhWnd = nullptr;
	mhdc = nullptr;
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
		PositionX -= 0.01f;
	}
	if (Input::GetKey(mKeyCode::D))
	{
		PositionX += 0.01f;
	}
	if (Input::GetKey(mKeyCode::W))
	{
		PositionY -= 0.01f;
	}
	if (Input::GetKey(mKeyCode::S))
	{
		PositionY += 0.01f;
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
