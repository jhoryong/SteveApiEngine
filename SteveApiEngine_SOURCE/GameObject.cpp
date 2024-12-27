#include "GameObject.h"
#include "Input.h"

steve::GameObject::GameObject():
								mX(0.f), 
								mY(0.f), 
								mSpeed(0.f)
{
}

steve::GameObject::~GameObject()
{
}

void steve::GameObject::Update()
{
	if (Input::GetKey(eKeyCode::A))
	{
		mX -= 0.01f;
	}
	if (Input::GetKey(eKeyCode::D))
	{
		mX += 0.01f;
	}
	if (Input::GetKey(eKeyCode::W))
	{
		mY -= 0.01f;
	}
	if (Input::GetKey(eKeyCode::S))
	{
		mY += 0.01f;
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
