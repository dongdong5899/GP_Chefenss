#include "pch.h"
#include "ClearScene.h"
#include "TextPro.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "Image.h"
#include "Button.h"

ClearScene::ClearScene()
{
	SetBackgroundTexture(GET_SINGLE(ResourceManager)
		->TextureLoad(L"ClearBackground", L"Texture\\Clear_Background.bmp"));
	SetBackgroundScale(5.f);
}

ClearScene::~ClearScene()
{
}

void ClearScene::Init()
{
	TextPro* endText = new TextPro;
	endText->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	endText->SetText(L"클리어 하셨군요!\n당신은 좀 치는사람입니다!");

	Image* exitBtn = new Image();
	exitBtn->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT - 50 });
	exitBtn->SetSize({ 150, 40 });
	Texture* cardTexture = GET_SINGLE(ResourceManager)->
		TextureLoad(L"ButtonArea", L"Texture\\Unit_Card_Area.bmp");
	exitBtn->SetImage(cardTexture, 0.6f);

	Button* button = new Button;
	button->onClick += []() { GET_SINGLE(EventManager)->SceneChange(L"TitleScene"); };
	exitBtn->AddComponent(button);
	AddObject(exitBtn, LAYER::UI);

	TextPro* exitTxt = new TextPro;
	exitTxt->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT - 60 });
	exitTxt->SetColor(RGB(255, 255, 255));
	exitTxt->SetText(L"타이틀로");
	exitTxt->SetFontSize(20);
	AddObject(exitTxt, LAYER::UI);
}
