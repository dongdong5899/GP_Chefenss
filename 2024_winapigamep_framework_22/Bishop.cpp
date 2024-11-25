#include "pch.h"
#include "Bishop.h"
#include "MapManager.h"
Bishop::Bishop()
{
}

Bishop::~Bishop()
{
}

void Bishop::Update()
{
}

void Bishop::Render(HDC _hdc)
{
}


void Bishop::RangeCheck()
{
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	for (int i = 0; i < 4; i++) {
		Vec2 attackCheckPos = m_tilePos;
		while (true) {
			if (attackCheckPos.x < 0 || attackCheckPos.y < 0 || map[0].size() < attackCheckPos.x || map.size() < attackCheckPos.y) {
				break;
			}
			attackCheckPos.x += xAttackRange[i];
			attackCheckPos.y += yAttackRange[i];
			Object* tile = map[(int)(attackCheckPos.x)][(int)(attackCheckPos.y)];
			Road* road = dynamic_cast<Road*>(tile);
			if (road)
			{
				attackRange.push_back(road);
			}
		}
	}
}
