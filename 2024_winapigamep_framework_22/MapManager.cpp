#include "pch.h"
#include "MapManager.h"
#include "InputManager.h"


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

Vec2 MapManager::PosToMapPos(Vec2 _pos)
{
	int size = GetTileSize();
	vector<vector<Tile*>> mapData = GetMapTileData();
	int height = mapData.size();
	int width = mapData[0].size();
	POINT startPos = { SCREEN_WIDTH / 2 + size / 2 - ((float)width / 2 + 0.5f) * size, SCREEN_HEIGHT / 2 + size / 2 - ((float)height / 2 + 0.5f) * size - 100 };

	int x = (_pos.x - startPos.x) / size;
	int y = (_pos.y - startPos.y) / size;

	cout << x << ", " << y << endl;

	return {x, y};
}

