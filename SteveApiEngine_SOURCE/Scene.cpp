#include "Scene.h"

steve::Scene::Scene() : mGameObjects{}
{
}

steve::Scene::~Scene()
{
}

void steve::Scene::Initialize()
{

}

void steve::Scene::Update()
{
	for (GameObject* gameobject : mGameObjects)
	{
		gameobject->Update();
	}
}

void steve::Scene::LateUpdate()
{
	for (GameObject* gameobject : mGameObjects)
	{
		gameobject->LateUpdate();
	}
}

void steve::Scene::Render(HDC hdc)
{
	for (GameObject* gameobject : mGameObjects)
	{
		gameobject->Render(hdc);
	}
}

void steve::Scene::AddGameObject(GameObject* gameObject)
{
	mGameObjects.push_back(gameObject);
}
