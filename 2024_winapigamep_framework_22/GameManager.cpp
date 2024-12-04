#include "pch.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "DefenseScene.h"
#include "TextPro.h"

void GameManager::Init()
{
	SetCoin(300);
}

void GameManager::SetCoin(int _coin)
{
	coin = _coin;
	ChangeText();
}

void GameManager::AddCoin(int _add)
{
	coin += _add;
	ChangeText();
}

bool GameManager::CanBuy(int cost)
{
	if (coin >= cost) {
		coin-=cost;
		ChangeText();
		return true;
	}
	return false;
}

void GameManager::ChangeText()
{
	std::shared_ptr<Scene> curScene = GET_SINGLE(SceneManager)->GetCurrentScene();
	DefenseScene* scene = dynamic_cast<DefenseScene*>(curScene.get());
	if (scene) {
		TextPro* goldTxt = scene->GetGoldText();
		goldTxt->SetText(L"Gold : " + std::to_wstring(GET_SINGLE(GameManager)->GetCoin()));
	}
}
