#include "pch.h"
#include "PawnEnemy.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Health.h"
#include "SpriteRenderer.h"
#include "HealthBar.h"
#include "EnemyManager.h"

PawnEnemy::PawnEnemy()
{
	GetComponent<SpriteRenderer>()->SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"PawnEnemy", L"Texture\\EnemyPawn.bmp"));
	SetMoveCooltime(GET_SINGLE(EnemyManager)->GetEnemyMoveCool(UNIT_TYPE::PAWN));
	SetCost(GET_SINGLE(EnemyManager)->GetEnemyCost(UNIT_TYPE::PAWN));
	Health* health = GetComponent<Health>();
	health->SetMaxHealth(GET_SINGLE(EnemyManager)->GetEnemyHealth(UNIT_TYPE::PAWN), true);
	GetHealthBar()->SetColor(BRUSH_TYPE::RED);
}

PawnEnemy::~PawnEnemy()
{
}