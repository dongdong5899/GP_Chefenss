#include "pch.h"
#include "Knight.h"
#include "MapManager.h"
Knight::Knight()
{
}

Knight::~Knight()
{
}

void Knight::Update()
{
}

void Knight::Render(HDC _hdc)
{
}



void Knight::RangeCheck()
{
	vector<vector<Object*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	for (int i = 0; i < 8; i++) {
		Object* tile = map[(int)(m_tilePos.x + xAttackRange[i])][(int)(m_tilePos.y + yAttackRange[i])];
		Road* road = dynamic_cast<Road*>(tile);
		if (road)
		{
			attackRange.push_back(road);
		}
	}
}
