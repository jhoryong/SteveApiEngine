#include "Animation.h"
#include "Time.h"
#include "Transform.h"
#include "GameObject.h"
#include "Animator.h"
#include "Renderer.h"
#include "Camera.h"

namespace steve
{
    Animation::Animation()
        : Resource(enums::eResourceType::Animation)
        , mAnimator(nullptr)
        , mTexture(nullptr)
        , mAnimationSheet{}
        , mIndex(-1)
        , mTime(0.0f)
        , mbComplete(false)
    {
    }

    Animation::~Animation()
    {
    }

    HRESULT Animation::Load(const std::wstring& path)
    {
        return E_NOTIMPL;
    }

    void Animation::Update()
    {
        if (mbComplete)
            return;

        mTime += Time::DeltaTime();

        if (mAnimationSheet[mIndex].duration < mTime)
        {
            mTime = 0.0f;
            if (mIndex < mAnimationSheet.size() - 1)
                mIndex++;
            else
                mbComplete = true;
        }
    }

    void Animation::Render(HDC hdc)
    {
        // 알파블렌드를 쓸수 있는 조건 : 해당이미지 알파채널이 있어야한다.
        //AlphaBlend(125, );


        if (mTexture == nullptr)
            return;

        GameObject* gameObj = mAnimator->GetOwner();
        Transform* tr = gameObj->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        float rot = tr->GetRoation();
        Vector2 scale = tr->GetScale();

        if (renderer::mainCamera)
            pos = renderer::mainCamera->CalculatePosition(pos);


        Sprite sprite = mAnimationSheet[mIndex];
        graphics::Texture::eTextureType type = mTexture->GetTextureType();

        if (type == graphics::Texture::eTextureType::Bmp)
        {
            BLENDFUNCTION func = {};
            func.BlendOp = AC_SRC_OVER;
            func.BlendFlags = 0;
            func.AlphaFormat = AC_SRC_ALPHA;
            func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

            HDC imgHdc = mTexture->GetHdc();

            AlphaBlend(hdc
                , (int)(pos.x - (sprite.size.x / 2.0f))
                , (int)(pos.y - (sprite.size.y / 2.0f))
                , (int)(sprite.size.x * scale.x)
                , (int)(sprite.size.y * scale.y)
                , imgHdc
                , (int)sprite.leftTop.x
                , (int)sprite.leftTop.y
                , (int)sprite.size.x
                , (int)sprite.size.y
                , func);

        }
        else if (type == graphics::Texture::eTextureType::Png)
        {
            // 내가 원하는 픽셀을 투명화 시킬떄
            Gdiplus::ImageAttributes imgAtt = {};

            // 투명화 시킬 픽셀의 색 범위
            imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

            Gdiplus::Graphics graphics(hdc);

            graphics.TranslateTransform(pos.x, pos.y);
            graphics.RotateTransform(rot);
            graphics.TranslateTransform(-pos.x, -pos.y);

            graphics.DrawImage(mTexture->GetImage()
                , Gdiplus::Rect
                (
                    (int)(pos.x - (sprite.size.x / 2.0f))
                    , (int)(pos.y - (sprite.size.y / 2.0f))
                    , (int)(sprite.size.x * scale.x)
                    , (int)(sprite.size.y * scale.y)
                )
                , (int)sprite.leftTop.x
                , (int)sprite.leftTop.y
                , (int)sprite.size.x
                , (int)sprite.size.y
                , Gdiplus::UnitPixel
                , /*&imgAtt*/nullptr
            );
        }
    }

    void Animation::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet
        , Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLegth, float duration)
    {
        mTexture = spriteSheet;
        for (size_t i = 0; i < spriteLegth; i++)
        {
            Sprite sprite = {};
            sprite.leftTop.x = leftTop.x + (size.x * i);
            sprite.leftTop.y = leftTop.y;
            sprite.size = size;
            sprite.offset = offset;
            sprite.duration = duration;

            mAnimationSheet.push_back(sprite);
        }
    }

    void Animation::Reset()
    {
        mTime = 0.0f;
        mIndex = 0;
        mbComplete = false;
    }
}
