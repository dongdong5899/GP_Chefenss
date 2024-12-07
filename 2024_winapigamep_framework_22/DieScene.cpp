#include "pch.h"
#include "DieScene.h"
#include "TextPro.h"
#include "Image.h"
#include "Button.h"
#include "ResourceManager.h"
#include "EventManager.h"

DieScene::DieScene()
{
	SetBackgroundTexture(GET_SINGLE(ResourceManager)
		->TextureLoad(L"Clear_Background", L"Textur\\Clear_Background.bmp"));
}

DieScene::~DieScene()
{
}

void DieScene::Init()
{
	TextPro* endText = new TextPro;
	endText->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	endText->SetText(L"저런...\n분발합시다...");

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
