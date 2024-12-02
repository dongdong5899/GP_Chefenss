#include "pch.h"
#include "Health.h"
#include "Object.h"
#include "MapManager.h"
#include "GDISelector.h"
#include "Enemy.h"

Health::Health()
	: m_maxHealth(10)
	, m_currnetHealth(10)
	, m_color()
{
}

Health::~Health()
{
}

void Health::LateUpdate()
{
}

void Health::Render(HDC _hdc)
{
	{
		GDISelector brush(_hdc, m_color);
		Enemy* enemy = dynamic_cast<Enemy*>(GetOwner());
		Vec2 pos = enemy->GetPos();
		int tileSize = GET_SINGLE(MapManager)->GetTileSize();
		pos.y -= tileSize / 2 + enemy->GetHpIndex() * tileSize * 0.14f;
		Vec2 size = { tileSize * 0.7f, tileSize * 0.1f };
		RECT_RENDER(_hdc, pos.x, pos.y, size.x, size.y);
	}
}
