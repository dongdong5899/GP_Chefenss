#include "pch.h"
#include "TitleScene.h"
#include "Object.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "EventManager.h"
#include "ResourceManager.h"
#include "Button.h"
#include "TextPro.h"
#include "Image.h"

TitleScene::TitleScene()
{
	SetBackgroundTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"Background", L"Texture\\Background.bmp"));
	SetBackgroundScale(5.f);
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	TextPro* titleTxt = new TextPro;
	titleTxt->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 150 });
	titleTxt->SetText(L"Gambit Streat");
	titleTxt->SetFontSize(100);
	AddObject(titleTxt, LAYER::UI);

	Image* gameStartBtn = new Image;
	gameStartBtn->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 200 });
	gameStartBtn->SetSize({250, 60});

	gameStartBtn->SetImage(GET_SINGLE(ResourceManager)->
		TextureLoad(L"GameStartBtn", L"Texture\\Unit_Card_Area.bmp"),1);
	gameStartBtn->GetComponent<Button>()->onClick += []() { GET_SINGLE(SceneManager)->LoadScene(L"DefenseScene"); };
	AddObject(gameStartBtn, LAYER::UI);

		TextPro* gamestartTxt = new TextPro;
		gamestartTxt->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 185 });
		gamestartTxt->SetColor(RGB(255, 255, 255));
		gamestartTxt->SetFontSize(30);
		gamestartTxt->SetText(L"게임 시작");
		AddObject(gamestartTxt, LAYER::UI);
	}
	
	{
		Image* gameEndBtn = new Image;
		gameEndBtn->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 280 });
		gameEndBtn->SetSize({ 250, 60 });
		gameEndBtn->SetImage(GET_SINGLE(ResourceManager)->
			TextureLoad(L"GameStartBtn", L"Texture\\Unit_Card_Area.bmp"),1);
		gameEndBtn->GetComponent<Button>()->onClick += [this]() { Quit(); };
		AddObject(gameEndBtn, LAYER::UI);

		TextPro* gamestartTxt = new TextPro;
		gamestartTxt->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 265 });
		gamestartTxt->SetColor(RGB(255, 255, 255));
		gamestartTxt->SetFontSize(30);
		gamestartTxt->SetText(L"게임 종료");
		AddObject(gamestartTxt, LAYER::UI);
	}
}

void TitleScene::Update()
{
	Scene::Update();
}
