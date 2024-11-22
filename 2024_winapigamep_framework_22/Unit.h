#pragma once
#include "Object.h"
#include "Enemy.h"

struct Stat
{
    float AttackSpeed;
    float AttackDamage;
};


class Unit :
    public Object
{
public:
    // Object을(를) 통해 상속됨|
    void Update() override;
    void Render(HDC _hdc) override;
public:
    virtual void Attack() abstract;
    virtual void RangeCheck() abstract;
public:
    Stat stat;
    vector<Enemy> enemyList;
    int cost;
    Vec2 m_pos;
    vector<Vec2> attackRange;
};

