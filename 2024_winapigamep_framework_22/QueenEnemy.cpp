#include "pch.h"
#include "QueenEnemy.h"
#include "ResourceManager.h"
#include "Health.h"

QueenEnemy::QueenEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"QueenEnemy", L"Texture\\EnemyQueen.bmp"));
	SetHP(100);
	SetMoveDuration(7);
	GetComponent<Health>()->SetColor(BRUSH_TYPE::YELLOW);
}

QueenEnemy::~QueenEnemy()
{
}
