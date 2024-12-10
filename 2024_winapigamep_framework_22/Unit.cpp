#include "pch.h"
#include "Unit.h"
#include "GDISelector.h"
#include "TimeManager.h"
#include "MapManager.h"
#include "Health.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "Texture.h"
#include "SpriteRenderer.h"


Unit::Unit()
	: m_attackCooldown(0)
	, m_rangeCheck(false)
	, m_isDeployed(false)
{
	GET_SINGLE(ResourceManager)->LoadSound(L"PawnAttack", L"Sound\\PawnAttack.wav",false);
	GET_SINGLE(ResourceManager)->LoadSound(L"KnightAttack", L"Sound\\KnightAttack.wav",false);
	GET_SINGLE(ResourceManager)->LoadSound(L"BishopAttack", L"Sound\\BishopAttack.wav",false);
	GET_SINGLE(ResourceManager)->LoadSound(L"RookAttack", L"Sound\\RookAttack.wav",false);
	GET_SINGLE(ResourceManager)->LoadSound(L"QueenAttack", L"Sound\\QueenAttack.wav", false);

	AddComponent<SpriteRenderer>();
	GetComponent<SpriteRenderer>()->OnTransparent();
	GetComponent<SpriteRenderer>()->SetAlpha(128);
}

Unit::~Unit()
{
}

void Unit::Update()
{
	if (m_isDeployed == false) return;

	m_attackCooldown++;
	SetAttackRoadColor(BRUSH_TYPE::RED, (BYTE)round(((float)m_attackCooldown / stat.AttackCooldown) * 255));
	if (m_attackCooldown > stat.AttackCooldown) {
		SetAttackRoadColor(BRUSH_TYPE::WHITE, 255);
		m_attackCooldown = 0;
		Attack();
	}
}

void Unit::Render(HDC _hdc)
{
	ComponentRender(_hdc);
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
		if (enemies.size()>0) {

			switch (m_unitType)
			{
			case UNIT_TYPE::PAWN:
				GET_SINGLE(ResourceManager)->Play(L"PawnAttack");
				break;
			case UNIT_TYPE::KNIGHT:
				GET_SINGLE(ResourceManager)->Play(L"PawnAttack");
				break;
			case UNIT_TYPE::BISHOP:
				GET_SINGLE(ResourceManager)->Play(L"BishopAttack");
				break;
			case UNIT_TYPE::ROOK:
				GET_SINGLE(ResourceManager)->Play(L"QueenAttack");
				break;
			case UNIT_TYPE::QUEEN:
				GET_SINGLE(ResourceManager)->Play(L"QueenAttack");
				break;
			}
		}
	}
}

bool Unit::AttackCoolTimeCheck(float fdt)
{
	if (m_attackCooldown > stat.AttackCooldown) {
		return true;
	}
	else {
		m_attackCooldown += fdt;
		return false;
	}
}

void Unit::SetDeploy(bool deploy)
{
	GetComponent<SpriteRenderer>()->SetAlpha(255);
	m_isDeployed = deploy;
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

void Unit::Die()
{
	SetAttackRoadColor(BRUSH_TYPE::WHITE, 0, true);
	GET_SINGLE(EventManager)->DeleteObject(this);
}


