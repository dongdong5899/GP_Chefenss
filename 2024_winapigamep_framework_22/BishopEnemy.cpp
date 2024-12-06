#include "pch.h"
#include "BishopEnemy.h"
#include "ResourceManager.h"
#include "Health.h"

BishopEnemy::BishopEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"BishopEnemy", L"Texture\\EnemyBishop.bmp"));
	SetMoveCooltime(20);
	SetCost(100);
	Health* health = GetComponent<Health>();
	health->SetColor(BRUSH_TYPE::BLUE);
	health->SetMaxHealth(10, true);
}

BishopEnemy::~BishopEnemy()
{
}