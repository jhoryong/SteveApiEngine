#pragma once
#include "../SteveApiEngine_SOURCE/GameObject.h"

namespace steve
{
	class Cat :
		public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	
	};
}


