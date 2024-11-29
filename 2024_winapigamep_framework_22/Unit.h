#pragma once
#include "Object.h"
#include "Enemy.h"
#include "Road.h"
struct Stat
{
    float AttackCooldown;
    float AttackDamage;
};

class Unit :
    public Object
{
public:
    void Update() override;
    void Render(HDC _hdc) override;
public:
    virtual void RangeCheck() abstract;
    void Attack();
    bool AttackCoolTimeCheck(float fdt);
public:
    Stat stat;
    vector<Enemy> enemyList;
    int cost;
    Vec2 m_tilePos;
    vector<Road*> attackRange;
    float attackCooldown;
};

