#pragma once

class Enemy;
class EnemyManager
{
	DECLARE_SINGLE(EnemyManager);
private:
	Enemy* GetTypeEnemy(UNIT_TYPE _type);
public:
	Enemy* CreateEnemy(UNIT_TYPE _type);
};

