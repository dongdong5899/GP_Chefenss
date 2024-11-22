#include "pch.h"
#include "MapManager.h"


void MapManager::Init()
{
}

void MapManager::Update()
{
}

void MapManager::SetMapMode(MAP_SIZE _mapSize)
{
	m_mapSize = _mapSize;
	m_currentMapStrVec = m_mapStrVec[(int)m_mapSize];
}

int MapManager::GetTileSize()
{
	int height = m_currentMapStrVec.size();
	int size = 400 / height;
	return size;
}

Vec2 MapManager::MapToPos(Vec2 _mapPos)
{


	return Vec2();
}

