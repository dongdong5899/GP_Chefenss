#pragma once
#include "Tile.h"
class Enemy;
class Road :
    public Tile
{
public:
	Road();
	~Road();
public:
	void Update() override;
	vector<Enemy*> GetAssignedEnemy() { return m_assignedEnemy; }
	void AddAssignedEnemy(Enemy* _enemy);
	void RemoveAssignedEnemy(Enemy* _enemy);
private:
	vector<Enemy*> m_assignedEnemy;
	int m_assignedEnemyCount;
};