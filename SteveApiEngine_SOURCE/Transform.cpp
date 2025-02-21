#include "Transform.h"

steve::Transform::Transform()
	: Component(enums::eComponentType::Transform)
	, mScale(Vector2::One)
	, mRotation(0.0f)
{
}

steve::Transform::~Transform()
{
}

void steve::Transform::Initialize()
{
}

void steve::Transform::Update()
{
}

void steve::Transform::LateUpdate()
{
}

void steve::Transform::Render(HDC hdc)
{
}
