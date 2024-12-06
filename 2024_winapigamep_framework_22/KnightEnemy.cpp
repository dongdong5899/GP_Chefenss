#include "pch.h"
#include "KnightEnemy.h"
#include "ResourceManager.h"
#include "Health.h"

KnightEnemy::KnightEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"KnightEnemy", L"Texture\\EnemyKnight.bmp"));
	SetMoveCooltime(10);
	SetCost(60);
	Health* health = GetComponent<Health>();
	health->SetColor(BRUSH_TYPE::GREEN);
	health->SetMaxHealth(5, true);
}

KnightEnemy::~KnightEnemy()
{
}
