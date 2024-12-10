#pragma once

class Enemy;
class EnemyManager
{
	DECLARE_SINGLE(EnemyManager);
private:
	Enemy* GetTypeEnemy(UNIT_TYPE _type);
public:
	Enemy* CreateEnemy(UNIT_TYPE _type);
	int GetEnemyHealth(UNIT_TYPE _type) { return m_enemyHealth[(int)_type]; }
	int GetEnemyCost(UNIT_TYPE _type) { return m_enemyCost[(int)_type]; }
	int GetEnemyMoveCool(UNIT_TYPE _type) { return m_enemyMoveCool[(int)_type]; }
private:
	//							  P, N, B,  R,   Q
	vector<int> m_enemyHealth = { 3, 2, 8, 150, 350 };
	vector<int> m_enemyCost = { 20, 150, 100, 400, 800 };
	vector<int> m_enemyMoveCool = { 50, 10, 40, 100, 70 };
};

