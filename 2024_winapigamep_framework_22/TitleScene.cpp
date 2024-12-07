#include "pch.h"
#include "TitleScene.h"
#include "Object.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "Button.h"
#include "TextPro.h"
#include "Image.h"


TitleScene::TitleScene()
{
	SetBackgroundTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"Background", L"Texture\\titleBackground.bmp"));
	SetBackgroundScale(2.3f);
	GET_SINGLE(ResourceManager)->LoadSound(L"BGM", L"Sound\\BGM.wav", true);
	GET_SINGLE(ResourceManager)->Play(L"BGM");
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	{
		TextPro* titleTxt = new TextPro;
		titleTxt->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 150 });
		titleTxt->SetText(L"Gambit Streat");
		titleTxt->SetFontSize(150);
		AddObject(titleTxt, LAYER::UI);
	}

	{
		Image* gameStartBtn = new Image;
		gameStartBtn->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 100 });
		gameStartBtn->SetSize({ 250, 60 });
		gameStartBtn->SetImage(GET_SINGLE(ResourceManager)->
			TextureLoad(L"GameStartBtn", L"Texture\\Unit_Card_Area.bmp"),1);
		Button* button = new Button;
		button->onClick += []() { GET_SINGLE(SceneManager)->LoadScene(L"MapSelectScene"); };
		gameStartBtn->AddComponent(button);
		AddObject(gameStartBtn, LAYER::UI);

		TextPro* gamestartTxt = new TextPro;
		gamestartTxt->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 85 });
		gamestartTxt->SetColor(RGB(255, 255, 255));
		gamestartTxt->SetFontSize(30);
		gamestartTxt->SetText(L"게임 시작");
		AddObject(gamestartTxt, LAYER::UI);
	}

	{
		Image* gameEndBtn = new Image;
		gameEndBtn->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 180 });
		gameEndBtn->SetSize({ 250, 60 });
		gameEndBtn->SetImage(GET_SINGLE(ResourceManager)->
			TextureLoad(L"GameEndBtn", L"Texture\\Unit_Card_Area.bmp"),1);
		Button* button = new Button;
		button->onClick += [this]() { Quit(); };
		gameEndBtn->AddComponent(button);
		AddObject(gameEndBtn, LAYER::UI);

		TextPro* gamestartTxt = new TextPro;
		gamestartTxt->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 165 });
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

void TitleScene::Quit()
{
	ExitProcess(0);
}