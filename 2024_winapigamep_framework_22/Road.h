#pragma once
#include "Object.h"
class Enemy;
class Road :
    public Object
{
public:
	Road();
	~Road();
public:
	void Update() override;
	void Render(HDC _hdc) override;
	Enemy* GetAssignedEnemy() { return m_assignedEnemy; }
	void AssignEnemy(Enemy* _enemy) { m_assignedEnemy = _enemy; }
	bool IsAssignedEnemy() { return m_assignedEnemy != nullptr; }
private:
	Enemy* m_assignedEnemy;
};