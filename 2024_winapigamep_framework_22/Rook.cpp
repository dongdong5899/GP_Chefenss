#include "pch.h"
#include "Rook.h"
#include "MapManager.h"
#include "Texture.h"
#include "ResourceManager.h"
Rook::Rook()
{
	m_uTexture = GET_SINGLE(ResourceManager)->TextureLoad(L"Rook", L"Texture\\PlayerRook.bmp");
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 20.f;
	m_vScale = size;
	cost = 10;
}

Rook::~Rook()
{
}

void Rook::Update()
{
}

vector<Road*> Rook::RangeCheck()
{
	vector<vector<Tile*>> map = GET_SINGLE(MapManager)->GetMapTileData();
	vector<Road*> vRange;
	for (int i = 0; i < 4; i++) {
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

void Rook::Render(HDC _hdc)
{
	Unit::Render(_hdc);
}

