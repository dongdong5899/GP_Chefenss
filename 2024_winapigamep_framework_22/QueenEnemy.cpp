#include "pch.h"
#include "QueenEnemy.h"
#include "ResourceManager.h"
#include "Health.h"
#include "SpriteRenderer.h"

QueenEnemy::QueenEnemy()
{
	GetComponent<SpriteRenderer>()->SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"QueenEnemy", L"Texture\\EnemyQueen.bmp"));
	SetMoveCooltime(70);
	SetCost(1000);
	Health* health = GetComponent<Health>();
	health->SetColor(BRUSH_TYPE::YELLOW);
	health->SetMaxHealth(200, true);
}

QueenEnemy::~QueenEnemy()
{
}
