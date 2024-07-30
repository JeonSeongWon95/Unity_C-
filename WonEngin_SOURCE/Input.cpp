#include "Input.h"
#include "..\Editer_Window\MyInclude.h"


int ASCII[(UINT)mKeyCode::End] =
{
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I',
	'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H',
	'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B',
	'N', 'M'
};

std::vector<Input::mKey> Input::Keys = {};

void Input::Initialize()
{
	for(int i = 0; i < (UINT)mKeyCode::End; ++i)
	{
		mKey Key = {};
		Key.IsPressed = false;
		Key.KeyState = mKeyState::None;
		Key.KeyCode = (mKeyCode)i;

		Keys.push_back(Key);
	}
}

void Input::Update()
{
	for(int i = 0; i < Keys.size(); ++i)
	{
		if(GetAsyncKeyState(ASCII[i]) & 0X8000)
		{
			if(Keys[i].IsPressed == true)
			{
				Keys[i].KeyState = mKeyState::Pressed;
			}
			else
			{
				Keys[i].KeyState = mKeyState::Down;
			}
			Keys[i].IsPressed = true;
		}
		else
		{
			if(Keys[i].IsPressed == true)
			{
				Keys[i].KeyState = mKeyState::Up;
			}
			else
			{
				Keys[i].KeyState = mKeyState::None;
			}
			Keys[i].IsPressed = false;
		}
	}
}

bool Input::GetKey(mKeyCode Keycode)
{
	return Keys[(UINT)Keycode].KeyState == mKeyState::Pressed;
}

bool Input::GetKeyDown(mKeyCode Keycode)
{
	return Keys[(UINT)Keycode].KeyState == mKeyState::Down;
}

bool Input::GetKeyUp(mKeyCode Keycode)
{
	return Keys[(UINT)Keycode].KeyState == mKeyState::Up;
}
