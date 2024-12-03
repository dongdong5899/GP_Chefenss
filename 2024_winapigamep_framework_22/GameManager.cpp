#include "pch.h"
#include "GameManager.h"



void GameManager::Init()
{
	SetCoin(300);
}

bool GameManager::CanBuy(int cost)
{
	if (coin >= cost) {
		coin-=cost;
		return true;
	}
	return false;
}
