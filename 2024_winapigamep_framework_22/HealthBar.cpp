#include "pch.h"
#include "HealthBar.h"
#include "Enemy.h"
#include "MapManager.h"
#include "GDISelector.h"
#include "Health.h"

HealthBar::HealthBar()
	: m_owner(nullptr)
	, m_color(BRUSH_TYPE::WHITE)
	, m_amount(1)
	, m_tileSize(0)
{
	m_tileSize = GET_SINGLE(MapManager)->GetTileSize();
	SetSize({ m_tileSize * 0.7f, m_tileSize * 0.1f });
}

HealthBar::~HealthBar()
{
}

void HealthBar::Update()
{
}

void HealthBar::LateUpdate()
{
	Enemy* enemy = GetOwner();
	Vec2 pos = enemy->GetPos();
	pos.y -= m_tileSize / 2 + enemy->GetHpIndex() * m_tileSize * 0.14f;
	SetPos(pos);

	float amount = enemy->GetComponent<Health>()->GetHealthAmount();
	SetAmount(amount);
}

void HealthBar::Render(HDC _hdc)
{
	Vec2 size = GetSize();
	Vec2 pos = GetPos();

	{
		GDISelector brush1(_hdc, BRUSH_TYPE::GRAY);
		RECT_RENDER(_hdc, pos.x, pos.y, size.x, size.y);
	}

	{
		GDISelector pen1(_hdc, PEN_TYPE::HOLLOW);
		if ((int)m_color == -1) m_color = BRUSH_TYPE::RED;
		GDISelector brush2(_hdc, m_color);
		Rectangle(_hdc, pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x * (GetAmount() - 0.5f), pos.y + size.y / 2);
	}

	{
		GDISelector brush3(_hdc, BRUSH_TYPE::HOLLOW);
		RECT_RENDER(_hdc, pos.x, pos.y, size.x, size.y);
	}
}