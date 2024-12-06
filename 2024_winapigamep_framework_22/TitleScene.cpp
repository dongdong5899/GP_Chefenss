#include "pch.h"
#include "TitleScene.h"
#include "Object.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "Button.h"
#include "ButtonUI.h"
#include "TextPro.h"


void TitleScene::Init()
{
	//Object* pObj = new Enemy;
	//pObj->SetPos({ SCREEN_WIDTH / 2.f,150.f });
	//pObj->SetSize({ 100.f,100.f });
	//pObj->SetName(L"Enemy");
	//AddObject(pObj, LAYER::ENEMY);

	//Object* pPlayer = new Player;
	//pPlayer->SetPos({ SCREEN_WIDTH / 2.f,500.f });
	//pPlayer->SetSize({ 100.f,100.f });
	//AddObject(pPlayer, LAYER::PLAYER);
	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);
	////GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
	//GET_SINGLE(ResourceManager)->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	//GET_SINGLE(ResourceManager)->Play(L"BGM");


	GET_SINGLE(ResourceManager)->LoadSound(L"BGM", L"Sound\\BGM.wav",true);
	GET_SINGLE(ResourceManager)->Play(L"BGM");
	{
		TextPro* titleText = new TextPro();
		titleText->SetScale(5.f);
		titleText->SetText(L"Chefense");
		titleText->SetPos({ SCREEN_WIDTH/2,SCREEN_HEIGHT/2 });
		AddObject(titleText, LAYER::UI);
	}
}

void TitleScene::Update()
{
	Scene::Update();
	if (GET_KEYDOWN(KEY_TYPE::ENTER))
		GET_SINGLE(SceneManager)->LoadScene(L"DefenseScene");
}
