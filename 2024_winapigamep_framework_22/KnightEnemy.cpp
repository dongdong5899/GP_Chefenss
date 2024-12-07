#include "pch.h"
#include "KnightEnemy.h"
#include "ResourceManager.h"
#include "Health.h"
#include "SpriteRenderer.h"
#include "HealthBar.h"

KnightEnemy::KnightEnemy()
{
	GetComponent<SpriteRenderer>()->SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"KnightEnemy", L"Texture\\EnemyKnight.bmp"));
	SetMoveCooltime(10);
	SetCost(60);
	Health* health = GetComponent<Health>();
	health->SetMaxHealth(5, true);
	GetHealthBar()->SetColor(BRUSH_TYPE::GREEN);
}

KnightEnemy::~KnightEnemy()
{
}
