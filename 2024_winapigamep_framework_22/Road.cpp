#include "pch.h"
#include "Road.h"
#include "Enemy.h"
#include "GDISelector.h"
#include "ResourceManager.h"
#include "Texture.h"

Road::Road()
	: m_assignedEnemy(nullptr)
{
	SetTexture(GET_SINGLE(ResourceManager)->
		TextureLoad(L"Road", L"Texture\\EnemyTile.bmp"));
}

Road::~Road()
{
}

void Road::Update()
{

}

void Road::AssignEnemy(Enemy* _enemy)
{
	SetAssignedEnemy(_enemy);
	_enemy->SetOwner(this);
	_enemy->SetPos(GetPos());
}
