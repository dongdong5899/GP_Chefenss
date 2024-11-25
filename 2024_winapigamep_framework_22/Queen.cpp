#include "pch.h"
#include "Queen.h"
#include "MapManager.h"
Queen::Queen()
{
}

Queen::~Queen()
{
}

void Queen::Update()
{
}

void Queen::Render(HDC _hdc)
{
}



void Queen::RangeCheck()
{
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	for (int i = 0; i < 8; i++) {
		Vec2 attackCheckPos = m_tilePos;
		while (true) {
			if (attackCheckPos.x < 0 || attackCheckPos.y < 0 || map[0].size() < attackCheckPos.x || map.size() < attackCheckPos.y) {
				break;
			}
			attackCheckPos.x += xAttackRange[i];
			attackCheckPos.y += yAttackRange[i];
			Tile* tile = map[(int)(attackCheckPos.x)][(int)(attackCheckPos.y)];
			Road* road = dynamic_cast<Road*>(tile);
			if (road)
			{
				attackRange.push_back(road);
			}
		}
	}
}
