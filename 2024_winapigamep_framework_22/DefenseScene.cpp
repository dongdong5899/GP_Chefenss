#include "pch.h"
#include "DefenseScene.h"
#include "Object.h"
#include "Road.h"
#include "Wall.h"
#include "Enemy.h"
#include "MapManager.h"

void DefenseScene::Init()
{
	GET_SINGLE(MapManager)->SetMapMode(MAP_SIZE::BIG);
	vector<wstring> map = GET_SINGLE(MapManager)->GetMapStrData();
	int size = GET_SINGLE(MapManager)->GetTileSize();
	int yPos = 100;
	int height = map.size();
	int width = map[0].size();
	vector<vector<Object*>> m_currentMapTileVec;
	for (int y = 0; y < height; ++y)
	{
		vector<Object*> tileLine;
		for (int x = 0; x < width; ++x)
		{
			Object* pObj = nullptr;
			if (map[y][x] == L'бс')
			{
				pObj = new Wall;
				pObj->SetName(L"Wall");
			}
			else
			{
				if (map[y][x] == L'S')
					m_startPos = { x, y };
				pObj = new Road;
				pObj->SetName(L"Road");
			}
			pObj->SetPos({ SCREEN_WIDTH / 2 + size / 2 + (x - (float)width / 2) * size, SCREEN_HEIGHT / 2 + size / 2 + (y - (float)height / 2) * size - yPos });
			pObj->SetSize({ size, size });
			AddObject(pObj, LAYER::BACKGROUND);
			tileLine.push_back(pObj);
		}
		m_currentMapTileVec.push_back(tileLine);
	}
	GET_SINGLE(MapManager)->SetMapTileData(m_currentMapTileVec);


	Enemy* pEnemy = new Enemy;
	pEnemy->SetName(L"Enemy");
	pEnemy->SetPos(GET_SINGLE(MapManager)->GetMapTileData()[m_startPos.y][m_startPos.x]->GetPos());
	pEnemy->SetSize({ size * 0.9f, size * 0.9f });
	AddObject(pEnemy, LAYER::ENEMY);
}
