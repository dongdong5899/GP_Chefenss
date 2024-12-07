#include "pch.h"
#include "MapManager.h"
#include "InputManager.h"
#include "Scene.h"
#include "Tile.h"
#include "Wall.h"
#include "Road.h"


void MapManager::Init()
{
	SetMapOffset({ 200, -50 });
}

void MapManager::Update()
{
}

void MapManager::SetMapSize(MAP_SIZE _mapSize)
{
	m_mapSize = _mapSize;
	m_currentMapStrVec = m_mapStrVec[(int)m_mapSize];
}

vector<Object*> MapManager::CreateTiles()
{
	vector<wstring> map = GetMapStrData();
	int size = GET_SINGLE(MapManager)->GetTileSize();

	Vec2 offset = GetMapOffset();
	int height = map.size();
	int width = map[0].size();

	vector<Object*> m_currentMapTileVec;
	vector<vector<Tile*>> TileVec;
	for (int y = 0; y < height; ++y)
	{
		vector<Tile*> tileLine;
		for (int x = 0; x < width; ++x)
		{
			Tile* pTile = nullptr;
			if (map[y][x] == L'бс')
			{
				pTile = new Wall;
				pTile->SetName(L"Wall");
			}
			else
			{
				pTile = new Road;
				pTile->SetName(L"Road");
				if (map[y][x] == L'S')
					GET_SINGLE(MapManager)->SetStartRoad(dynamic_cast<Road*>(pTile));
			}
			pTile->SetTilePos({ x, y });
			int xPos = SCREEN_WIDTH / 2 + size / 2 + (x - (float)width / 2) * size + offset.x;
			int yPos = SCREEN_HEIGHT / 2 + size / 2 + (y - (float)height / 2) * size + offset.y;
			pTile->SetPos({ xPos ,yPos });
			pTile->SetSize({ size, size });
			m_currentMapTileVec.push_back(pTile);
			tileLine.push_back(pTile);
		}
		TileVec.push_back(tileLine);
	}
	SetMapTileData(TileVec);

	return m_currentMapTileVec;
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
	Vec2 offset = GetMapOffset();
	int xPos = SCREEN_WIDTH / 2 + size / 2 - ((float)width / 2 + 0.5f) * size + offset.x;
	int yPos = SCREEN_HEIGHT / 2 + size / 2 - ((float)height / 2 + 0.5f) * size + offset.y;
	POINT startPos = { xPos, yPos };

	int x = (_pos.x - startPos.x) / size;
	int y = (_pos.y - startPos.y) / size;

	return {x, y};
}

