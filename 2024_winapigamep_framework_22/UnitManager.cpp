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
#include "SceneManager.h"
#include "Scene.h"
#include "EventManager.h"
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
	if (wall) {
		if (wall->GetAssignedUnit()) {
			return nullptr;
		}
		unit = TypeUnitGenerate();
		unit->SetUnitType(GET_SINGLE(UnitManager)->GetUnitType());
		unit->SetPos(wall->GetPos());
		unit->RangeCheck();
		wall->SetAssignedUnit(unit);
	}
	else {
		return nullptr;
	}
	m_currentUnitType = UNIT_TYPE::END;
	m_prevUnitType = UNIT_TYPE::END;
	unit->SetDeploy(true);
	return unit;
}



void UnitManager::UnitSelect()
{
	if (m_currentUnitType != UNIT_TYPE::END) {
		if (m_currentUnitType != m_prevUnitType) {
			if (m_currentUnit) {
				GET_SINGLE(EventManager)->DeleteObject(m_currentUnit);
			}
			m_currentUnit = TypeUnitGenerate();
			GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(m_currentUnit,LAYER::PLAYER);
		}
		Vec2 mousePos = GET_SINGLE(MapManager)->PosToMapPos(GET_SINGLE(InputManager)->GetMousePos());
		vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();

		int mapWidth = map[1].size();
		int mapHeight = map.size();

		if (mousePos.x < 0 || mousePos.y < 0 || mousePos.x >= mapWidth || mousePos.y >= mapHeight) {
			m_currentUnit->SetPos(GET_SINGLE(InputManager)->GetMousePos());
		}
		else {
			Tile* tile = map[mousePos.y][mousePos.x];

			Wall* wall = dynamic_cast<Wall*>(tile);
			if (wall) { 
				if (wall->GetAssignedUnit()) 
					m_currentUnit->SetPos(GET_SINGLE(InputManager)->GetMousePos());
				else 
					m_currentUnit->SetPos(wall->GetPos());
			} 
		}
		m_prevUnitType = m_currentUnitType;
	}
	
}

void UnitManager::UnitDelete()
{
	if (m_currentUnit) {
		GET_SINGLE(EventManager)->DeleteObject(m_currentUnit);
		m_currentUnit = nullptr;
	}
}

void UnitManager::SetSelectMode(bool _selectMode)
{
	m_selectMode = _selectMode;
	if (!_selectMode) {
		m_prevUnitType = UNIT_TYPE::END;
	}
}

int UnitManager::GetUnitCost(UNIT_TYPE _unitType)
{
	return unitCost[(int)_unitType];
}


