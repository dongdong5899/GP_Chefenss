#include "pch.h"
#include "BishopEnemy.h"
#include "ResourceManager.h"
#include "Health.h"

BishopEnemy::BishopEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"BishopEnemy", L"Texture\\EnemyBishop.bmp"));
	SetHP(10);
	SetMoveCooltime(20);
	SetCost(100);
	GetComponent<Health>()->SetColor(BRUSH_TYPE::BLUE);
}

BishopEnemy::~BishopEnemy()
{
}