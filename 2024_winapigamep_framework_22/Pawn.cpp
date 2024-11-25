#include "pch.h"
#include "Pawn.h"
#include "MapManager.h"
#include "Road.h"
#include "TimeManager.h"
Pawn::Pawn()
{
}
Pawn::~Pawn()
{
}
void Pawn::Update()
{
}

void Pawn::Render(HDC _hdc)
{
}



void Pawn::RangeCheck()
{
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	for (int i = 0; i < 4; i++) {
		Tile* tile = map[(int)(m_tilePos.x + xAttackRange[i])][(int)(m_tilePos.y + yAttackRange[i])];
		Road* road = dynamic_cast<Road*>(tile);
		if (road) 
		{
			attackRange.push_back(road);
		}
	}
}



