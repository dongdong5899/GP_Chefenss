#include "pch.h"
#include "KnightEnemy.h"
#include "ResourceManager.h"
#include "Health.h"
#include "SpriteRenderer.h"
#include "HealthBar.h"
#include "EnemyManager.h"

KnightEnemy::KnightEnemy()
{
	GetComponent<SpriteRenderer>()->SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"KnightEnemy", L"Texture\\EnemyKnight.bmp"));
	SetMoveCooltime(GET_SINGLE(EnemyManager)->GetEnemyMoveCool(UNIT_TYPE::KNIGHT));
	SetCost(GET_SINGLE(EnemyManager)->GetEnemyCost(UNIT_TYPE::KNIGHT));
	Health* health = GetComponent<Health>();
	health->SetMaxHealth(GET_SINGLE(EnemyManager)->GetEnemyHealth(UNIT_TYPE::KNIGHT), true);
	GetHealthBar()->SetColor(BRUSH_TYPE::GREEN);
}

KnightEnemy::~KnightEnemy()
{
}
