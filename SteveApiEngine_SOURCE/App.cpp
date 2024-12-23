#include "App.h"

namespace steve
{
	App::App()
		: mHwnd(nullptr)
		, mHdc(nullptr)
	{
	}
	App::~App()
	{
	}
	void App::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}
	void App::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void App::Update()
	{
		mPlayer.Update();
	}
	void App::LateUpdate()
	{
		mPlayer.LateUpdate();
	}
	void App::Render()
	{
		mPlayer.Render(mHdc);
	}
}