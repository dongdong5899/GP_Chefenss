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
	Unit::Render(_hdc);
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
