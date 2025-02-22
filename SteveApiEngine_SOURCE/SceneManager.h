#pragma once
#include "Scene.h"
namespace steve
{
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			mActiveScene = scene;
			scene->SetName(name);
			scene->Initialize();
			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene() { return mActiveScene; }

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Release();
	private:
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}

