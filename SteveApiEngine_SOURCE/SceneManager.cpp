#include "SceneManager.h"

namespace steve
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;
}

void steve::SceneManager::Initialize()
{
}

void steve::SceneManager::Update()
{
	mActiveScene->Update();
}

void steve::SceneManager::LateUpdate()
{
	mActiveScene->LateUpdate();
}

void steve::SceneManager::Render(HDC hdc)
{
	mActiveScene->Render(hdc);
}
