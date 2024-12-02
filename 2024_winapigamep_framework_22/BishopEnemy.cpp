#include "pch.h"
#include "BishopEnemy.h"
#include "ResourceManager.h"

BishopEnemy::BishopEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"BishopEnemy", L"Texture\\EnemyBishop.bmp"));
	SetHP(5);
	SetMoveDuration(2);
}

BishopEnemy::~BishopEnemy()
{
}