#include "pch.h"
#include "EnemyManager.h"
#include "PawnEnemy.h"
#include "KnightEnemy.h"
#include "BishopEnemy.h"
#include "RookEnemy.h"
#include "QueenEnemy.h"
#include "MapManager.h"
#include "Road.h"

#include <concepts>

Enemy* EnemyManager::GetTypeEnemy(UNIT_TYPE _type)
{
	Enemy* pEnemy = nullptr;
	switch (_type)
	{
	case UNIT_TYPE::PAWN:
		pEnemy = new PawnEnemy;
		break;
	case UNIT_TYPE::KNIGHT:
		pEnemy = new KnightEnemy;
		break;
	case UNIT_TYPE::BISHOP:
		pEnemy = new BishopEnemy;
		break;
	case UNIT_TYPE::ROOK:
		pEnemy = new RookEnemy;
		break;
	case UNIT_TYPE::QUEEN:
		pEnemy = new QueenEnemy;
		break;
	case UNIT_TYPE::END:
		break;
	default:
		break;
	}

	return pEnemy;
}

Enemy* EnemyManager::CreateEnemy(UNIT_TYPE _type)
{
	Enemy* pEnemy = GetTypeEnemy(_type);

	if (pEnemy != nullptr)
	{
		int size = GET_SINGLE(MapManager)->GetTileSize();
		pEnemy->SetName(L"Enemy");
		pEnemy->SetSize({ size, size });
		GET_SINGLE(MapManager)->GetStartRoad()->AssignEnemy(pEnemy);
		return pEnemy;
	}
}
