#include "pch.h"
#include "PawnEnemy.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Health.h"

PawnEnemy::PawnEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"PawnEnemy", L"Texture\\EnemyPawn.bmp"));
	SetMoveCooltime(50);
	SetCost(20);
	Health* health = GetComponent<Health>();
	health->SetColor(BRUSH_TYPE::RED);
	health->SetMaxHealth(2, true);
}

PawnEnemy::~PawnEnemy()
{
}