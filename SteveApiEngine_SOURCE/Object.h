#pragma once
#include "SceneManager.h"
#include "Transform.h"
namespace steve
{
	namespace object
	{
		template <typename T>
		static T* Instantiate(steve::enums::eLayerType type)
		{
			T* gameObject = new T();
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			return gameObject;
		}

		template <typename T>
		static T* Instantiate(steve::enums::eLayerType type, math::Vector2 position)
		{
			T* gameObject = new T();
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			Transform* tr = gameObject->GetComponent<Transform>();
			tr->SetPosition(position);

			return gameObject;
		}
	}
}