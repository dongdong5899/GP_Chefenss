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
	Enemy* GetAssignedEnemy() { return m_assignedEnemy; }
	void SetAssignedEnemy(Enemy* _enemy) { m_assignedEnemy = _enemy; }
	void AssignEnemy(Enemy* _enemy);
	bool IsAssignedEnemy() { return m_assignedEnemy != nullptr; }
private:
	Enemy* m_assignedEnemy;
};