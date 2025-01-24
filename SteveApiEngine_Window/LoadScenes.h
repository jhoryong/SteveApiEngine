#pragma once
#include "../SteveApiEngine_SOURCE/SceneManager.h"
#include "PlayScene.h"

namespace steve
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::LoadScene(L"PlayScene");
	}
}