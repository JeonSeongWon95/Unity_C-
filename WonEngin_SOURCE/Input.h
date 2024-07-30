#pragma once
#include "..\Editer_Window\MyInclude.h"

enum class mKeyCode
{
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L, Z,
	X, C, V, B, N, M,
	End
};

enum class mKeyState
{
	Pressed,
	Down,
	Up,
	None
};

class Input
{
	struct mKey
	{
		mKeyCode KeyCode;
		mKeyState KeyState;
		bool IsPressed;
	};

public:
	static void Initialize();
	static void Update();

	static bool GetKey(mKeyCode Keycode);
	static bool GetKeyDown(mKeyCode Keycode);
	static bool GetKeyUp(mKeyCode Keycode);


private:

	static std::vector<mKey> Keys;

};

