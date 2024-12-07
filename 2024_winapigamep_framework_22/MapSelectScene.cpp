#include "pch.h"
#include "MapSelectScene.h"
#include "TextPro.h"
#include "Image.h"
#include "Button.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "MapManager.h"
#include "Texture.h"


MapSelectScene::MapSelectScene()
{
	SetBackgroundTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"Background", L"Texture\\Background.bmp"));
	SetBackgroundScale(5.f);
}

MapSelectScene::~MapSelectScene()
{
}

void MapSelectScene::Init()
{
	TextPro* titleTxt = new TextPro;
	titleTxt->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 250 });
	titleTxt->SetText(L"맵을 고르세요");
	titleTxt->SetFontSize(100);
	AddObject(titleTxt, LAYER::UI);

	int width = 700;
	int count = (int)MAP_SIZE::END;
	wstring sizeText[3] = { L"작은거", L"좀 있는거", L"큰거" };
	for (int i = 0; i < count; i++)
	{
		Image* gameStartBtn = new Image;
		gameStartBtn->SetPos({ SCREEN_WIDTH / 2 - width / 2 + i * (width / (count - 1)), SCREEN_HEIGHT / 2 + 100 });
		gameStartBtn->SetSize({ 260, 340 });
		Texture* texture = GET_SINGLE(ResourceManager)->
			TextureLoad(L"Card_Background", L"Texture\\Unit_Card_Background.bmp");
		gameStartBtn->SetImage(texture, 10.f);
		Button* button = new Button();
		button->onClick += [i]() 
			{
				GET_SINGLE(MapManager)->SetMapSize((MAP_SIZE)i);
				GET_SINGLE(EventManager)->SceneChange(L"DefenseScene"); 
			};
		gameStartBtn->AddComponent(button);
		AddObject(gameStartBtn, LAYER::UI);

		TextPro* gamestartTxt = new TextPro;
		gamestartTxt->SetPos({ SCREEN_WIDTH / 2 - width / 2 + i * (width / (count - 1)), SCREEN_HEIGHT / 2 + 85 });
		gamestartTxt->SetColor(RGB(255, 255, 255));
		gamestartTxt->SetFontSize(30);
		gamestartTxt->SetText(sizeText[i]);
		AddObject(gamestartTxt, LAYER::UI);
	}

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