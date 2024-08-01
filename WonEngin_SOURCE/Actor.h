#pragma once
#include "..\\Editer_Window\MyInclude.h"

class Actor
{
public:
	Actor();
	~Actor();

	void SetPosition(float NewX, float NewY) { PositionX = NewX; PositionY = NewY; }
	float GetPositionX() { return PositionX; }
	float GetPositionY() { return PositionY; }

	void Initialize(HWND hwnd);
	void Update();
	void Render(HDC hdc);

private:
	float Speed;
	float PositionX;
	float PositionY;
	HWND mhWnd;

};

