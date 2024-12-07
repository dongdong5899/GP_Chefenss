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

void TitleScene::Init()
{
	{
		Image* background = new Image();
		Texture* backgroundTexture = GET_SINGLE(ResourceManager)->TextureLoad(L"TitleBackGround", L"Textur\\titleBackground.bmp");
		background->SetImage(backgroundTexture,1);
		background->SetPos({ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });
		AddObject(background, LAYER::UI);
	}
	
	/*{
		Image* whiteQueen = new Image();
	}*/

	
	{
		TextPro* titleTxt = new TextPro;
		titleTxt->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 150 });
		titleTxt->SetText(L"Gambit Streat");
		titleTxt->SetFontSize(100);
		AddObject(titleTxt, LAYER::UI);
	}

	{
		ButtonUI* gameStartBtn = new ButtonUI;
		gameStartBtn->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 200 });
		gameStartBtn->SetSize({ 250, 60 });
		gameStartBtn->SetScale(1.f);
		gameStartBtn->SetTexture(GET_SINGLE(ResourceManager)->
			TextureLoad(L"GameStartBtn", L"Texture\\Unit_Card_Area.bmp"));
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
		ButtonUI* gameEndBtn = new ButtonUI;
		gameEndBtn->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 280 });
		gameEndBtn->SetSize({ 250, 60 });
		gameEndBtn->SetScale(1.f);
		gameEndBtn->SetTexture(GET_SINGLE(ResourceManager)->
			TextureLoad(L"GameStartBtn", L"Texture\\Unit_Card_Area.bmp"));
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

void TitleScene::Quit()
{
	ExitProcess(0); 
}
