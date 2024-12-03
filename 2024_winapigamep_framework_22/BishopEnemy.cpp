#include "pch.h"
#include "BishopEnemy.h"
#include "ResourceManager.h"
#include "Health.h"

BishopEnemy::BishopEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"BishopEnemy", L"Texture\\EnemyBishop.bmp"));
	SetHP(5);
	SetMoveDuration(2);
	SetCost(100);
	GetComponent<Health>()->SetColor(BRUSH_TYPE::BLUE);
}

BishopEnemy::~BishopEnemy()
{
}