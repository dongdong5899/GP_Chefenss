#include "pch.h"
#include "QueenEnemy.h"
#include "ResourceManager.h"
#include "Health.h"
#include "SpriteRenderer.h"
#include "HealthBar.h"

QueenEnemy::QueenEnemy()
{
	GetComponent<SpriteRenderer>()->SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"QueenEnemy", L"Texture\\EnemyQueen.bmp"));
	SetMoveCooltime(70);
	SetCost(700);
	Health* health = GetComponent<Health>();
	health->SetMaxHealth(350, true);
	GetHealthBar()->SetColor(BRUSH_TYPE::YELLOW);
}

QueenEnemy::~QueenEnemy()
{
}
