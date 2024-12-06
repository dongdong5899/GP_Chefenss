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
	, m_isDead(false)
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
		Enemy* enemy = dynamic_cast<Enemy*>(GetOwner());
		Vec2 pos = enemy->GetPos();
		int tileSize = GET_SINGLE(MapManager)->GetTileSize();
		pos.y -= tileSize / 2 + enemy->GetHpIndex() * tileSize * 0.14f;
		Vec2 size = { tileSize * 0.7f, tileSize * 0.1f };


		GDISelector brush1(_hdc, BRUSH_TYPE::GRAY);
		RECT_RENDER(_hdc, pos.x, pos.y, size.x, size.y);

		GDISelector pen1(_hdc, PEN_TYPE::HOLLOW);
		GDISelector brush2(_hdc, m_color);
		Rectangle(_hdc, pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x * (GetHealthAmount() - 0.5f), pos.y + size.y / 2);

		GDISelector pen2(_hdc, PEN_TYPE::BLACK);
		GDISelector brush3(_hdc, BRUSH_TYPE::HOLLOW);
		RECT_RENDER(_hdc, pos.x, pos.y, size.x, size.y);
	}
}
