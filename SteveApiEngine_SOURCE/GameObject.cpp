#include "GameObject.h"

steve::GameObject::GameObject()
{
}

steve::GameObject::~GameObject()
{
}

void steve::GameObject::Update()
{
	mSpeed += 0.01f;
	// 내가 오른 키를 입력받았다면
	// x 좌표가 플러스
	// 왼쪽 -> x 가 마이너스
	// 위아래는 y가 플러스 마이너스
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		mX -= 0.01f;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		mX += 0.01f;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		mY -= 0.01f;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
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
