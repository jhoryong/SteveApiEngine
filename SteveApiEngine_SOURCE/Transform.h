#pragma once
#include "Component.h"
#include "Entity.h"

namespace steve
{
	using namespace math;
	struct Pos
	{
		int mX;
		int mY;
	};

    class Transform : public Component
    {
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetPosition(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		Vector2 GetPosition() { return mPosition; }
		float GetRoation() { return mRotation; }
		Vector2 GetScale() { return mScale; }
		void SetRotation(float rotate) { mRotation = rotate; }
		void SetScale(Vector2 scale) { mScale = scale; }

	private:
		Vector2 mPosition;
		Vector2 mScale;
		float mRotation;
    };
}

