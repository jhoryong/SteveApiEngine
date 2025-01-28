#pragma once
#include "..\\SteveApiEngine_SOURCE\\ResourceManager.h"
#include "..\\SteveApiEngine_SOURCE\\Texture.h"

namespace steve
{
	void LoadResources()
	{
		ResourceManager::Load<graphics::Texture>(L"BG", L"../Resources/gura.jpeg");
	}
}