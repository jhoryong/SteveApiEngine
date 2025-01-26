#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"

steve::SpriteRenderer::SpriteRenderer()
	: mImage(nullptr)
	, mWidth(0)
	, mHeight(0)
{
}

steve::SpriteRenderer::~SpriteRenderer()
{
}

void steve::SpriteRenderer::Initialize()
{
}

void steve::SpriteRenderer::Update()
{
}

void steve::SpriteRenderer::LateUpdate()
{
}

void steve::SpriteRenderer::Render(HDC hdc)
{
	// transform component �� �����ͼ� ��ġ���� ���� �� ���ҽ��� �׸���.
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();
	Gdiplus::Graphics graphics(hdc);
	graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
}

void steve::SpriteRenderer::ImageLoad(const std::wstring& path)
{
	mImage = Gdiplus::Image::FromFile(path.c_str());
	mWidth = mImage->GetWidth();
	mHeight = mImage->GetHeight();
}
