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
		// main camera
		GameObject* camera = object::Instantiate<GameObject>
			(enums::eLayerType::Particle, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;


		mPlayer = object::Instantiate<Player>(enums::eLayerType::Particle);
		//SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		//sr->SetSize(Vector2(3.0f, 3.f));
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();

		animator->CreateAnimation(L"DownWalk", packmanTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"RightWalk", packmanTexture
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"UpWalk", packmanTexture
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"LeftWalk", packmanTexture
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"SitDown", packmanTexture
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"Grooming", packmanTexture
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		animator->PlayAnimation(L"SitDown", false);


		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		//mPlayer->GetComponent<Transform>()->SetRotation(30.0f);
		/*sr->SetTexture(packmanTexture);*/

		GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::Player);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		//bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Bubble");
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