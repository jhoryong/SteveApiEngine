#pragma once
#include "..\\SteveApiEngine_SOURCE\\Resources.h"
#include "..\\SteveApiEngine_SOURCE\\Texture.h"

namespace steve
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"Packman", L"..\\Resources\\img\\pacman\\0.png");
	}
}