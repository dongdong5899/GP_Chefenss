#include "pch.h"
#include "Rook.h"
#include "MapManager.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "UnitManager.h"
#include "SpriteRenderer.h"
Rook::Rook()
{
	SpriteRenderer* renderer = GetComponent<SpriteRenderer>();
	renderer->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"Rook", L"Texture\\PlayerRook.bmp"));
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 20.f;
	renderer->SetScale(size);
	SetAttackDamage(GET_SINGLE(UnitManager)->GetUnitAtkDamage(UNIT_TYPE::ROOK));
	SetAttackCooldown(GET_SINGLE(UnitManager)->GetUnitAtkCool(UNIT_TYPE::ROOK));
}

Rook::~Rook()
{
}

void Rook::Update()
{
	if (m_isDeployed) {
		Unit::Update();
	}
}

vector<Road*> Rook::RangeCheck()
{
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	vector<Road*> vRange;
	m_tilePos = GET_SINGLE(MapManager)->PosToMapPos(GET_SINGLE(InputManager)->GetMousePos());
	for (int i = 0; i < 4; i++) {
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
