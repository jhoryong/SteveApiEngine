#pragma once
#include "CommonInclude.h"
#include "GameObject.h"
namespace steve
{
	class App
	{
	public:
		App();
		~App();
		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;

		GameObject mPlayer;
	};
}