#include "pch.h"
#include "Queen.h"
#include "MapManager.h"
#include "ResourceManager.h"
#include "Texture.h"
Queen::Queen()
{
	m_uTexture = GET_SINGLE(ResourceManager)->TextureLoad(L"Queen", L"Texture\\PlayerQueen.bmp");
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 20.f;
	m_vScale = size;
	cost = 15;
}

Queen::~Queen()
{
}

void Queen::Update()
{
}

void Queen::Render(HDC _hdc)
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

vector<Road*> Queen::RangeCheck()
{
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	vector<Road*> vRange;
	for (int i = 0; i < 8; i++) {
		Vec2 attackCheckPos = m_tilePos;
		while (true) {
			if (attackCheckPos.x < 0 || attackCheckPos.y < 0 || map[0].size() < attackCheckPos.x || map.size() < attackCheckPos.y) {
				break;
			}
			attackCheckPos.x += xAttackRange[i];
			attackCheckPos.y += yAttackRange[i];
			Tile* tile = map[(int)(attackCheckPos.x)][(int)(attackCheckPos.y)];
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


