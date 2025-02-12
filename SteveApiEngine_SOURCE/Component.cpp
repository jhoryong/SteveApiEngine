#include "Component.h"

steve::Component::Component(enums::eComponentType type)
	:mType(type)
{
}

steve::Component::~Component()
{
}

void steve::Component::Initialize()
{
}

void steve::Component::Update()
{
}

void steve::Component::LateUpdate()
{
}

void steve::Component::Render(HDC hdc)
{
}
