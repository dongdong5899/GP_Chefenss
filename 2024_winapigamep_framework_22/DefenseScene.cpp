#include "pch.h"
#include "DefenseScene.h"
#include "Object.h"
#include "Road.h"
#include "Wall.h"
#include "Enemy.h"
#include "MapManager.h"
#include "InputManager.h"

void DefenseScene::Init()
{
	GET_SINGLE(MapManager)->SetMapMode(MAP_SIZE::SMALL);
	vector<wstring> map = GET_SINGLE(MapManager)->GetMapStrData();
	int size = GET_SINGLE(MapManager)->GetTileSize();
	int yPos = 100;
	int height = map.size();
	int width = map[0].size();
	vector<vector<Tile*>> m_currentMapTileVec;
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
			pTile->SetPos({ SCREEN_WIDTH / 2 + size / 2 + (x - (float)width / 2) * size, SCREEN_HEIGHT / 2 + size / 2 + (y - (float)height / 2) * size - yPos });
			pTile->SetSize({ size, size });
			AddObject(pTile, LAYER::BACKGROUND);
			tileLine.push_back(pTile);
		}
		m_currentMapTileVec.push_back(tileLine);
	}
	GET_SINGLE(MapManager)->SetMapTileData(m_currentMapTileVec);


	Enemy* pEnemy = new Enemy;
	pEnemy->SetName(L"Enemy");
	pEnemy->SetSize({ size * 0.9f, size * 0.9f });
	AddObject(pEnemy, LAYER::ENEMY);
	GET_SINGLE(MapManager)->GetStartRoad()->AssignEnemy(pEnemy);
}

void DefenseScene::Update()
{
	GET_SINGLE(MapManager)->PosToMapPos(GET_SINGLE(InputManager)->GetMousePos());
}
