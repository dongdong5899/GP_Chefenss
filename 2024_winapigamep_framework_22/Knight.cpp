#include "pch.h"
#include "Knight.h"
#include "MapManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "InputManager.h"
#include "UnitManager.h"
#include "SpriteRenderer.h"
Knight::Knight()
{
	SpriteRenderer* renderer = GetComponent<SpriteRenderer>();
	renderer->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"Knight", L"Texture\\PlayerKnight.bmp"));
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 20.f;
	renderer->SetScale(size);
	SetAttackDamage(GET_SINGLE(UnitManager)->GetUnitAtkDamage(UNIT_TYPE::KNIGHT));
	SetAttackCooldown(GET_SINGLE(UnitManager)->GetUnitAtkCool(UNIT_TYPE::KNIGHT));
}

Knight::~Knight()
{
}

void Knight::Update()
{
	if (isDeployed) {
		Unit::Update();
	}
}



vector<Road*> Knight::RangeCheck()
{
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	vector<Road*> vRange;
	m_tilePos = GET_SINGLE(MapManager)->PosToMapPos(GET_SINGLE(InputManager)->GetMousePos());
	for (int i = 0; i < 8; i++) {
		if (m_tilePos.x + xAttackRange[i] < 0 || m_tilePos.y  + yAttackRange[i]< 0 
			|| map[0].size() <= m_tilePos.x + xAttackRange[i] || map.size() <= m_tilePos.y + yAttackRange[i])
			continue;
		Tile* tile = map[(int)(m_tilePos.y + yAttackRange[i])][(int)(m_tilePos.x + xAttackRange[i])];
		Road* road = dynamic_cast<Road*>(tile);
		if (road)
		{
			vRange.push_back(road);
		}
	}
	attackRange = vRange;
	return vRange;
}
