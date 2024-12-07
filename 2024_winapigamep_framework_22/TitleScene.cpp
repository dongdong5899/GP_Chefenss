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
	Texture* texture = GET_SINGLE(ResourceManager)->
		TextureLoad(L"GameStartBtn", L"Texture\\Unit_Card_Area.bmp");
	gameStartBtn->SetImage(texture, 1.f);
	Button* button = new Button();
	button->onClick += []() { GET_SINGLE(EventManager)->SceneChange(L"DefenseScene"); };
	gameStartBtn->AddComponent(button);
	AddObject(gameStartBtn, LAYER::UI);

	TextPro* gamestartTxt = new TextPro;
	gamestartTxt->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 185 });
	gamestartTxt->SetColor(RGB(255, 255, 255));
	gamestartTxt->SetFontSize(30);
	gamestartTxt->SetText(L"게임 시작");
	AddObject(gamestartTxt, LAYER::UI);
}

void TitleScene::Update()
{
	Scene::Update();
	
}
