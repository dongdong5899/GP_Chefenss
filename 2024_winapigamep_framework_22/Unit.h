#pragma once
#include "Object.h"
#include "Enemy.h"
#include "Road.h"
struct Stat
{
    float AttackSpeed;
    float AttackDamage;
};

class Unit :
    public Object
{
public:
    // Object��(��) ���� ��ӵ�
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
    Vec2 m_currentPos;
    vector<Road*> attackRange;
};

