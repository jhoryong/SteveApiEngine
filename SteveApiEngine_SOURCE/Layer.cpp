#include "Layer.h"

steve::Layer::Layer() : mGameObjects{}
{
}

steve::Layer::~Layer()
{
}

void steve::Layer::Initialize()
{
	for (GameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Initialize();
	}
}

void steve::Layer::Update()
{
	for (GameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Update();
	}
}

void steve::Layer::LateUpdate()
{
	for (GameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->LateUpdate();
	}
}

void steve::Layer::Render(HDC hdc)
{
	for (GameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Render(hdc);
	}
}

void steve::Layer::AddGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr)
		return;

	mGameObjects.push_back(gameObject);
}
