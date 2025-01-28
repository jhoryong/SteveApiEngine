#include "Scene.h"

steve::Scene::Scene() : mLayers{}
{
	CreateLayers();
}

steve::Scene::~Scene()
{
}

void steve::Scene::Initialize()
{
	for (Layer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->Initialize();
	}
}

void steve::Scene::Update()
{
	for (Layer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->Update();
	}
}

void steve::Scene::LateUpdate()
{
	for (Layer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->LateUpdate();
	}
}

void steve::Scene::Render(HDC hdc)
{
	for (Layer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->Render(hdc);
	}
}

void steve::Scene::AddGameObject(GameObject* gameObject, const enums::eLayerType type)
{
	mLayers[(UINT)type]->AddGameObject(gameObject);
}

void steve::Scene::CreateLayers()
{
	mLayers.resize((UINT)enums::eLayerType::Max);
	for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
	{
		mLayers[i] = new Layer();
	}
}

void steve::Scene::OnEnter()
{

}

void steve::Scene::OnExit()
{

}