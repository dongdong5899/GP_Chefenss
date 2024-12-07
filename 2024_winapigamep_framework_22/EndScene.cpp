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
		endText->SetText(L"Ŭ���� �ϼ̱���!\n����� �� ġ�»���Դϴ�!");
	else
		endText->SetText(L"����.. �׾�����....\nŬ�������� �����ڿ��� ����� ��ġ�Դϴ�.\n�ٽ��ϼ���.");


}
