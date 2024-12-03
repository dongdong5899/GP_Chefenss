#include "pch.h"
#include "RookEnemy.h"
#include "ResourceManager.h"
#include "Health.h"

RookEnemy::RookEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"RookEnemy", L"Texture\\EnemyRook.bmp"));
	SetHP(30);
	SetMoveDuration(4);
	SetCost(400);
	GetComponent<Health>()->SetColor(BRUSH_TYPE::RED);
}

RookEnemy::~RookEnemy()
{
}
