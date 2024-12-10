#include "pch.h"
#include "PlayerHealthUI.h"
#include "GDISelector.h"
#include "GameManager.h"

PlayerHealthUI::PlayerHealthUI()
	: m_maxHealth(10)
	, m_currentHealth(10)
	, m_visualHealth(10)
	, m_interval(10)
{
	SetMaxHealth(GET_SINGLE(GameManager)->GetMaxHealth());
	m_currentHealth = (GetMaxHealth());
	SetVisualHealth(GetMaxHealth());
	GET_SINGLE(GameManager)->onHit += [this]() { this->HealthDown(); };
}

PlayerHealthUI::~PlayerHealthUI()
{
}

void PlayerHealthUI::Update()
{
}


void PlayerHealthUI::Render(HDC _hdc)
{
	Vec2 pos = GetPos();
	Vec2 size = GetSize();
	int interval = GetInterval();
	int maxHealth = GetMaxHealth();
	int HealthSize = (size.x - interval * (maxHealth - 1)) / maxHealth;
	int startXPos = pos.x - size.x / 2 + HealthSize / 2;
	int count = GetVisualHealth();
	for (size_t i = 0; i < count; i++)
	{
		if (i < GetHealth())
		{
			GDISelector brush(_hdc, BRUSH_TYPE::RED);
			RECT_RENDER(_hdc, startXPos + i * (HealthSize + interval), pos.y, HealthSize, size.y);
		}
		else
		{
			SetVisualHealth(GetVisualHealth() - 1);
			GDISelector pen(_hdc, PEN_TYPE::HOLLOW);
			GDISelector brush(_hdc, BRUSH_TYPE::WHITE);
			RECT_RENDER(_hdc, startXPos + i * (HealthSize + interval), pos.y, HealthSize, size.y);
		}
	}
}