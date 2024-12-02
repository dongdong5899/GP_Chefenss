#include "pch.h"
#include "KnightEnemy.h"
#include "ResourceManager.h"

KnightEnemy::KnightEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"KnightEnemy", L"Texture\\EnemyKnight.bmp"));
	SetHP(5);
	SetMoveDuration(1);
}

KnightEnemy::~KnightEnemy()
{
}
