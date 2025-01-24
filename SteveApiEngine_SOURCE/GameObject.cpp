#include "GameObject.h"
#include "Input.h"

steve::GameObject::GameObject()
{
}

steve::GameObject::~GameObject()
{
	for (Component* comp : mComponents)
	{
		delete comp;
		comp = nullptr;
	}
}

void steve::GameObject::Initialize()
{
	for (Component* comp : mComponents)
	{
		comp->Initialize();
	}
}

void steve::GameObject::Update()
{
	for (Component* comp : mComponents)
	{
		comp->Update();
	}
}

void steve::GameObject::LateUpdate()
{
	for (Component* comp : mComponents)
	{
		comp->LateUpdate();
	}
}

void steve::GameObject::Render(HDC hdc)
{
	for (Component* comp : mComponents)
	{
		comp->Render(hdc);
	}
}
