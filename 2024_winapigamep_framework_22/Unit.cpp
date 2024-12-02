#include "pch.h"
#include "Unit.h"
#include "GDISelector.h"
#include "TimeManager.h"
#include "Texture.h"


Unit::Unit():m_uTexture(nullptr)
{
	
}

Unit::~Unit()
{
}

void Unit::Update()
{
}

void Unit::Render(HDC _hdc)
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

void Unit::Attack()
{
	for (Road*& range : attackRange)
	{
		Enemy* enemy = range->GetAssignedEnemy();
		if(enemy==nullptr)
			return;
		
		cout << enemy->GetMoveSpeed();
		cout << "Attack";
		enemy->ApplyDamage(stat.AttackDamage);
	}
}

bool Unit::AttackCoolTimeCheck(float fdt)
{
	if (attackCooldown > stat.AttackCooldown) {
		return true;
	}
	else {
		attackCooldown += fdt;
		return false;
	}
}


