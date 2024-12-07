#include "pch.h"
#include "Bishop.h"
#include "MapManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "InputManager.h"
#include "UnitManager.h"
#include "SpriteRenderer.h"

Bishop::Bishop()
{
	SpriteRenderer* renderer = GetComponent<SpriteRenderer>();
	renderer->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"Bishop", L"Texture\\PlayerBishop.bmp"));
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 20.f;
	renderer->SetScale(size);
	SetAttackDamage(GET_SINGLE(UnitManager)->GetUnitAtkDamage(UNIT_TYPE::BISHOP));
	SetAttackCooldown(GET_SINGLE(UnitManager)->GetUnitAtkCool(UNIT_TYPE::BISHOP));
}

Bishop::~Bishop()
{
}

void Bishop::Update()
{
	if (isDeployed) {
		Unit::Update();
	}
}

vector<Road*> Bishop::RangeCheck()
{
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	vector<Road*> vRange;
	m_tilePos = GET_SINGLE(MapManager)->PosToMapPos(GET_SINGLE(InputManager)->GetMousePos());
	for (int i = 0; i < 4; i++) {
		Vec2 attackCheckPos = m_tilePos;
		while (true) {
			if (attackCheckPos.x + xAttackRange[i] < 0 || attackCheckPos.y + yAttackRange[i] < 0 || map[0].size() <= attackCheckPos.x + xAttackRange[i] || map.size() <= attackCheckPos.y+ yAttackRange[i]) {
				break;
			}
			attackCheckPos.x += xAttackRange[i];
			attackCheckPos.y += yAttackRange[i];
			Object* tile = map[(int)(attackCheckPos.y)][(int)(attackCheckPos.x)];
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



