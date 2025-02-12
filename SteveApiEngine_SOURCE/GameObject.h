#pragma once
#include "CommonInclude.h"
#include "Component.h"
namespace steve
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);
			UINT compType = (UINT)comp->GetType();
			mComponents[compType] = comp;

			return comp;
		}
		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{

				component = dynamic_cast<T*>(comp);
				if (component) break;
			}
			return component;
		}
	private:
		void InitializeTransform();
	private:
		std::vector<Component*> mComponents;
	};


}

