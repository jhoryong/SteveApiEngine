#include "GameObject.h"
#include "Input.h"

steve::GameObject::GameObject():
								mX(0.f), 
								mY(0.f), 
								mSpeed(5.f)
{
}

steve::GameObject::~GameObject()
{
}

void steve::GameObject::Update()
{
	if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left))
	{
		mX -= mSpeed;
	}
	if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right))
	{
		mX += mSpeed;
	}
	if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up))
	{
		mY -= mSpeed;
	}
	if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down))
	{
		mY += mSpeed;
	}
}

void steve::GameObject::LateUpdate()
{
}

void steve::GameObject::Render(HDC hdc)
{
	//파랑 브러쉬 생성
	HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
	// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);
	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
	SelectObject(hdc, oldPen);
	Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
	SelectObject(hdc, oldBrush);
	DeleteObject(blueBrush);
	DeleteObject(redPen);
}
