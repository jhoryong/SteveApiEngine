#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "Texture.h"
steve::SpriteRenderer::SpriteRenderer()
	:Component()
	, mTexture(nullptr)
	, mSize(Vector2::One)
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
	// transform component 를 가져와서 위치값을 구한 뒤 리소스를 그린다.
	if (mTexture == nullptr)
		assert(false);

	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();

	if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
	{
		//https://blog.naver.com/power2845/50147965306
		TransparentBlt(hdc, pos.x, pos.y
			, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
			, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
			, RGB(255, 0, 255));
	}
	else if (mTexture->GetTextureType()
		== graphics::Texture::eTextureType::Png)
	{
		Gdiplus::Graphics graphcis(hdc);
		graphcis.DrawImage(mTexture->GetImage()
			, Gdiplus::Rect(pos.x, pos.y
				, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
	}
}
