#include "PlayScene.h"
#include "GameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"

steve::PlayScene::PlayScene()
{
}

steve::PlayScene::~PlayScene()
{
}

void steve::PlayScene::Initialize()
{
	/*for (size_t i = 0; i < 100; i++)
	{
		GameObject* obj = new GameObject();
		obj->SetPosition(rand() % 1600, rand() % 900);
		AddGameObject(obj);
	}*/
	/*Player* player = new Player();
	Transform* transform = player->AddComponent<Transform>();
	transform->SetPos(800, 450);
	transform->SetName(L"Transform");
	SpriteRenderer* spriteRenderer = player->AddComponent<SpriteRenderer>();
	spriteRenderer->SetName(L"SpriteRenderer");
	AddGameObject(player);*/
	Player* bg = new Player();
	Transform* tr = bg->AddComponent<Transform>();
	tr->SetPos(Vector2(0, 0));
	tr->SetName(L"TR");
	SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
	sr->SetName(L"SR");
	sr->ImageLoad(L"../Resources/gura.jpeg");
	AddGameObject(bg);
}

void steve::PlayScene::Update()
{
	Scene::Update();
}

void steve::PlayScene::LateUpdate()
{
	Scene::LateUpdate();
}

void steve::PlayScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
