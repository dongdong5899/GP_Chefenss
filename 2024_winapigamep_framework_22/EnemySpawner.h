#pragma once
class EnemySpawner
{
public:
	EnemySpawner();
	~EnemySpawner();
public:
	void Update();
	void SetEnemySpawnDelay(int _count) { m_enemySpawnDelay = _count; }
	void SetEnemySpawnVec(wstring _enemySpawnVec) { m_enemySpawnVec = _enemySpawnVec; }
	bool IsEnd() { return m_isEnd; }
	UNIT_TYPE GetUnitType(wchar_t enemyChar)
	{
		switch (enemyChar)
		{
		case L'P':
			return UNIT_TYPE::PAWN;
			break;
		case L'B':
			return UNIT_TYPE::BISHOP;
			break;
		case L'N':
			return UNIT_TYPE::KNIGHT;
			break;
		case L'R':
			return UNIT_TYPE::ROOK;
			break;
		case L'Q':
			return UNIT_TYPE::QUEEN;
			break;
		default:
			return UNIT_TYPE::END;
			break;
		}
	}
private:
	void SpawnEnemy();
private:
	wstring m_enemySpawnVec;
	bool m_isEnd;
	int m_enemySpawnIndex;
	int m_enemySpawnDelay;
	int m_currentSpawnDelay;
};

