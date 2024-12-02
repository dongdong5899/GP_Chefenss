#include "pch.h"
#include "Road.h"
#include "Enemy.h"
#include "GDISelector.h"
#include "ResourceManager.h"
#include "Texture.h"

Road::Road()
	: m_assignedEnemy()
	, m_assignedEnemyCount(0)
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

void Road::AddAssignedEnemy(Enemy* _enemy)
{
	m_assignedEnemy.push_back(_enemy);
	_enemy->SetOwner(this);
	_enemy->SetPos(GetPos());
	for (int i = 0; i < m_assignedEnemy.size(); ++i)
	{
		m_assignedEnemy[i]->SetHpIndex(i);
	}
}

void Road::RemoveAssignedEnemy(Enemy* _enemy)
{
	auto pos = std::find(m_assignedEnemy.begin(), m_assignedEnemy.end(), _enemy);
	if (pos != m_assignedEnemy.end())
	{
		m_assignedEnemy.erase(pos);
	}
	for (int i = 0; i < m_assignedEnemy.size(); ++i)
	{
		m_assignedEnemy[i]->SetHpIndex(i);
	}
}