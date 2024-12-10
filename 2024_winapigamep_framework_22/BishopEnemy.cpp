#include "pch.h"
#include "BishopEnemy.h"
#include "ResourceManager.h"
#include "Health.h"
#include "SpriteRenderer.h"
#include "HealthBar.h"
#include "EnemyManager.h"

BishopEnemy::BishopEnemy()
{
	GetComponent<SpriteRenderer>()->SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"BishopEnemy", L"Texture\\EnemyBishop.bmp"));
	SetMoveCooltime(GET_SINGLE(EnemyManager)->GetEnemyMoveCool(UNIT_TYPE::BISHOP));
	SetCost(GET_SINGLE(EnemyManager)->GetEnemyCost(UNIT_TYPE::BISHOP));
	Health* health = GetComponent<Health>();
	health->SetMaxHealth(GET_SINGLE(EnemyManager)->GetEnemyHealth(UNIT_TYPE::BISHOP), true);
	GetHealthBar()->SetColor(BRUSH_TYPE::BLUE);
}

BishopEnemy::~BishopEnemy()
{
}