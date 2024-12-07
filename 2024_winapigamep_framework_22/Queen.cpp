#include "pch.h"
#include "Queen.h"
#include "MapManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "InputManager.h"
#include "UnitManager.h"
#include "SpriteRenderer.h"
Queen::Queen()
{
	SpriteRenderer* renderer = GetComponent<SpriteRenderer>();
	renderer->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"Queen", L"Texture\\PlayerQueen.bmp"));
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 20.f;
	renderer->SetScale(size);
	SetAttackDamage(GET_SINGLE(UnitManager)->GetUnitAtkDamage(UNIT_TYPE::QUEEN));
	SetAttackCooldown(GET_SINGLE(UnitManager)->GetUnitAtkCool(UNIT_TYPE::QUEEN));
}

Queen::~Queen()
{
}

void Queen::Update()
{
	if (isDeployed) {
		Unit::Update();
	}
}

vector<Road*> Queen::RangeCheck()
{
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	vector<Road*> vRange;
	m_tilePos = GET_SINGLE(MapManager)->PosToMapPos(GET_SINGLE(InputManager)->GetMousePos());
	for (int i = 0; i < 8; i++) {
		Vec2 attackCheckPos = m_tilePos;
		while (true) {
			if (attackCheckPos.x + xAttackRange[i] < 0 || attackCheckPos.y + yAttackRange[i] < 0 || map[0].size() <= attackCheckPos.x + xAttackRange[i] || map.size() <= attackCheckPos.y + yAttackRange[i]) {
				break;
			}
			attackCheckPos.x += xAttackRange[i];
			attackCheckPos.y += yAttackRange[i];
			Tile* tile = map[(int)(attackCheckPos.y)][(int)(attackCheckPos.x)];
			Road* road = dynamic_cast<Road*>(tile);
			if (road)
			{
				vRange.push_back(road);
			}
		}
	}
	attackRange = vRange;
	return vRange;
}


