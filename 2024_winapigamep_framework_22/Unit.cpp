#include "pch.h"
#include "Unit.h"
#include "GDISelector.h"
#include "TimeManager.h"

void Unit::Update()
{
	if (AttackCoolTimeCheck(GET_SINGLE(TimeManager)->GetDT())) {
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
		Enemy* enemy = range->GetAssignedEnemy();
		if (enemy != nullptr) {
			enemy->ApplyDamage(stat.AttackDamage);
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
