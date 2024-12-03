#include "pch.h"
#include "KnightEnemy.h"
#include "ResourceManager.h"
#include "Health.h"

KnightEnemy::KnightEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"KnightEnemy", L"Texture\\EnemyKnight.bmp"));
	SetHP(5);
	SetMoveDuration(1);
	SetCost(60);
	GetComponent<Health>()->SetColor(BRUSH_TYPE::GREEN);
}

KnightEnemy::~KnightEnemy()
{
}
