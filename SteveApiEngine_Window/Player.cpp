#include "Player.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"

void steve::Player::Initialize()
{
	GameObject::Initialize();
}

void steve::Player::Update()
{
	GameObject::Update();
}

void steve::Player::LateUpdate()
{
	GameObject::LateUpdate();
}

void steve::Player::Render(HDC hdc)
{
	GameObject::Render(hdc);
}
