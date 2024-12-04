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
	SetAttackDamage(5.f);
	SetAttackCooldown(0.5f);
}

Pawn::~Pawn()
{
}

void Pawn::Update()
{
	if(isDeployed)
		Unit::Update();
}

void Pawn::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	int width = m_uTexture->GetWidth();
	int height = m_uTexture->GetHeight();
	::TransparentBlt(_hdc
		, (int)(vPos.x - width * m_vScale / 2)
		, (int)(vPos.y - height * m_vScale / 2)
		, width * m_vScale, height * m_vScale,
		m_uTexture->GetTexDC()
		, 0, 0, width, height, RGB(255, 0, 255));
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



