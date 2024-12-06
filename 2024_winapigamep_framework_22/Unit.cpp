#include "pch.h"
#include "Unit.h"
#include "GDISelector.h"
#include "TimeManager.h"
#include "MapManager.h"
#include "Health.h"


Unit::Unit()
	: m_uTexture(nullptr)
	, attackCooldown(0)
	, rangeCheck(false)
{
	
}

Unit::~Unit()
{
}

void Unit::Update()
{
	attackCooldown++;
	cout << attackCooldown << endl;
	SetAttackRoadColor(BRUSH_TYPE::RED, (BYTE)round(((float)attackCooldown / stat.AttackCooldown) * 255));
	if (attackCooldown > stat.AttackCooldown) {
		SetAttackRoadColor(BRUSH_TYPE::WHITE, 255);
		attackCooldown = 0;
		Attack();
	}
}

void Unit::Render(HDC _hdc)
{
	
}

void Unit::Attack()
{
	for (Road*& range : attackRange)
	{
		vector<Enemy*> enemies = range->GetAssignedEnemy();
		for (Enemy* enemy : enemies)
		{
			enemy->GetComponent<Health>()->ApplyDamage(stat.AttackDamage);
		}
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

void Unit::SetAttackRoadColor(BRUSH_TYPE _color, BYTE _alpha, bool _isUnconditional)
{
	for (Road*& range : attackRange)
	{
		range->SetColor(_color);
		BYTE alpha = range->GetAlpha();
		if (!_isUnconditional && alpha > _alpha && alpha != 255) continue;
		range->SetAlpha(_alpha);
	}
}


