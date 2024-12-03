#include "pch.h"
#include "Knight.h"
#include "MapManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "InputManager.h"
Knight::Knight()
{
	m_uTexture = GET_SINGLE(ResourceManager)->TextureLoad(L"Knight", L"Texture\\PlayerKnight.bmp");
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 20.f;
	m_vScale = size;
	cost = 7;
	stat.AttackDamage = 3.f;
	stat.AttackCooldown = 0.1f;
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


void Knight::Render(HDC _hdc)
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



vector<Road*> Knight::RangeCheck()
{
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	vector<Road*> vRange;
	m_tilePos = GET_SINGLE(MapManager)->PosToMapPos(GET_SINGLE(InputManager)->GetMousePos());
	for (int i = 0; i < 8; i++) {
		if (m_tilePos.x + xAttackRange[i] < 0 || m_tilePos.y < 0 
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
