#include "pch.h"
#include "PawnEnemy.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Health.h"
#include "SpriteRenderer.h"
#include "HealthBar.h"

PawnEnemy::PawnEnemy()
{
	GetComponent<SpriteRenderer>()->SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"PawnEnemy", L"Texture\\EnemyPawn.bmp"));
	SetMoveCooltime(50);
	SetCost(20);
	Health* health = GetComponent<Health>();
	health->SetMaxHealth(3, true);
	GetHealthBar()->SetColor(BRUSH_TYPE::RED);
}

PawnEnemy::~PawnEnemy()
{
}