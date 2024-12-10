#include "pch.h"
#include "Pawn.h"
#include "MapManager.h"
#include "Road.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Animator.h"
#include "InputManager.h"
#include "UnitManager.h"
#include "SpriteRenderer.h"

Pawn::Pawn()
{
	SpriteRenderer* renderer = GetComponent<SpriteRenderer>();
	renderer->SetTexture(GET_SINGLE(ResourceManager)->TextureLoad(L"Pawn", L"Texture\\PlayerPawn.bmp"));
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 20.f;
	renderer->SetScale(size);
	SetAttackDamage(GET_SINGLE(UnitManager)->GetUnitAtkDamage(UNIT_TYPE::PAWN));
	SetAttackCooldown(GET_SINGLE(UnitManager)->GetUnitAtkCool(UNIT_TYPE::PAWN));
}

Pawn::~Pawn()
{
}

void Pawn::Update()
{
	if(m_isDeployed)
		Unit::Update();
}

vector<Road*> Pawn::RangeCheck()
{
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	m_tilePos = GET_SINGLE(MapManager)->PosToMapPos(GET_SINGLE(InputManager)->GetMousePos());
	vector<Road*> vRange;
	for (int i = 0; i < 4; i++) {
		if (m_tilePos.x + xAttackRange[i] < 0 || m_tilePos.y+yAttackRange[i] < 0
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



