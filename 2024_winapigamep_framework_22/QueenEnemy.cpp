#include "pch.h"
#include "QueenEnemy.h"
#include "ResourceManager.h"
#include "Health.h"
#include "SpriteRenderer.h"
#include "HealthBar.h"
#include "EnemyManager.h"

QueenEnemy::QueenEnemy()
{
	GetComponent<SpriteRenderer>()->SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"QueenEnemy", L"Texture\\EnemyQueen.bmp"));
	SetMoveCooltime(GET_SINGLE(EnemyManager)->GetEnemyMoveCool(UNIT_TYPE::QUEEN));
	SetCost(GET_SINGLE(EnemyManager)->GetEnemyCost(UNIT_TYPE::QUEEN));
	Health* health = GetComponent<Health>();
	health->SetMaxHealth(GET_SINGLE(EnemyManager)->GetEnemyHealth(UNIT_TYPE::QUEEN), true);
	GetHealthBar()->SetColor(BRUSH_TYPE::YELLOW);
}

QueenEnemy::~QueenEnemy()
{
}
