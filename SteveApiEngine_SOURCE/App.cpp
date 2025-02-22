#include "App.h"
#include "Input.h"
#include "Time.h"
#include "SceneManager.h"
#include "Resources.h"

namespace steve
{
	App::App()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
	{
	}
	App::~App()
	{
	}
	void App::Initialize(HWND hwnd, UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeManagers();
		SceneManager::Initialize();
	}
	void App::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void App::Update()
	{
		Input::Update();
		Time::Update();
		SceneManager::Update();
	}
	void App::LateUpdate()
	{
		SceneManager::LateUpdate();
	}
	void App::Render()
	{
		clearRenderTarget();

		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}

	void App::Release()
	{
		SceneManager::Release();
		Resources::Release();
	}

	void App::clearRenderTarget()
	{
		//clear
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void App::copyRenderTarget(HDC source, HDC dest)
	{
		// BackBuffer �� �ִ°� ���� Buffer �� ����(�׷��ش�)
		BitBlt(dest, 0, 0, mWidth, mHeight,
			source, 0, 0, SRCCOPY);
	}

	void App::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, (LONG)width, (LONG)height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void App::createBuffer(UINT width, UINT height)
	{
		// ������ �ػ󵵿� �´� ����� ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// ����۸� ����ų DC ����
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void App::initializeManagers()
	{
		Input::Initialize();
		Time::Initialize();
	}
}