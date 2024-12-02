#include "pch.h"
#include "UnitManager.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "MapManager.h"
#include "InputManager.h"
#include "Wall.h"

void UnitManager::Init()
{
	m_currentUnitType = UNIT_TYPE::END;
	m_prevUnitType = UNIT_TYPE::END;
}

void UnitManager::Update()
{
}

Unit* UnitManager::TypeUnitGenerate()
{
	switch (m_currentUnitType)
	{
	case UNIT_TYPE::PAWN:
		return new Pawn;
	case UNIT_TYPE::KNIGHT:
		return new Knight;
	case UNIT_TYPE::BISHOP:
		return new Bishop;
	case UNIT_TYPE::ROOK:
		return new Rook;
	case UNIT_TYPE::QUEEN:
		return new Queen;
	case UNIT_TYPE::END:
		return nullptr;
	}
}

Unit* UnitManager::UnitGenerate()
{
 	Vec2 mousePos = GET_SINGLE(MapManager)->PosToMapPos(GET_SINGLE(InputManager)->GetMousePos());
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	int mapWidth = map[1].size();
	int mapHeight = map.size();
	if (mousePos.x < 0 || mousePos.y < 0 || mousePos.x >= mapWidth || mousePos.y >= mapHeight) {
		return nullptr;
	}
	Unit* unit = nullptr;

	Tile* tile = GET_SINGLE(MapManager)->GetMapTileData()[mousePos.y][mousePos.x];
	Wall* wall = dynamic_cast<Wall*>(tile);
	cout << wall->GetPos().x;
	if (wall) {
		if (wall->GetAssignedUnit()) {
			return nullptr;
		}
		unit = TypeUnitGenerate();
		unit->SetUnitType(GET_SINGLE(UnitManager)->GetUnitType());
		unit->SetPos(wall->GetPos());
		wall->SetAssignedUnit(unit);
	}
	m_currentUnitType = UNIT_TYPE::END;
	return unit;
}



void UnitManager::UnitSelect()
{
	if (m_currentUnitType != UNIT_TYPE::END) {
		if (m_currentUnitType != m_prevUnitType)
			m_currentUnit = TypeUnitGenerate();
		Vec2 mousePos = GET_SINGLE(MapManager)->PosToMapPos(GET_SINGLE(InputManager)->GetMousePos());
		vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
		int mapWidth = map[1].size();
		int mapHeight = map.size();
		if (mousePos.x < 0 || mousePos.y < 0 || mousePos.x >= mapWidth || mousePos.y >= mapHeight) {
			return;
		}
		Tile* tile = GET_SINGLE(MapManager)->GetMapTileData()[mousePos.y][mousePos.x];
		Wall* wall = dynamic_cast<Wall*>(tile);
		if (wall) {
			if (wall->GetAssignedUnit()) {
				return;
			}
			m_currentUnit->SetPos(wall->GetPos());
		}
		m_prevUnitType = m_currentUnitType; 
	}
}


