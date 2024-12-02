#include "pch.h"
#include "RookEnemy.h"
#include "ResourceManager.h"

RookEnemy::RookEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"RookEnemy", L"Texture\\EnemyRook.bmp"));
	SetHP(30);
	SetMoveDuration(4);
}

RookEnemy::~RookEnemy()
{
}
