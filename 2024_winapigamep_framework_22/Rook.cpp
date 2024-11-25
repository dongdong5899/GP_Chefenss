#include "pch.h"
#include "Rook.h"
#include "MapManager.h"

Rook::Rook()
{
}

Rook::~Rook()
{
}

void Rook::Update()
{
}

void Rook::Render(HDC _hdc)
{
}

void Rook::Attack()
{
}

void Rook::RangeCheck()
{
	vector<vector<Object*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	for (int i = 0; i < 4; i++) {
		while (true) {
			if (m_currentPos.x < 0 || m_currentPos.y < 0 || map[0].size() < m_currentPos.x || map.size() < m_currentPos.y) {
				m_currentPos = m_pos;
				break;
			}
			m_currentPos.x += xAttackRange[i];
			m_currentPos.y += yAttackRange[i];
			Object* tile = map[(int)(m_currentPos.x)][(int)(m_currentPos.y)];
			Road* road = dynamic_cast<Road*>(tile);
			if (road)
			{
				attackRange.push_back(road);
			}
		}
	}
}
