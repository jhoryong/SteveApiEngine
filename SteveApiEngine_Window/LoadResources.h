#pragma once
#include "..\\SteveApiEngine_SOURCE\\Resources.h"
#include "..\\SteveApiEngine_SOURCE\\Texture.h"

namespace steve
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");
	}
}