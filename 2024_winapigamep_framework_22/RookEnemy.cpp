#include "pch.h"
#include "RookEnemy.h"
#include "ResourceManager.h"
#include "Health.h"

RookEnemy::RookEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"RookEnemy", L"Texture\\EnemyRook.bmp"));
	SetMoveCooltime(100);
	SetCost(400);
	Health* health = GetComponent<Health>();
	health->SetColor(BRUSH_TYPE::RED);
	health->SetMaxHealth(50, true);
}

RookEnemy::~RookEnemy()
{
}
