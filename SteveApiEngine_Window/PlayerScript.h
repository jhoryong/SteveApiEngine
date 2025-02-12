#pragma once
#include "../SteveApiEngine_SOURCE/Script.h"
namespace steve
{
	class PlayerScript: public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


	private:

	};
}
