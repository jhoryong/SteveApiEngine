#pragma once
#include "CommonInclude.h"
namespace steve {
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		End,
	};
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) 
		{ 
			return mKeys[(UINT)code].state == eKeyState::Down; 
		}
		static bool GetKeyUp(eKeyCode code) 
		{ 
			return mKeys[(UINT)code].state == eKeyState::Up;
		}
		static bool GetKey(eKeyCode code)
		{
			return mKeys[(UINT)code].state == eKeyState::Pressed;
		}

	private:
		static void CreateKeys();
		static void UpdateKeys();
		static void UpdateKey(Input::Key& key);
		static bool IsKeyDown(eKeyCode code);
		static void UpdateKeyDown(Input::Key& key);
		static void UpdateKeyUp(Input::Key& key);

	private:
		static std::vector<Key> mKeys;
	};


}
