#include "GameObject.h"
#include "Input.h"
#include "Transform.h"
steve::GameObject::GameObject() : mComponents{}
{
	mComponents.resize((UINT)enums::eComponentType::End);
	InitializeTransform();
}

steve::GameObject::~GameObject()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;

		delete comp;
		comp = nullptr;
	}
}

void steve::GameObject::Initialize()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->Initialize();
	}
}

void steve::GameObject::Update()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->Update();
	}
}

void steve::GameObject::LateUpdate()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->LateUpdate();
	}
}

void steve::GameObject::Render(HDC hdc)
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->Render(hdc);
	}
}


void steve::GameObject::InitializeTransform()
{
	AddComponent<Transform>();
}