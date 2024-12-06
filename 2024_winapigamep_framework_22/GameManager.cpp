#include "pch.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "DefenseScene.h"
#include "TextPro.h"
#include "UnitManager.h"


void GameManager::Init()
{
	SetCoin(10000);
}

void GameManager::SetCoin(int _coin)
{
	coin = _coin;
	CheckUnitCost();
	UpdateShopText();         
}

void GameManager::AddCoin(int _add)
{
	coin += _add;
	CheckUnitCost();
	UpdateShopText();
}

bool GameManager::CanBuy(int cost)
{
	if (coin >= cost)
		return true;
	return false;
}

void GameManager::Buy(UNIT_TYPE _unitType)
{
	coin -= GET_SINGLE(UnitManager)->GetUnitCost(_unitType);
	CheckUnitCost();
	UpdateShopText();
}

void GameManager::CheckUnitCost()
{
	std::shared_ptr<Scene> curScene = GET_SINGLE(SceneManager)->GetCurrentScene();
	DefenseScene* scene = dynamic_cast<DefenseScene*>(curScene.get());
	if (scene) {
		for (int i = 0; i < 5; i++) {
			if (coin >= GET_SINGLE(UnitManager)->GetUnitCostVec()[i]) {
				scene->SetCostTextColor(i, RGB(255,255,0));
			}
			else {
				scene->SetCostTextColor(i, RGB(255, 0, 0));
			}
		}
	}
}

void GameManager::Hit()
{
	int health = GetHealth();
	health--;
	SetHealth(health);
	if (health == 0)
		Die();
}



void GameManager::UpdateShopText()
{
	std::shared_ptr<Scene> curScene = GET_SINGLE(SceneManager)->GetCurrentScene();
	DefenseScene* scene = dynamic_cast<DefenseScene*>(curScene.get());
	if (scene) {
		TextPro* goldTxt = scene->GetGoldText();
		goldTxt->SetText(L"Gold : " + std::to_wstring(GET_SINGLE(GameManager)->GetCoin()));
	}
}

void GameManager::UpdateHealth()
{
}

void GameManager::Die()
{
}
