#include "pch.h"
#include "Pawn.h"
#include "MapManager.h"`

void Pawn::Update()
{
}

void Pawn::Render(HDC _hdc)
{
}

void Pawn::Attack()
{
	for(Vec2 &attack : attackRange)
	{
		/*if (GET_SINGLE(MapManager)->GetMap()[attack.x][attack.y] == ) {
			
		}*/
	}
}

void Pawn::RangeCheck()
{
	vector<wstring> map = GET_SINGLE(MapManager)->GetMap();
	for (int i = 0; i < 4; i++) {
		if (map[(int)(m_pos.x + xAttackRange[i])] [(int)(m_pos.y + yAttackRange[i])] == L'¤±') {
			Vec2 vec = { (int)(m_pos.x + xAttackRange[i]),(int)(m_pos.y + yAttackRange[i]) };
			attackRange.push_back(vec);
		}
	}
}
