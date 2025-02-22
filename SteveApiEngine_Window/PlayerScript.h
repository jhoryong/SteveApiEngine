#pragma once
#include "..\\SteveApiEngine_SOURCE\\Script.h"
namespace steve
{
	class PlayerScript: public Script
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			Attack,
			Idle,
			GiveWater,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


		void AttackEffect();
	private:
		void idle();
		void move();
		void giveWater();

	private:
		eState mState;
		class Animator* mAnimator;
	};
}
