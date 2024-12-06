#include "pch.h"
#include "TitleScene.h"
#include "Object.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "ButtonUI.h"
#include "Button.h"
#include "TextPro.h"

void TitleScene::Init()
{
	/*TextPro* titleTxt = new TextPro;
	titleTxt->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 150 });
	titleTxt->SetText(L"Gambit Streat");
	titleTxt->SetFontSize(100);
	AddObject(titleTxt, LAYER::UI);*/

	ButtonUI* gameStartBtn = new ButtonUI;
	gameStartBtn->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 200 });
	gameStartBtn->SetSize({250, 60});
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

void TitleScene::Update()
{
	Scene::Update();
	
}
