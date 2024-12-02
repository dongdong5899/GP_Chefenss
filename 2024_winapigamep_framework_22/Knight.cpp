#include "pch.h"
#include "Knight.h"
#include "MapManager.h"
#include "ResourceManager.h"
#include "Texture.h"
Knight::Knight()
{
	m_uTexture = GET_SINGLE(ResourceManager)->TextureLoad(L"Knight", L"Texture\\PlayerKnight.bmp");
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 20.f;
	m_vScale = size;
	cost = 7;
}

Knight::~Knight()
{
}

void Knight::Update()
{
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
	for (int i = 0; i < 8; i++) {
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
