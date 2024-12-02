#include "pch.h"
#include "Bishop.h"
#include "MapManager.h"
#include "ResourceManager.h"
#include "Texture.h"

Bishop::Bishop()
{
	m_uTexture = GET_SINGLE(ResourceManager)->TextureLoad(L"Bishop", L"Texture\\PlayerBishop.bmp");
	int tileSize = GET_SINGLE(MapManager)->GetTileSize();
	float size = (float)tileSize / 20.f;
	m_vScale = size;
	cost = 7;
}

Bishop::~Bishop()
{
}

void Bishop::Update()
{
}

void Bishop::Render(HDC _hdc)
{
	Unit::Render(_hdc);
}

vector<Road*> Bishop::RangeCheck()
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
			Object* tile = map[(int)(attackCheckPos.x)][(int)(attackCheckPos.y)];
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



