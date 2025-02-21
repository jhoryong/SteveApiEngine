#include "PlayScene.h"
#include "GameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManager.h"
#include "Object.h"
#include "Texture.h"
#include "Resources.h"
#include "PlayerScript.h"
#include "Camera.h"
#include "Renderer.h"
#include "Animator.h"


namespace steve
{

	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		GameObject* camera = object::Instantiate<GameObject>
			(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;


		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		//SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		//sr->SetSize(Vector2(3.0f, 3.f));
		mPlayer->AddComponent<PlayerScript>();

	    graphics::Texture* catTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(
			L"CatFrontMove",
			catTexture,
			Vector2(0.0f, 0.0f),
			Vector2(32.0f, 32.0f),
			Vector2::Zero,
			4,
			0.5f);
		//sr->SetTexture(packmanTexture);
		animator->PlayAnimation(L"CatFrontMove", true);

		GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
		bgSr->SetTexture(bgTexture);

		// 게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init함수를 호출
		Scene::Initialize();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		/*wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);*/
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		/*Transform* tr = bg->GetComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));*/
	}
}