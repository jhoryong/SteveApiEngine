#pragma once
#include "../SteveApiEngine_SOURCE/Scene.h"
namespace steve
{
    class TitleScene :
        public Scene
    {
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
    };
}
