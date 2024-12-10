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
	SetBackgroundScale(5.5f);
}

ClearScene::~ClearScene()
{
}

void ClearScene::Init()
{
	{
		TextPro* endText = new TextPro;
		endText->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 150 });
		endText->SetText(L"클리어 하셨군요!\n당신은 쩌는 사람입니다!");
		endText->SetColor(RGB(255, 255, 255));
		endText->SetFontSize(100.f);
		AddObject(endText, LAYER::UI);
	}

	{
		Image* exitBtn = new Image();
		exitBtn->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100 });
		exitBtn->SetSize({ 250, 65 });
		Texture* cardTexture = GET_SINGLE(ResourceManager)->
			TextureLoad(L"ButtonArea", L"Texture\\Unit_Card_Area.bmp");
		exitBtn->SetImage(cardTexture, 1.f);

		Button* button = new Button;
		button->onClick += []() { GET_SINGLE(EventManager)->SceneChange(L"TitleScene"); };
		exitBtn->AddComponent(button);
		AddObject(exitBtn, LAYER::UI);

		TextPro* exitTxt = new TextPro;
		exitTxt->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT - 110 });
		exitTxt->SetColor(RGB(255, 255, 255));
		exitTxt->SetText(L"타이틀로");
		exitTxt->SetFontSize(30);
		AddObject(exitTxt, LAYER::UI);
	}
}
