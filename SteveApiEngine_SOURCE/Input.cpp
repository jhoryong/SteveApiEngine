#include "Input.h"
namespace steve {
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] = {
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	};

	void Input::Initialize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			Key& key = mKeys[i];
			// 키가 눌린 상태
			if (GetAsyncKeyState(ASCII[i] & 0x8000))
			{
				if (key.bPressed == true) 
				{
					key.state = eKeyState::Pressed;
				}
				else
				{
					key.state = eKeyState::Down;
				}
				key.bPressed = true;
			}
			else
			{
				if (key.bPressed == true)
				{
					key.state = eKeyState::Up;
				}
				else
				{
					key.state = eKeyState::None;
				}
				key.bPressed = false;
			}
			}
		}
	}
}
