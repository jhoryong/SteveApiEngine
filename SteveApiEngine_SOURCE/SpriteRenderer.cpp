#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "Texture.h"
#include "Renderer.h"
namespace steve
{
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2::One)
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		// transform component 를 가져와서 위치값을 구한 뒤 리소스를 그린다.
		if (mTexture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRoation();
		Vector2 scale = tr->GetScale();

		pos = renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			//https://blog.naver.com/power2845/50147965306
			TransparentBlt(hdc, (int)pos.x, (int)pos.y
				, (int)(mTexture->GetWidth() * mSize.x * scale.x), (int)(mTexture->GetHeight() * mSize.y)
				, mTexture->GetHdc(), 0, 0, (int)mTexture->GetWidth(), (int)mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType()
			== graphics::Texture::eTextureType::Png)
		{
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));
			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			auto rect = Gdiplus::Rect(
				(int)pos.x, (int)pos.y
				, (int)(mTexture->GetWidth() * mSize.x * scale.x)
				, (int)(mTexture->GetHeight() * mSize.y * scale.y)
			);

			graphics.DrawImage(
				mTexture->GetImage(),
				rect,
				0, 0,
				mTexture->GetWidth(), mTexture->GetHeight(),
				Gdiplus::UnitPixel,
				nullptr
			);
		}
	}
}
