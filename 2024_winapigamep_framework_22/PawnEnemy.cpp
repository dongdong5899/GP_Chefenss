#include "pch.h"
#include "PawnEnemy.h"
#include "Texture.h"
#include "ResourceManager.h"

PawnEnemy::PawnEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"PawnEnemy", L"Texture\\EnemyPawn.bmp"));
	SetHP(5);
	SetMoveCooltime(70);
	SetCost(20);
}

PawnEnemy::~PawnEnemy()
{
}