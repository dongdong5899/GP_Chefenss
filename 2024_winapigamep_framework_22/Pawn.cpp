#include "pch.h"
#include "Pawn.h"
#include "MapManager.h"
#include "Road.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Animator.h"
#include "InputManager.h"

Pawn::Pawn()
{
	m_uTexture = GET_SINGLE(ResourceManager)->TextureLoad(L"Pawn", L"Texture\\PlayerPawn.bmp");
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 20.f;
	m_vScale = size;
	cost = 5;
	stat.AttackDamage = 1.f;
	RangeCheck();
}
Pawn::~Pawn()
{
}
void Pawn::Update()
{
	Unit::Attack();
}

void Pawn::Render(HDC _hdc)
{
	Unit::Render(_hdc);
}


vector<Road*> Pawn::RangeCheck()
{
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	m_tilePos = GET_SINGLE(MapManager)->PosToMapPos(GET_SINGLE(InputManager)->GetMousePos());
	vector<Road*> vRange;
	for (int i = 0; i < 4; i++) {
		Tile* tile = map[(int)(m_tilePos.x + xAttackRange[i])][(int)(m_tilePos.y + yAttackRange[i])];
		Road* road = dynamic_cast<Road*>(tile);
		if (road) 
		{
			vRange.push_back(road);
		}
	}
	attackRange = vRange;
	return vRange;
}



