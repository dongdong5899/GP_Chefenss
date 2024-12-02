#include "pch.h"
#include "QueenEnemy.h"
#include "ResourceManager.h"

QueenEnemy::QueenEnemy()
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"QueenEnemy", L"Texture\\EnemyQueen.bmp"));
	SetHP(100);
	SetMoveDuration(7);
}

QueenEnemy::~QueenEnemy()
{
}
