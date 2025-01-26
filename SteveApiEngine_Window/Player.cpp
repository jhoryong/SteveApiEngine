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

	if (Input::GetKey(eKeyCode::Right))
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.x += 100.0f * Time::DeltaTime();
		tr->SetPos(pos);
	}
}

void steve::Player::Render(HDC hdc)
{
	GameObject::Render(hdc);
}
