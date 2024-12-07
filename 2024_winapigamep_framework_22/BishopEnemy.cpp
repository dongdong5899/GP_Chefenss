#include "pch.h"
#include "BishopEnemy.h"
#include "ResourceManager.h"
#include "Health.h"
#include "SpriteRenderer.h"
#include "HealthBar.h"

BishopEnemy::BishopEnemy()
{
	GetComponent<SpriteRenderer>()->SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"BishopEnemy", L"Texture\\EnemyBishop.bmp"));
	SetMoveCooltime(20);
	SetCost(80);
	Health* health = GetComponent<Health>();
	health->SetMaxHealth(5, true);
	GetHealthBar()->SetColor(BRUSH_TYPE::BLUE);
}

BishopEnemy::~BishopEnemy()
{
}