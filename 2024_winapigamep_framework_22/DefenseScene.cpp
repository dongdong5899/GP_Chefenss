#include "pch.h"
#include "DefenseScene.h"
#include "Object.h"
#include "Road.h"
#include "Wall.h"
#include "MapManager.h"

void DefenseScene::Init()
{
	GET_SINGLE(MapManager)->SetMapSize(MAP_SIZE::BIG);
	vector<wstring> map = GET_SINGLE(MapManager)->GetMap();
	int size = GET_SINGLE(MapManager)->GetTileSize();
	int yPos = 100;
	int height = map.size();
	int width = map[0].size();
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			Object* pObj = nullptr;
			if (map[y][x] == L'бс')
			{
				pObj = new Road;
				pObj->SetName(L"Road");
			}
			else if (map[y][x] == L'бр')
			{
				pObj = new Wall;
				pObj->SetName(L"Wall");
			}
			else
			{
				pObj = new Road;
				pObj->SetName(L"Road");
			}
			pObj->SetPos({ SCREEN_WIDTH / 2 + size / 2 + (x - (float)width / 2) * size, SCREEN_HEIGHT / 2 + size / 2 + (y - (float)height / 2) * size - yPos });
			pObj->SetSize({ size, size });
			AddObject(pObj, LAYER::BACKGROUND);
		}
	}
}
