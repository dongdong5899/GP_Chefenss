#pragma once
#include "MapManager.h"
#include "Enemy.h"
class Enemy;
class EnemyManager
{
	DECLARE_SINGLE(EnemyManager);
public:
	template<typename T>
	Enemy* CreateEnemy()
	{
		int size = GET_SINGLE(MapManager)->GetTileSize();
		T* pEnemy = new T;
		Enemy* castEnemy = nullptr;
		castEnemy = dynamic_cast<Enemy*>(pEnemy);

		if (castEnemy != nullptr)
		{
			castEnemy->SetName(L"Enemy");
			castEnemy->SetSize({ size * 0.9f, size * 0.9f });
			GET_SINGLE(MapManager)->GetStartRoad()->AssignEnemy(pEnemy);
			return castEnemy;
		}
		else
		{
			delete pEnemy;
			return nullptr;
		}
	}
};

