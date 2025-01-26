#pragma once
#include "../SteveApiEngine_SOURCE/SceneManager.h"
#include "PlayScene.h"
#include "TitleScene.h"

namespace steve
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}