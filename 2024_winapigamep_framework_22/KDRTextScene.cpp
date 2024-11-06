#include "pch.h"
#include "KDRTextScene.h"
#include "Object.h"
#include "Road.h"
#include "Wall.h"

void KDRTextScene::Init()
{
	wstring mapStr[5] =
	{
		L"10000",
		L"11100",
		L"10001",
		L"10111",
		L"11110",
	};

	int size = 30;
	for (int y = 0; y < 5; ++y)
	{
		for (int x = 0; x < 5; ++x)
		{
			Object* pObj = nullptr;
			if (mapStr[y][x] == '1')
			{
				pObj = new Road;
				pObj->SetName(L"Road");
			}
			else
			{
				pObj = new Wall;
				pObj->SetName(L"Wall");
			}
			pObj->SetPos({ size / 2 + x * size, size / 2 + y * size });
			pObj->SetSize({ size, size });
			AddObject(pObj, LAYER::BACKGROUND);
		}
	}
}
