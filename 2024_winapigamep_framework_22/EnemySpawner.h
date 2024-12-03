#pragma once
class EnemySpawner
{
public:
	EnemySpawner();
	~EnemySpawner();
public:
	void Update();
	void SetEnemySpawnDelay(int _count) { m_enemySpawnDelay = _count; }
	void SetEnemySpawnVec(vector<UNIT_TYPE> _enemySpawnVec)
		{ m_enemySpawnVec = _enemySpawnVec; }
	bool IsEnd() { return m_isEnd; }
private:
	void SpawnEnemy();
private:
	vector<UNIT_TYPE> m_enemySpawnVec;
	bool m_isEnd;
	int m_enemySpawnIndex;
	int m_enemySpawnDelay;
	int m_currentSpawnDelay;
};

