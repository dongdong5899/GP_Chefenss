#include "pch.h"
#include "EnemySpawner.h"
#include "EnemyManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Enemy.h"

EnemySpawner::EnemySpawner()
	: m_enemySpawnVec()
	, m_enemySpawnIndex(0)
	, m_enemySpawnDelay(0)
	, m_currentSpawnDelay(0)
	, m_isEnd(false)
{
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::Update()
{
	if (m_isEnd) return;

	if (m_enemySpawnDelay <= m_currentSpawnDelay)
	{
		m_currentSpawnDelay = 0;
		SpawnEnemy();
	}
	m_currentSpawnDelay++;
}

void EnemySpawner::SpawnEnemy()
{
	UNIT_TYPE enemyType = GetUnitType(m_enemySpawnVec[m_enemySpawnIndex++]);

	if (m_enemySpawnIndex == m_enemySpawnVec.size())
	{
		m_isEnd = true;
	}

	if (enemyType == UNIT_TYPE::END) return;
	Enemy* pEnemy = GET_SINGLE(EnemyManager)->CreateEnemy(enemyType);
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pEnemy, LAYER::ENEMY);
}
