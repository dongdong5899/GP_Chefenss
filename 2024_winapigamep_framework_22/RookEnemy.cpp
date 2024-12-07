#include "pch.h"
#include "RookEnemy.h"
#include "ResourceManager.h"
#include "Health.h"
#include "SpriteRenderer.h"
#include "HealthBar.h"

RookEnemy::RookEnemy()
{
	GetComponent<SpriteRenderer>()->SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"RookEnemy", L"Texture\\EnemyRook.bmp"));
	SetMoveCooltime(100);
	SetCost(400);
	Health* health = GetComponent<Health>();
	health->SetMaxHealth(50, true);
	GetHealthBar()->SetColor(BRUSH_TYPE::WHITE);
}

RookEnemy::~RookEnemy()
{
}
