#include "pch.h"
#include "Pawn.h"
//#include "Mapmanager"

void Pawn::Attack()
{
	
}

void Pawn::RangeCheck()
{
	wstring map[10][10]; //= GET_SINGLE(MapManager);
	for (int i = 0; i < 4; i++) {
		if (map[(int)(m_pos.x + xAttackRange[i])] [(int)(m_pos.y + yAttackRange[i])] == L"¤±") {
			//Vec2 vec = { (int)(m_pos.x + xAttackRange[i])][(int)(m_pos.y + yAttackRange[i]) }
			attackRange.push_back();
		}
	}
}
