#include "pch.h"
#include "EndScene.h"
#include "TextPro.h"
#include "GameManager.h"

EndScene::EndScene()
{
}

EndScene::~EndScene()
{
}

void EndScene::Init()
{
	TextPro* endText = new TextPro;
	endText->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	if (GET_SINGLE(GameManager)->GetEndState())
		endText->SetText(L"클리어 하셨군요!\n당신은 좀 치는사람입니다!");
	else
		endText->SetText(L"저런.. 죽었군요....\n클리어하지 못한자에게 배경은 사치입니다.\n다시하세요.");


}
