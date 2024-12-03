#include "pch.h"
#include "Unit.h"
#include "GDISelector.h"
#include "TimeManager.h"
#include "MapManager.h"


Unit::Unit():m_uTexture(nullptr), attackCooldown(0)
{
	
}

Unit::~Unit()
{
}

void Unit::Update()
{
	if (!rangeCheck) {
		rangeCheck = true;
		RangeCheck();
	}
	else {
		attackCooldown+=GET_SINGLE(TimeManager)->GetDT();
		if (attackCooldown > stat.AttackCooldown) {
			attackCooldown = 0;
			Attack();
		}
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
			enemy->ApplyDamage(stat.AttackDamage);
			cout << enemy->GetHP()<<endl;
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


