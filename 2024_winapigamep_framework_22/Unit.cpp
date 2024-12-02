#include "pch.h"
#include "Unit.h"
#include "GDISelector.h"
#include "TimeManager.h"


Unit::Unit():m_uTexture(nullptr)
{
	
}

Unit::~Unit()
{
}

void Unit::Update()
{
	/*if (AttackCoolTimeCheck(GET_SINGLE(TimeManager)->GetDT())) {*/
		Attack();
	/*}*/
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
			cout << "hit";
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


