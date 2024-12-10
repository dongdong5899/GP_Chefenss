#include "pch.h"
#include "RookEnemy.h"
#include "ResourceManager.h"
#include "Health.h"
#include "SpriteRenderer.h"
#include "HealthBar.h"
#include "EnemyManager.h"

RookEnemy::RookEnemy()
{
	GetComponent<SpriteRenderer>()->SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"RookEnemy", L"Texture\\EnemyRook.bmp"));
	SetMoveCooltime(GET_SINGLE(EnemyManager)->GetEnemyMoveCool(UNIT_TYPE::ROOK));
	SetCost(GET_SINGLE(EnemyManager)->GetEnemyCost(UNIT_TYPE::ROOK));
	Health* health = GetComponent<Health>();
	health->SetMaxHealth(GET_SINGLE(EnemyManager)->GetEnemyHealth(UNIT_TYPE::ROOK), true);
	GetHealthBar()->SetColor(BRUSH_TYPE::WHITE);
}

RookEnemy::~RookEnemy()
{
}
