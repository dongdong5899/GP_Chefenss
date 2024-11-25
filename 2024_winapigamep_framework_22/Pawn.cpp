#include "pch.h"
#include "Pawn.h"
#include "MapManager.h"
#include "Road.h"
void Pawn::Update()
{

}

void Pawn::Render(HDC _hdc)
{
}

void Pawn::Attack()
{
	for(Road* &range : attackRange)
	{
		Enemy* enemy = range->GetAssignedEnemy();
		if (enemy != nullptr) {
			enemy->ApplyDamage(stat.AttackDamage);
		}
	}
}

void Pawn::RangeCheck()
{
	vector<vector<Object*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	for (int i = 0; i < 4; i++) {
		Object* tile = map[(int)(m_tilePos.x + xAttackRange[i])][(int)(m_tilePos.y + yAttackRange[i])];
		Road* road = dynamic_cast<Road*>(tile);
		if (road) 
		{
			attackRange.push_back(road);
		}
	}
}
